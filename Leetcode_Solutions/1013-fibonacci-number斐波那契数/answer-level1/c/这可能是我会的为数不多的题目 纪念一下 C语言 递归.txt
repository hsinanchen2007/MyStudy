### 解题思路
递归调用自身 本来原理就是F(N) = F(N - 1) + F(N - 2) 很容易想到递归调用

### 代码

```c


int fib(int N){
    if(N==1)
    return 1;
    if(N==0)
    return 0;
    return fib(N-1)+fib(N-2);
}
```