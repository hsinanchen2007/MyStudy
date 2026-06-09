### 解题思路
纯C 二分法

### 代码

```c
int mySqrt(int x){
    int low = 0;
    int high = x;
    int mid = 0;

    if (x < 0)
    {
        return -1;
    }

    if (x <= 1)
    {
        return x;
    }

    while(low + 1 < high)    
    {
        mid = low + (high - low) / 2;

        if (x/mid < mid) 
        { 
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    
    return low;    
}
```