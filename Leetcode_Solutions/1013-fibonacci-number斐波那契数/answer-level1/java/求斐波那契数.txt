### 解题思路
首先分析斐波那契数特点：当n为1时，sum为1，
 n  = 1 2 3 4 5 6 7
sum = 1 1 2 3 5 8 13 //斐波那契数
因为斐波那契数的特点是前一个与后一个相加得到后一个数，所以就定义first与second让他俩相加
相加了几次可以通过推算可得计算第N个数时是相加了N-1次
之后将前一次相加时的second给这次相加的first，
将前一次相加的sum给这次相加的second
### 代码

```java
class Solution {
    public int fib(int N) {
        if(N <= 1){
            return N;
        }
        int first = 0;
        int second = 1;
        for(int i = 0; i < N - 1; i++){
            int sum = first + second;
            first = second;
            second = sum;
        }
        return second;
    }
}
```