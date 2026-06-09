### 解题思路
此处撰写解题思路

### 代码

```c
int fib(int N)
{
    int a = 0, b = 1, sum = 0;
    if(N == 0)
        return 0;
    else if(N == 1)
        return 1;
    while(N > 1)      //迭代
    {
        sum = a +b;
        a = b;
        b = sum;
        --N;
    }
  return sum;
}
```