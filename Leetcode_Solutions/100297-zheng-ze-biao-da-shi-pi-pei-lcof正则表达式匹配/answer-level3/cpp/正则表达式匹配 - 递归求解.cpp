### 解题思路
1. 特判，同时也是递归出口，如果`p`是空串，返回`s`是否为空串。如果`p`不为空，保证一定存在`p[1]`（可能是字符串结尾`\0`）
2. 假如`p[1] == *` 的话，可以尝试两种情况：情况一是递归比较`s`和`p.substr(2)`；情况二是当`s[0]`可以匹配`p[0]`时, 尝试递归比较`s.substr(1)`和`p`，这里没有必要比较`s.substr(1)` 和 `p.substr(2)`，因为这种情况已经包含在递归比较`s.substr(1)`和`p`当中了
3. 假如`p[1] != *`,如果`p[0]`不匹配`s[0]`，返回`false`，否则递归判断`s.substr(1)`和`p.substr(1)`

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p[1] == '*'){
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.')) && isMatch(s.substr(1), p);
        }
        else{
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && (isMatch(s.substr(1), p.substr(1)));
        }
    }
};
```