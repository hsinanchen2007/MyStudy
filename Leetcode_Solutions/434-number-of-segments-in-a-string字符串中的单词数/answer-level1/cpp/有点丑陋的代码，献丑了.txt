### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countSegments(string s)
    {
        int cnt = 0;
        bool flag = 1;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            while (s[i] == ' ')
            {
                i++, flag = 1;
                if (i >= len) return cnt;
            }
            if (flag) cnt++, flag = 0;
        }
        return cnt;
    }
};
```