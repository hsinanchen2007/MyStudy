### 解题思路
f(i, m)中计算下一轮的起始索引值nextIterStart: m % i；f(i - 1, m)的返回值为最终剩下的数字在i - 1个剩余数字中的索引值nextIterIndex(从0开始算)；
从而可以换算到剩余i个数字时，最终剩余数字的索引值：nextInterStart + nextIterIndex，有可能会超过i个数字，所以要取模i。递归终止条件是f(1,m) = 0，
也就是只有1个元素时，最终剩余的元素索引值时0.


### 代码

```c
int f(int n, int m)
{
    if (n == 1) {
        return 0;
    }
    int nextIterIndex = f(n - 1, m);
    int nextIterStart = m % n;
    return (nextIterStart + nextIterIndex) % n;
}

int lastRemaining(int n, int m) {
    return f(n, m);
}

```