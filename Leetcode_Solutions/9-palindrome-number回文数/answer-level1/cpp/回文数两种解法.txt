如下写法执行时间24ms
```cpp
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if((x < 0) || ((x % 10 == 0) && (x != 0)))
        {
            return false;
        }

        int y = 0;

        while(x > y)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return (x == y) || (x == y / 10);
    }
};
```

如下写法执行时间16ms
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)
        {
            return false;
        }

        long long ox = x;
        long long y = 0;

        while(x > 0)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return ox == y;
    }
};