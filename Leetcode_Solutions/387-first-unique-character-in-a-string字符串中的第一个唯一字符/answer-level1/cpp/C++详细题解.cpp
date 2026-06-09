### 思路
根据提示使用哈希映射
1. 遍历一遍字符串记录每个字母出现的次数
2. 遍历hashmap，找出第一个出现次数只有一次的字符
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hashmap;
        for(auto i : s){
            if(hashmap.count(i))    hashmap[i] += 1;
            else    hashmap[i] = 1;
        }
        for(int j = 0; s[j] != '\0'; ++ j)  if(hashmap[s[j]] == 1)  return j;
        return -1;
    }
};
```
