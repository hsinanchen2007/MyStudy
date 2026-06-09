### 解题思路
直接将给定字符串裁剪，裁切后的字符串前后互换再连接。

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string s1,s2;
        s1 = s.substr(0,n);
        s2 = s.substr(n,s.size()-1);
        return s2+s1;
    }
};
```