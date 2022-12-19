### 解题思路
此处撰写解题思路

### 代码

```c
#include <math.h>
#define MAX 2147483647
#define MIN -2147483647
int reverse(int x){
    long y = 0;
    int z = pow(10 , getCount(x));
    if(abs(x % 10) > 2 && getCount(x) > 8)
    {
        return 0;
    }
    while(x != 0)
    {
        y += (x % 10) * z;
        x /= 10;
        z /= 10;
    }
    if(y > MAX || y < MIN)
    {
        return 0;
    }
    return y;
}

int getCount(int i)
{
    int count = 0;
    while(i != 0)
    {
        i /= 10;
        count++;
    }
    return count - 1;
}
```