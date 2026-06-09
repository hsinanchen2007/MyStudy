### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.length() - 1) + s.substr(0,n);
    }
};
```