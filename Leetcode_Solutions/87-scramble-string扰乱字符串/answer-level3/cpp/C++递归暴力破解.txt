### 解题思路
C++暴力破解  
循环切割字符串，从长度为1开始，长度为s1.size()-1时停止，每次对比 （s1的左端和s2的左端 && s1的右端和s2的右端）|| （s1的左端和s2的右端 && s1的右端和s2的左端） 是否为扰乱字符串。  
注意每次先判断s1 s2的排序结果是否一致，不一致直接返回 false

12 ms	10.4 MB

### 代码

```cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if(t1 != t2) return false;
        if(s1.size() == 1 && s1 != s2) return false;
        for(int i = 1; i < s1.size() ; i++){
            if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
            || (isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) && isScramble(s1.substr(i), s2.substr(0,s2.size() - i))))
            return true;
        }
        return false;
    }
};
```