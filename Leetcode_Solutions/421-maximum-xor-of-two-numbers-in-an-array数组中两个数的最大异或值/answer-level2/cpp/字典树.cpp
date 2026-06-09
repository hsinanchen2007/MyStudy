### 解题思路
字典树，有点慢

### 代码

```cpp
class Solution {
public:
    int idx = 0;
    int findMaximumXOR(vector<int>& nums) {
        vector<vector<int> > son(nums.size() * 31, vector<int>(2, 0));
        for(int i = 0;i < nums.size();++i)insert(son, nums[i]);
        int ans = 0;
        for(int i = 0;i < nums.size();++i){
            int p = 0, k = 30, sum = 0;
            while(k >= 0){
                int t = nums[i] >> k & 1;
                if(son[p][!t]) {
                    p = son[p][!t];
                    sum += 1 << k;
                }
                else p = son[p][t];
                --k;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
    void insert(vector<vector<int>>& son, int x){
        int p = 0, k = 30;
        while(k >= 0){
            int t = x >> k & 1;
            if(!son[p][t]) son[p][t] = ++idx;
            p = son[p][t];
            --k;
        }
    }
};
```