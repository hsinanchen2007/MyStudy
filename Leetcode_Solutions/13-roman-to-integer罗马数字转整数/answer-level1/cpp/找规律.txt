### 解题思路
此处撰写解题思路
此题的难度在于那几个特例，容易纠结于怎么判断左右。
其实不必判断左右，只需要找出在左面特例的个数即可。
例如，“MCMXCIV”中在V左面的I由1个，在C左面的X有1个，在M左面的C有一个。
先算出各个字母所代表数的总和为2216，然后减去2*（1 + 10 + 100）即可算出结果！
### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int flag1 = 0;
        int flag2 = 0;
        int flag3 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;
        int value = 0;
        for(int i = s.length() - 1;i >= 0;i--)
        {
            switch(s[i])
            {
                case 'I':
                    if(flag1) 
                    {
                        cnt1++;
                    }
                    value = 1;
                    break;
                case 'V':
                    flag1 = 1;
                    value = 5;
                    break;
                case 'X':
                    if(flag2) 
                    {
                        cnt2++;
                    }
                    flag1 = 1;
                    value = 10;
                    break;
                case 'L':
                    flag2 = 1;
                    value = 50;
                    break;
                case 'C':
                    if(flag3) 
                    {
                        cnt3++;
                    }
                    flag2 = 1;
                    value = 100;
                    break;
                case 'D':
                    flag3 = 1;
                    value = 500;
                    break;
                case 'M':
                    flag3 = 1;
                    value = 1000;
                    break;
            }
            sum += value;
        }
        sum -= 2 * ( cnt1 + 10 * cnt2 + 100 * cnt3); 
        return sum;
    }
};
```