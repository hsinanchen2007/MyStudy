
### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.empty()) return true;

        unordered_map<char,int> help;//用于记录每个字母出现的次数
        int odd=0;//用于记录出现奇数次的字母的个数

        for(char c:s)
            help[c]++;
        for(auto h:help)
            if(h.second%2==1) odd++;

        return odd<2;//如果出现奇数次的字母多于1个，那么这些字母无法构成一个回文串
    }   
};
```