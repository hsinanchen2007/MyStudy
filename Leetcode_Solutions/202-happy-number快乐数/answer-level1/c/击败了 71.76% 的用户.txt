### 解题思路

### 代码

```c
int mul(n)
{
    int sum = 0;
    int x;
    while (n != 0)
    {
        x = n % 10;
        sum += (x * x);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n){
    int slow = n, fast = n;
    do 
    {
        slow = mul(slow);
        fast = mul(fast);
        fast = mul(fast);
    } while(slow != fast);
    return slow == 1;
}
```