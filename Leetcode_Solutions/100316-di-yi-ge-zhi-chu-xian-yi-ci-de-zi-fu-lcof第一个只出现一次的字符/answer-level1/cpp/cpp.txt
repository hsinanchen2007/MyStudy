### 解题思路
构造hash数组，遍历两次即可

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        if(s.length() == 0) return ' ';
        vector<int> hash_S(26, 0);
        for(auto x : s){
            hash_S[x - 'a']++;
        }
        for(auto x:s){
            if(hash_S[x - 'a'] == 1) return x;
        }
        return ' ';
    }
};
```