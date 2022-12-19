### 解题思路
首先火柴的长度总和要满足构成一个正方形的条件。
其次是剪枝：
1 从大到小枚举所有边，这是因为边越大对应的分支越少，总方案数是一定的，能够减掉的分支就越多。
2 每条边内部的木棒长度规定从大到小。
3 如果当前木棒拼接失败，跳过接下来所有长度相同的木棒。
4 如果当前木棒拼接失败，且是当前边的第一个，则直接减掉该分支。
5 如果当前木棒拼接失败，且是当前边的最后一个，则直接减掉当前分支。

### 代码

```cpp
class Solution {
public:
    vector<bool> st;//表示当前木棒有没有用过
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for(auto c:nums) sum += c;

        if(nums.size()<4 || sum%4) return false;
        st = vector<bool>(nums.size());
        sort(nums.rbegin(),nums.rend());//逆序
        return dfs(nums,0,0,sum/4);
    }

    bool dfs(vector<int> &nums,int u,int cur,int length)//u表示第几条边，cur表示当前边的长度，length表示边长
    {
        if(cur == length) u++,cur = 0;
        if(u == 4) return true;

        for(int i = 0;i<nums.size();i++)
        {
            if(cur + nums[i] <= length && !st[i])
            {
                st[i] = true;
                if(dfs(nums,u,cur+nums[i],length)) return true;
                st[i] = false;
                while(i+1<nums.size() && nums[i+1] == nums[i]) i++;
                if(!cur) return false;
                if(cur + nums[i] == length) return false;
            }
        }

        return false;
    }
};
```