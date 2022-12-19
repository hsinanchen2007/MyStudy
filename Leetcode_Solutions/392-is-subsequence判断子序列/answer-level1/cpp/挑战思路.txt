### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> memo[26];
    bool isSubsequence(string s, string t) {
        for(int i = 0;i < t.size();++i)
            memo[t[i] - 'a'].push_back(i);
        int u = -1;
        for(auto p : s){
            int l = 0, r = memo[p - 'a'].size() - 1;
            if(r < 0) return false;
            while(l < r){
                int mid = (l + r) >> 1;
                if(memo[p - 'a'][mid] > u) r = mid;
                else l = mid + 1;
            }
            if(memo[p - 'a'][l] <= u) return false;
            u = memo[p - 'a'][l];
        }
        return true;
    }
};
```