### 解题思路

在遍历过程中一定会遇到一个a²<x<b²（且b-a==1）
利用此思想使用二分法查找[a，b]，当b-a==1时break，return a即可

### 代码

```cpp
#include <tgmath.h>
class Solution {
public:
    int mySqrt(int x) {
            long long a = 0;//long long是为了防止溢出
            long long b = x/2+2;
            while(true)
            {
                long long half    = (a+b)/2;
                long long square  = half*half;
                if(square>x)  b   = half;
                if(square<x)  a   = half;
                if(square==x)   return half;
                if(b-a==1)      return a;
            }
    }
};
```