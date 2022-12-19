### 解题思路
首先简化问题，只处理s的长度大于等于t的情况，循环到两者出现不同字符时，根据长度选择删除字符或者替换字符就可以了。

### 代码

```cpp
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ss = s.size(), st = t.size();
        if (st > ss) return isOneEditDistance(t, s);
        int delta = ss - st;
        if (delta > 1) return false;
        if (s == t) return false;
        for (int i = 0; i < st; i++) {
            if (s[i] != t[i]) {
                return delta ? s.substr(i+1)==t.substr(i) : s.substr(i+1)==t.substr(i+1);
            }
        }
        return true;
    }
};
```
执行用时 :4 ms, 在所有 C++ 提交中击败了83.83%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了100.00%的用户