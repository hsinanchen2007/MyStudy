按行依次读

按一个小勾为一个单元

规律：
![图片.png](https://pic.leetcode-cn.com/83c533f9401309d6b7c8786fb224acdfbf33eeb135f1827a4553190c451b2880-%E5%9B%BE%E7%89%87.png)

```c++
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int n = s.size();
        int steps = 2 * (numRows - 1);
        string res;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < n; j += steps)
            {
                res += s[j + i];
                if (i != 0 && i != numRows - 1 && j + steps - i < n)
                    res += s[j + steps - i];
            }
        }
        return res;
    }
};
```

