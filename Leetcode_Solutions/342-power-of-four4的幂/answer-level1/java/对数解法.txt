首先可以根据题目得出一个等式：4 ^ x = num 。如果num为4的幂，则x为非负整数即可。

对于该等式可以两边取对数，直接利用Math中的计算对数的函数得出未知数x的表达式：

    4 ^ x = num <=> log(4 ^ x) = log(num) <=> x * log 4 = log num <=> x = log(num) / log 4

x定义为double类型，只要 x与(int)x值相等 ，num即为4的幂

```
class Solution {
    public boolean isPowerOfFour(int num) {
        double check = Math.log(num) / Math.log(4);
        if(check == (int)check)
            return true;
        return false;
    }
}
```
