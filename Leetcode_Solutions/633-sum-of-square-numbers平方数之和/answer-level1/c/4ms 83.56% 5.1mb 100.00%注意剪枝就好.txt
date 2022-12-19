### 解题思路
此处撰写解题思路

### 代码

```c
#include <math.h>
bool judgeSquareSum(long c){
    long limit=(int)sqrt(c);
    long i=0,j=0;
    while(i<=limit){
        j=(long)sqrt(c-i*i);
        if(i*i+j*j==c){
            return true;
        }
        i++;
    }
    return false;
}
```