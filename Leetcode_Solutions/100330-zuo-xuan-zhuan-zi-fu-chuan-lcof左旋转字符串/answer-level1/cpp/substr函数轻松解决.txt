### 解题思路
还有比我代码短的吗？？？

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n,s.size()-n)+s.substr(0,n);
    }
};
```