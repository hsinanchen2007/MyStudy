### 解题思路
最简单的递归，贴上来是因为空间复杂度低（击败了91.96%）

### 代码

```c
int fib(int N){
    if(N==0) return 0;
    if(N==1) return 1;
    return fib(N-1)+fib(N-2);
}
```