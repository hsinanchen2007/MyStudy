### 解题思路
两个字符串需要相互映射 实现完全对应的替换

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a[300]={0};
        int b[300]={0};
        for (int i = 0; i < s.size(); i++)
        {
            if (a[s[i]]&&a[s[i]]!=t[i])return false;
            if (b[t[i]]&&b[t[i]]!=s[i])return false;
            if (!a[s[i]])a[s[i]] = t[i];
            if (!b[t[i]])b[t[i]] = s[i];
        }
        return true;
    }
};
```