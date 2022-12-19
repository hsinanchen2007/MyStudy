### 解题思路
这里还是用不断减去的记录， 需要注意两点：
1） 需要清楚有一种情况会超出int , 所以需要特殊处理；
2） 如果一个一个减下去，是会超时的，因此需要做处理；
具体方法：
只要 new_dividend>=new_divisor,（以10 3举例） 那么就去找， 进入循环后，进入第二个循环
3<<1 为 6 ，则应该看是否10-6ok，如果ok， 6是2个3， 那么result<<1; 再看6<<1为12不行，则跳出里面循环；
result此时为2， 剩下的被除数为 10-6=4; 再次进入循环；此时 3<<1 < 4不符合，所有不能进入第二个循环，只能result加1；再比较 则会跳出循环 


### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long result = 0;
        long  new_dividend = labs(dividend);
        long new_divisor = labs(divisor);
        while (new_dividend >= new_divisor) {
            long tmp_div = new_divisor;
            long tmp_result = 1;
            while (tmp_div << 1 < new_dividend) {
                tmp_div = tmp_div << 1;
                tmp_result = tmp_result << 1;
            }
            result += tmp_result;
            new_dividend -= tmp_div;
        }

        if (dividend < 0 && divisor <0 || dividend > 0 && divisor >0) {
            return result;
        } else {
            return -result;
        }
    }
};
```