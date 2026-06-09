### 解题思路
如果两个字符串一样，那么就不存在一个特殊序列；
而如果不一样，那二者中较长的字符串一定是在另一个字符串中不存在的“特殊序列”。

### 代码

```cpp
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a==b?-1:max(a.size(),b.size());
    }
};
```