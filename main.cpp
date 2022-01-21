#include <iostream>
#include <vector>
#include <climits>

int maxSubArray(std::vector<int>& nums) {
    //How is this only 51.74% faster for online subs.. wtf
    /**
     * Notes
     * - The current pass used 68mb in space, that's a bit shit. 01/20/2022 14:21 Accepted 211 ms 67.8 MB cpp
     * - 01/20/2022 16:28	Accepted	122 ms	67.8 MB	cpp
     */
    //Let's get the size of the array first.
    //int size = nums.size();
    https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-170
    //-2147483647, perfection. Honestly I could just set it but look at it, it's so clean and simple. Now max will work against all negative sets + 0.
    int max = INT_MIN, current = 0;

    for(std::size_t i = 0; i < nums.size(); i++){
        current = std::max(nums[i],current + nums[i]);
        //The max sum is set by comparing the current and the previous max.
        max = std::max(max, current);
    }
    //Return the max.
    return max;
}

int main() {

    std::vector<int> sample = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::vector<int> edgeA = {-1, -6, -7, -3};
    std::vector<int> edgeB = {0};
    std::cout << maxSubArray(sample) << std::endl;
    std::cout << maxSubArray(edgeA) << std::endl;
    std::cout << maxSubArray(edgeB) << std::endl;
    return 0;
}
