### 解题思路
![image.png](https://pic.leetcode-cn.com/bd298f3a207622dad1bbfec783486c0e19551d74c762f3a9fa55c0d755de3590-image.png)
有点蠢。。但比较直接。。
从最大的数减起，能减掉就减掉，然后找表中对应字符串拼接上去
这不知道拷贝了多少次字符串，希望能研究出来更简单的办法
### 代码

```cpp
class Solution
{
public:
    string intToRoman(int num)
    {
        string rom[]{"I", "IV", "V",  "IX", "X", "XL", "L", "XC",  "C",  "CD", "D", "CM", "M"};
        int val[]{    1,   4,   5,    9,    10,  40,   50,   90,   100,  400,  500, 900, 1000};
        int size(13);
        //dismember num into sum of val
        string ret;
        for (int i = size - 1; i >= 0;)
        {
            int currentV(val[i]);
            if (currentV > num)
                i--;
            else
            {
                num -= currentV;
                ret += rom[i];
            }
        }
        return ret;
    }
};
```