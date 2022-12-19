```
class Solution {
public:
    int mySqrt(int x) {
        for(long int i=0;;i++)
        {
            if(x==i*i)
            return i;
            else{
                if(x>i*i&&x<(i+1)*(i+1))
                return i;
            }
        }
    }
};
```
