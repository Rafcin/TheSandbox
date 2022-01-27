#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

std::vector<int> sumEvenAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {

    /**
     * @params nums
     * Vector of values
     *
     * @param queries
     * Vector of vector containing mutations - {int value, int target index}
     */

    std::vector<int> ans;
    //I added the check, when testing I realized oh shit that could be an issue.
    if(nums.size() == queries.size()){
        //Ternary op using custom binary. It's cleaner to do this.
        //for(auto value : nums){if(value % 2 == 0){}}

        //God this is so fucking cleaaaaan
        auto accumulateSum = std::accumulate(std::begin(nums), std::end(nums), 0, [](int x, int y){ return y % 2 == 0 ? x+y : x; });

        //Sanity check
        //std::cout << accumulateSum << std::endl;

        //Query for each.
        for(auto query : queries){
            //Loop goes through each query, for ref to access the query its
            /*
             * query[0] - value
             * query[1] - target
             */
            //Def value and target
            //At the start value is set to the query value and target is set to query target index.
            auto value = query[0], target = query[1];
            //If the nums[target] in this case on pass 1 value of 1 on the original array is even then summarize value should be sum - target value.
            if (nums[target] % 2 == 0) accumulateSum -=nums[target];
            nums[target] += value;
            //Similar to condition above
            if(nums[target] % 2 == 0) accumulateSum += nums[target];
            //Put the value into the answer vec
            ans.emplace_back(accumulateSum);
        }
    }else{
        std::cout << "The size of queries and nums does not match. Exit" << std::endl;
    }
    return ans;
}

int main() {
    std::vector<int> nums = {1,2,3,4,9,6};
    std::vector<std::vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
    for(auto x : sumEvenAfterQueries(nums,queries)) {
        std::cout << x << std::endl;
    }
    return 0;
}
