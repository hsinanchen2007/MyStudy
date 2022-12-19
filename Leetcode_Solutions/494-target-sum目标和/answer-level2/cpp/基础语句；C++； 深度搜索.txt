本题使用DFS来实现，通过计数器`counter`来记录深度，不断迭代直到遍历完数组内的全部数据。
记下符合目标的支路。

```
class Solution {
public:
    void DFS(vector<int>& nums, int S, int& count, int counter, int sum)
    {
        if(counter == nums.size())
        {
            if(sum == S)
                ++ count;
            return;
        }
        //counter = counter + 1;
        DFS(nums, S, count, counter + 1, sum + nums[counter]);
        DFS(nums, S, count, counter + 1, sum -  nums[counter]);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        int sum = 0;
        DFS(nums, S, count, 0, sum);
        return count;
    }
};
```