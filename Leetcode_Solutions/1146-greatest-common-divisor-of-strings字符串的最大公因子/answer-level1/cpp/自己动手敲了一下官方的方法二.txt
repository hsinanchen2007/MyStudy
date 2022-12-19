### 解题思路
采用了官方的方法二的思路
![微信图片_20200312235323.png](https://pic.leetcode-cn.com/3ca95360f680d1ee76b0af1de81df70c84c62b6c3c6188f348a1e9ac4cce6bd3-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200312235323.png)

### 代码

```cpp
class Solution {
public:
    bool check(string t, string str)
    {
        int num = str.size() / t.size();
        string temp = "";
        for (int i = 0; i < num; i++)
        {
            temp += t;
        }
        return temp == str;
    }

    string gcdOfStrings(string str1, string str2)
    {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 > 0 && len2 > 0)
        {
            int num1 = len1, num2 = len2;
            if (num1 < num2)
            {
                num1 = num1 + num2;
                num2 = num1 - num2;
                num1 = num1 - num2;
            }
            int temp = 0;
            while (num2 != 0)
            {
                temp = num1 % num2;
                num1 = num2;
                num2 = temp;
            }
            string subStr = str1.substr(0, num1);
            if (check(subStr, str1) && check(subStr, str2))
            {
                return subStr;
            }
        }
        return "";
    }
};
```