### 解题思路
剪枝
1.从大到小枚举所有边
2.每条边内部的木棒长度规定从大到小//为了防止枚举到重复方案
3.如果当前木棒拼接失败，则跳过接下来所有长度相同的木棒
4.如果当前木棒拼接失败，且是当前边的第一个，则直接剪掉分支
5.如果当前木棒拼接失败，且是当前边的最后一个，则直接剪掉分支

### 代码

```cpp
class Solution {
public:
    
    vector<bool>st;
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for(auto u : nums) sum+=u;
        if(!sum || sum % 4) return false;
        sort(nums.rbegin(),nums.rend());
        st = vector<bool>(nums.size());
        return dfs(nums,0,0,sum / 4);
    }

    bool dfs(vector<int>&nums,int u , int cur, int length)
    {
        if(cur == length) u++, cur = 0;
        if(u == 4)return true;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!st[i] && cur + nums[i] <= length)
            {
                st[i] = true;
                if(dfs(nums,u , cur+nums[i],length))return true;
                st[i] = false;
                if(!cur)return false;//如果cur = 0 ,第一个失败了，直接剪掉
                if(cur + nums[i] == length) return false;
                while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;//当前失败，跳过相同大小木棒

            }
        }
        return false;
    }
};
```