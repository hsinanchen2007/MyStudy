### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    vector<bool> st;
    //u:当前枚举到第几条边； cur当前边的长度
    bool dfs(vector<int>& nums, int u, int cur, int length) {
        if (cur == length) {
            u++;
            cur = 0;
        }
        if(u == 4) {
            return true;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(!st[i] && cur + nums[i] <= length) {
                st[i] = true;
                if (dfs(nums, u, cur+nums[i],length)) {
                    return true;
                }
                st[i] = false;
                if (!cur) {
                    return false;
                }
                if(cur+nums[i]==length) {
                    return false;
                }
                while(i+1<nums.size() && nums[i] == nums[i+1]) 
                    i++;
            }

        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        st = vector<bool>(nums.size(), false);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        } 
        if (sum == 0|| sum%4) {
            return false;
        }
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return dfs(nums, 0, 0, sum/4);
    }
};
```