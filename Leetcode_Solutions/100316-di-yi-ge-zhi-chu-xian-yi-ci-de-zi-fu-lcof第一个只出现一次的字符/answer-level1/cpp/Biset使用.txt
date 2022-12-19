### 解题思路
Bitset存储信息，减少内存占用。

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        
        bitset<128> bs1, bs2;
        for(int i=0; i<s.size(); i++) {
            if (!bs1[s[i]] && !bs2[s[i]])
                bs1[s[i]] = 1;
            else if (bs1[s[i]] && !bs2[s[i]])
                bs2[s[i]] = 1;
        }
        for(auto item: s){
            if (bs1[item] && !bs2[item])
                return item;
        }
        return ' ';
    }
};
```