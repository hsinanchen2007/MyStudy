### 解题思路

![image.png](https://pic.leetcode-cn.com/dcb1d633d32cc4c1e7c794ccc3b5d5152778663a4d1e5987a6c50d1552f8060d-image.png)

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2)
    {
        if (s1.length() != s2.length()) return 0;
        unordered_map<char, int> love[2];
        for (int i = 0; i < s1.length(); i++)
        {
            if (love[0].count(s1[i]) == 0) love[0][s1[i]] = 1;
            else love[0][s1[i]]++;
            if (love[1].count(s2[i]) == 0) love[1][s2[i]] = 1;
            else love[1][s2[i]]++;
        }
        for (int i = 0; i < s1.length(); i++)
        {
            if (!love[0].count(s1[i]) || !love[1].count(s1[i]))
                return 0;
            else if (love[0].at(s1[i]) != love[1].at(s1[i]))
                return 0;
        }
        for (int i = 0; i < s2.length(); i++)
        {
            if (!love[0].count(s2[i]) || !love[1].count(s2[i]))
                return 0;
            else if (love[0].at(s2[i]) != love[1].at(s2[i]))
                return 0;
        }
        return 1;
    }
};
```