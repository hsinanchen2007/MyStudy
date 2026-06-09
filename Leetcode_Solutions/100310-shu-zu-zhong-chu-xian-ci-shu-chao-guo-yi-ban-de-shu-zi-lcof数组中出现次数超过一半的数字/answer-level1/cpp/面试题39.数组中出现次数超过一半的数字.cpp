### 解题思路
- 核心要点：常规做法是对数组排序，取中间位置数即为所求。此题可使用摩尔投票法，降低时间复杂度到O(n)，空间复杂度到O(1)。
- 算法：初始假设nums[0]为众数，从头遍历，遇到众数+1票，遇到非众数-1票，票数为0时设置下一元素为众数。遍历结束后即得正确结果。
- 执行用时：44 ms, 在所有 C++ 提交中击败了12.22%的用户
- 内存消耗：18.8 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=nums[0];
        int votes=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x)votes++;
            else votes--;
            if(votes==0)x=nums[i+1];
        }
        return x;
    }
};
```