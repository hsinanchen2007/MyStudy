### 解题思路
因为内置的排序算法在时间复杂度上实际上是O(logn)的满足要求
因此我们可以通过排序将其 转化为一个很简单的问题
### 代码

```cpp
class Solution {
public:
    //排序算法可以在log2N的时间复杂度之内排序
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        //排序
        sort(nums.begin(),nums.end());

        //统计当前值
        size_t current = 1;
        size_t Max = 1;//最大值

        for(int i = 1; i< nums.size();i++)
        {
            //递增
            if(nums[i] == nums[i-1]+1)
            {
                current++;
                if(current>Max)
                    Max = current;
            }
            //递增清0
            else if(nums[i] != nums[i-1])
            {
                current = 1;
            }
            //相等啥不干
        }

        return Max;
    }
};
```