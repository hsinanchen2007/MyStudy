**1.递归**
个位数中只有1和7是快乐数，其他都不是，这是递归终止条件。
```c
bool isHappy(int n){
    if(n == 1 || n ==7)
        return 1;
    if(n < 10)
        return 0;
    int sum = 0;
    do{
        sum += (n % 10) * (n % 10);
        n /= 10;
    }while(n != 0);
    return isHappy(sum);
}
```
**2.快慢法**
```
int bitSum(int n)
{
    int ans = 0;
    do{
        ans += (n % 10) * (n % 10);
        n /= 10;
    }while(n != 0);
    return ans;
}

bool isHappy(int n)
{
    int slow = n, fast = n;
    do{
        slow = bitSum(slow);
        fast = bitSum(fast);
        fast = bitSum(fast);
    }while(slow != fast);
    return slow == 1;
}
```