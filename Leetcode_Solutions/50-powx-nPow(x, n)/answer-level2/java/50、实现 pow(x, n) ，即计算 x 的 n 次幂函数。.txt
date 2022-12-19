### 解题思路
1、考虑n<0时，将其转换为正数时，可能会发生溢出，因此，用long类型接收转换后的幂次方，同时底数变为倒数；
2、类型转换后，如果再次调用该方法，则发生形参类型不兼容，因此，可以再定义一个新的方法实现幂次方的计算；
3、递归弹栈的过程，遇到return以后，递归调用的方法结束，出栈。

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        //long类型接收负数次方
        long N = n;
        if(n < 0){
            N = -n;
            x = 1 / x;
        }
        return fastPow(x, N);
    }
    //转换形参类型
    public double fastPow(double x, long n){
        if(n == 0){
            return 1;
        }
        double res = fastPow(x, n / 2);
        //每一次递归后都会先执行到return，再向下递归。
        if(n % 2 == 0){
            return res * res;
        }else{
            return res * res * x;
        } 
    }
}
```