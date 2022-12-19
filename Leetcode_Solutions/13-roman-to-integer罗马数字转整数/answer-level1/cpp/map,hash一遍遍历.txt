### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        map<char, int> m = { {'I',1} ,{'V', 5} ,{'X', 10},{'L', 50} ,{'C', 100} ,{'D', 500} ,{'M', 1000} };
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] >= m[s[i + 1]])
            {
                num = m[s[i]]+num;
            }
            else
            {
                num = m[s[i+1]] - m[s[i]]+ num;
                i++;
            }
        }
        return num;
    }
};
```