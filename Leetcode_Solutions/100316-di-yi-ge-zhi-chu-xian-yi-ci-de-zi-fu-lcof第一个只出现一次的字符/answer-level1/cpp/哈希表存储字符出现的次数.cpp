### 解题思路
使用哈希表存储字符出现的次数

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        unordered_map<char,int>::iterator it;
        for(auto c:s){
            if(mp[c]==1) return c;
        }
        return ' ';
    }
};
```