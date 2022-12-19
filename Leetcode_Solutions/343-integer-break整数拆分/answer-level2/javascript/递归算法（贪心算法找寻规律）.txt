**解题思路： 根据拆解整数7,8,9,10科研得出如下规律：**
7： 3 * 2 * 2
8： 3 * 3 * 2
9：  3 * 3 * 3
10： 3 * 3 * 2 * 2
即要将这个整数尽可能拆成多的3与2的合集，但如果一个数拆除2或3之后剩余的数只能为1时，则不需要查分它。因为此时拆分后的乘积反而更小了。
**得到递归的逻辑：** 
                当数字大于等于5时，先拆分出一个3，然后继续拆分剩余数值。
                当数字大于等于4时，先拆分出一个2，然后继续拆分属于数值。
注意先处理输入数字为2和3的情况。
```
var integerBreak = function(n) {
    function getRes(num) {
        if (num >=5) {
            return 3*getRes(num-3);
        } else if (num>=4) {
            return 2*getRes(num-2);
        } else {
            return num;
        }
    }
    if (n === 2) {return 1;}
    else if (n === 3) {return 2;}
    else {
        return getRes(n);
    }
};
```
