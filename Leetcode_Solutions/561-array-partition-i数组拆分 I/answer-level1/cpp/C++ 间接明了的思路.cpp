### 解题思路
排序，然后选每一对的第一个元素
比如 1 4 3 2 排序后就是 1 2 3 4 选1和3就是最小的了

### 代码

```cpp
class Solution 
{
public:
    int arrayPairSum(vector<int>& nums) 
    {
        int minr = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0, N = nums.size(); i < N; i += 2)
        {
            minr  += nums[i];
        }
        return minr;
    }
};
```