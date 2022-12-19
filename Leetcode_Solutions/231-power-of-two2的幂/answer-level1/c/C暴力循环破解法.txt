```
#include <Math.h>
bool isPowerOfTwo(int n){
    if(n==1) return true;
    if(n%2==1 || n<=0) return false;
    int s = 1;
    while(s<100){
        if(n == pow(2,s))
            return true;
        s++;
    }
    return false;
}
```
