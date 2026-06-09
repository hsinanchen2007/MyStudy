### 解题思路
首先left和right限定了范围，程序中不再需要对其进行判断。
由题意可知需要对数字进行拆解，以t来储存
t为0时，进行下一数字的判断
  非0时，判断当前值temp是否可整除t
     不能则进行下一数字的判断
     能则去除当前值temp的个位数，继续判断，直至满足当前值temp为0，将数字i存入result中。

### 代码

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        int temp, t, i;
        for ( i = left; i <= right; i++)
        {
            temp = i;
            while (temp)
            {
                t = temp % 10;
                if (t == 0) {temp = 0;}
                else if ( (i % t) == 0 )
                {
                    temp /= 10;
                    if (temp == 0)
                    {
                        result.push_back(i);
                    }
                }
                else
                {
                    temp = 0;
                }
            }
        }
        return result;
    }
};
```