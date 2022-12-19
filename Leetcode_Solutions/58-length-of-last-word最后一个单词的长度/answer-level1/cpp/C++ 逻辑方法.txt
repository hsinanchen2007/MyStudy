### 解题思路
很简单

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int cnt  = 0;
        int len = s.length();
        bool flag = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] != ' ' && flag == 1) cnt = 1, flag = 0;
            else if (s[i] != ' ') cnt++;
            else flag = 1;
        }
        return cnt;
    }
};
```