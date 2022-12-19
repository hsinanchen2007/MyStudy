### 解题思路
此处撰写解题思路
需要一个标识提前判断正负，还有就是每次循环计算数值的时候要判断是否越界，如果想计算完之后再判断越界那么有几种case是过不了的

### 代码

```cpp
class Solution {
public:
    int strToInt(string str) {
        long res = 0;
        int iBeg = 0;
        int iiBeg = 0;
        bool isNeg = false;
        bool isC = false;
        for (;iBeg < str.size(); iBeg++)
        {
            if (str[iBeg] == '+' || str[iBeg] == '-' || (str[iBeg] >= '0' && str[iBeg] <= '9'))
            {
                if (str[iBeg] == '+')
                {
                    isNeg = false;
                    isC = true;
                }
                else if (str[iBeg] == '-')
                {
                    isNeg = true;
                    isC = true;
                }
                else
                {
                    isNeg = false;
                }
                if (isC) iiBeg = iBeg+1;
                else iiBeg = iBeg;
                for (;iiBeg < str.size() && (str[iiBeg] >= '0' && str[iiBeg] <= '9'); iiBeg++)
                {
                    res = res*10 + (str[iiBeg] - '0');
                    if (res >= INT_MAX && isNeg == false) return INT_MAX;
                    else if (-res < INT_MIN && isNeg == true) return INT_MIN;
                }
                return  isNeg == true? -res:res;
            }
            else if (str[iBeg] == ' ') continue;
            else return res;
        }
        return res;
    }
};
```