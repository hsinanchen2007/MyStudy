### 解题思路
双指针。
设置返回值ret默认为false，分别取最小的数（0）和最大的数，最大的数可以直接使用sqrt()函数求目标数的平方根并向下取整，小数的平方与大数的平方求和，若大于目标值，大数减1，继续循环；若小于目标值，小数加1，继续循环；直到与目标值相等（置ret为true）或者小数不再小于大数，跳出循环。返回结果

### 代码

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        bool ret = false;
        long small = 0;
        long big = int(sqrt(c));
        while (small <= big)
        {
            if (big * big > c || small * small + big * big > c)
            {
                big--;
                continue;
            }
            else if (small * small + big * big < c)
            {
                small++;
                continue;
            }
            else
            {
                ret = true;
                break;
            }
        }
        return ret;
    }
};
```