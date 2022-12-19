### 解题思路
cpp精简代码题解

### 代码

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash_s(26, 0);
        for(auto x:s){
            hash_s[x-'a']++;
        }
        for(auto x:t){
            hash_s[x - 'a']--;
            if(hash_s[x-'a'] == -1) return x;
        }
        return ' ';
    }
};
```