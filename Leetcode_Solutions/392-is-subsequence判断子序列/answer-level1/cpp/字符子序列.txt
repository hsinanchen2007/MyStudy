### 解题思路
/*
        从前往后一次遍历，双指针完成
        执行用时 :44 ms, 在所有 C++ 提交中击败了94.20%的用户
        内存消耗 :16.6 MB, 在所有 C++ 提交中击败了100.00%的用户
        */

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (s[i] && t[j])
        {
            if (s[i] == t[j])
                i++;
            j++;
        }

        if (i == s.length())
            return true;
        else
            return false;
    }
};
```