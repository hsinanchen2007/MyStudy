```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        map<int, int> map;
        for(auto c: s) map[c] += 1;
        for(int i=0; i<s.size(); ++i)
            if(map[s[i]] == 1) return i;
        return -1;
    }
};
```
- 利用哈希表对所有字符计数
- 遍历字符串返回第一个唯一字符索引