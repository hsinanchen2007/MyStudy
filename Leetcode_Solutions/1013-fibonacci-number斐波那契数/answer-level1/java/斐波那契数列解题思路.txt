### 解题思路
此处撰写解题思路
求第 n 个斐波那契数（fibonacci number）
0 1 1 2 3 5 8 13 ...
如果 N <= 1 ;那么直接返回N即可；
如果N > 1;
我们定义第1个数first = 0，定义第2个数second = 1;
然后进行for 循环，定义变量m, m 就等于第一个数加上第2个数，
然后进行下一次计算时，第2个数的值作为第一个数的值，即 first = second;
下一个第2个数就是m,即second = m; 
所以第N个数的值为second;即return second;

### 代码

```java
class Solution {
    public int fib(int N) {
        if (N <= 1) return N;
        int first = 0;
        int second = 1;
        for (int i = 1; i < N; i++) {
            int m;
            m = first + second;
            first = second;
            second = m; 
        }
        return second;
    }
}
```