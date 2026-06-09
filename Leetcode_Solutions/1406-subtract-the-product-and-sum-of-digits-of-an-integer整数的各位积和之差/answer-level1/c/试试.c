### 解题思路
此处撰写解题思路

### 代码

```c
int subtractProductAndSum(int n)
{
    int sum = 0;
    int  product = 1;
    while(n)
    {////n非0
        sum += (n%10);
        product *= (n%10);
        n /= 10;
    }
    return (product - sum);
}
```