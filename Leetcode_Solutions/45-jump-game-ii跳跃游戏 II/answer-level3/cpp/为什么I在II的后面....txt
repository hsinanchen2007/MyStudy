执行用时 :4 ms, 在所有 C++ 提交中击败了99.79%的用户
内存消耗 :10.1 MB, 在所有 C++ 提交中击败了78.69%的用户

因为每一步可以走的长度没有限制，所以如果在第k步可以到达x，则也可以到达[0,x)的任何一个位置。
所以不用动规了，直接贪心解决。
在a[0]处获得第一步能到的最大下标，遍历到这个位置并计算从其中每个位置能走到的范围，其中最大值就是第二步能到的最大位置。
如此循环直到达到终点，时间复杂度O(n)。
注意边界处理。


```cpp []
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 1;
        if(nums.size() < 2)
            return 0;
        int thisstepmax = nums[0];
        if(nums[0] >= nums.size() - 1)
            return 1;
        int nextstepmax = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(i + nums[i] >= nums.size() - 1)
                return step + 1;
            if(i + nums[i] > nextstepmax)
                nextstepmax = i + nums[i];
            if(i == thisstepmax)
            {
                ++step;
                thisstepmax = nextstepmax;
            }
        }
        return 0;
    }
};
```

