### 解题思路
记录出现数字的次数

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        map<int,int> m;
        vector<vector<int>> ans;
        for(int n:nums){
            if(m.find(target-n)==m.end()||!m[target-n])m[n]++;
            else {
                ans.push_back({target-n,n});
                m[target-n]--;
            }
        }
        return ans;
    }
};
```