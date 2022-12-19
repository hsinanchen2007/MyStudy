### 解题思路
注意 负数的位运算用补码

### 代码

```c
int numberOfSteps (int num)
{
    int count = 0;
    while (num > 0)
    {
        if (num & 1)
            num &= -2;
        else num >>= 1;
        count++;
    }
    return count;
}
```