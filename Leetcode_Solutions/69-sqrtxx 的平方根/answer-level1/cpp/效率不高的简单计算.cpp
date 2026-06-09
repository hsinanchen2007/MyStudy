
```
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        long long i=1;
        while(i*i<=x)
            i++;
        return i-1;
    }
};
```
