### 解题思路
string::find()方法
例如：`a.find(b)`在a中查找b。如果找到就返回子串首地址，找不到返回string::npos。
调库虽然简单，但是面试不允许调库就gg，还是得想想O(n)的解法

### 代码

```cpp
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.empty() && s2.empty()) return true;
        if(s1.size()!=s2.size()) return false;

        string ms=s2+s2;
        if(ms.find(s1)==string::npos)
            return false;
        else
            return true;
    }
};
```