### 解题思路
如果输入数字小于10，说明只有一位数字，则乘积和和积相同，差为零；
如果输入数字为10的倍数，说明数字中有0存在，则乘积一定为0，结果为和积的相反数。

正常情况下，常规分离计算即可。

### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        if (n < 10) return 0;
        int sum_add = 0, sum_mul = 1;
        if (n % 10 == 0) sum_mul = 0;
        while (n)
        {
            int c = n % 10;
            sum_add += c;
            sum_mul *= c;
        
            n /= 10;
        } 

        return sum_mul - sum_add;
    }
};
```