### 解题思路
此处撰写解题思路

### 代码

```c
int fib(int n)
{
    if(n < 2)
        return n;
    int q1 = 0;
    int q2 = 1;
    int sum = 0;
    while(n > 1)    //因为 0 1 都是固定值，所以循环从2 开始
    {
        sum = q1 + q2;   //用迭代
        q1 = q2;
        q2 = sum;
        q2 %= 1000000007;    //预防整形溢出
        --n;
    }
    return q2;   

}
```