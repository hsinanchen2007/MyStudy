### 解题思路
直接if……else……虽然代码不是很好看，但是执行效率还行
![image.png](https://pic.leetcode-cn.com/129b2e55beff6881c3171914b04741d896beafcf67cc4f71a15a201ea7ac7b4c-image.png)

也可以直接用vector<pair<int, string>>来存储字符和数字之间的关系，这样代码更好看
### 代码

```cpp
class Solution
{
public:
    string intToRoman(int num)
    {
        string str = "";
        string s1;
        int cnt;

        while (num != 0)
        {
            if (num >= 1000)
            {
                cnt = num / 1000;
                num %= 1000;
                s1 = "M";
            }
            else if (num >= 900)
            {
                cnt = num / 900;
                num %= 900;
                s1 = "CM";
            }
            else if (num >= 500)
            {
                cnt  = num / 500;
                num %= 500;
                s1 = "D";
            }
            else if (num >= 400)
            {
                cnt = num / 400;
                num %= 400;
                s1 = "CD";
            }
            else if (num >= 100)
            {
                cnt = num / 100;
                num %= 100;
                s1 = "C";
            }
            else if (num >= 90)
            {
                cnt = num / 90;
                num %= 90;
                s1 = "XC";
            }
            else if (num >= 50)
            {
                cnt = num / 50;
                num %= 50;
                s1 = "L";
            }
            else if (num >= 40)
            {
                cnt = num / 40;
                num %= 40;
                s1 = "XL";
            }
            else if (num >= 10)
            {
                cnt = num / 10;
                num %= 10;
                s1 = "X";
            }
            else if (num >= 9)
            {
                cnt = num / 9;
                num %= 9;
                s1 = "IX";
            }
            else if (num >= 5)
            {
                cnt = num / 5;
                num %= 5;
                s1 = "V";
            }
            else if (num >= 4)
            {
                cnt = num / 4;
                num %= 4;
                s1 = "IV";
            }
            else if (num >= 1)
            {
                cnt = num / 1;
                num %= 1;
                s1 = "I";
            }

            while (cnt != 0)
            {
                str += s1;
                cnt--;
            }
        }

        return str;
    }
};
```