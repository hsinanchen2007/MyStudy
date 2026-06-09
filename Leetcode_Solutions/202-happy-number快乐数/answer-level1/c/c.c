### 解题思路
此处撰写解题思路
1、本题采用快慢指针的方式，更加有效且直接；
2、笨办法，可以加一个计数器，小于1000则跳转出来；

### 代码

```c
int find_next(int n)
{
    int ans = 0;

    while(n)
    {
        ans += (n % 10) * (n % 10);
        n = n / 10;
    }

    return ans;
}


bool isHappy(int n){
    int fast = find_next(n);
    int slow = n;

    while(fast != slow)
    {
        fast = find_next(fast);
        fast = find_next(fast);
        slow = find_next(slow);
    }

    if(fast == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
```