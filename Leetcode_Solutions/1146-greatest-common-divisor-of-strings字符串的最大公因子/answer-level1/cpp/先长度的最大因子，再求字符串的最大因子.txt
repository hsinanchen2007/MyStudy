### 解题思路

先长度的最大因子，再求字符串的最大因子

### 代码

```cpp
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        string ans = "";
        int str1_len = str1.length();
        int str2_len = str2.length();

        for (int j = 1; j <= min(str1_len, str2_len); ++j)
        {
            if (str1_len % j == 0 && str2_len % j == 0)
            {
                string tmp = str1.substr(0, j);
                bool flag1 = true;
                bool flag2 = true;
                for (int i = 0; i < str1_len / j; ++i)
                {
                    string str1_tmp = str1.substr(i * j, j);
                    if (str1_tmp != tmp)
                    {
                        flag1 = false;
                        break;
                    }
                }
                for (int i = 0; i < str2_len / j; ++i)
                {
                    string str2_tmp = str2.substr(i * j, j);
                    if (str2_tmp != tmp)
                    {
                        flag2 = false;
                        break;
                    }
                }

                if (flag1 && flag2)
                {
                    ans = tmp;
                }
            }
        }
        return ans;
    }
};
```