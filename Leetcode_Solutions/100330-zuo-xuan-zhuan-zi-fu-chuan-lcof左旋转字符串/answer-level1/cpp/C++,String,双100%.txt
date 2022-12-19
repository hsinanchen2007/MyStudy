### 解题思路
使用C++中String字符串函数，str.substr(pos, n)提取从pos位置开始的n个字符，str.earse(pos, n)删除从pos位置开始的n个字符，然后拼接即可。

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string tmp = s.substr(0, n);
        string ans = s.erase(0, n);
        ans += tmp;
        return ans;
    }
};
```