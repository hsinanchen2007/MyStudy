### 解题思路
此处撰写解题思路

### 代码

```c
int mySqrt(int x)
{
    if(x < 2)
    return x;
    
    int left = 2;
    int right = x/2;

    while(left <= right)
    {
        long mid = (left+right)/2;
        if(mid*mid > x)
        {
            right = mid-1;
        }
        else if(mid*mid < x)
        {
            left = mid+1;
        }
        else
        {
            return mid;
        }

    }
    return right;
}
```