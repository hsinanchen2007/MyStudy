### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isFlipedString(string s1, string s2)
    {
        if(s1.size() != s2.size()) return false;
        s1 = s1 + s1;//若s2是s1翻转得到 则对于s1拼接之后的string中 必然含有s2
        if(s1.find(s2) != -1) return true;
        return false;
    }
};


```