### 解题思路
此处没必要撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n)
    {
        string ans = "";
        int len = s.length();
        ans += s.substr(n, len);
        ans += s.substr(0, n);
        return ans;
    }
};
```