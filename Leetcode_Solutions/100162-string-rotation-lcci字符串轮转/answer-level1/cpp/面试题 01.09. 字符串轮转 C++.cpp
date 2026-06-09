### 解题思路

先判断长度是否相同，不同则直接返回

再将s1重复拼接，判断s2是否为其子串即可  如："erbottlewat" 是 "waterbottlewaterbottle" 的子串，且长度正好是其一半

本来还以为题目会提供isSubstring函数，实际并没有，所以直接调用了string::find


### 代码

```cpp
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        
        return (s1 + s1).find(s2) != string::npos;
    }
};
```