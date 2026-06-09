### 解题思路
递归

### 代码

```c
int fib(int N){
    if(N==0)return 0;
    if(N==1)return 1;
    return fib(N-1)+fib(N-2);
}
```