### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int fib(int N) {
        if(N<=1) return N;

        int first =0;
        int second = 1;
        for(int i = 0; i<N-1; i++){
            int sum = first + second;
            first = second;
            second = sum;
        }
        return second;
    }
}
```


实际上开发很少会用到递归，分为两部分，当N<=1时，和其他时候。主要是考虑N>1时候的情形。当f(2) = f(1) + f(0); f(3) = f(2) + f(1);  f(4) = (f3) + f(2); 设置了first,sceond实际为f(0) f(1). 当N等于3的时候，要进行两次循环那个first为f(1),second为f(2);所以first = second， second = sum; 