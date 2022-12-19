```
class Solution {
public:
    int lastRemaining(int n, int m)
    {
        if(n <= 0 || m <= 0)
            return -1;
        
        int last = 0;
        for(int i = 2; i <= n; i++)
            last = (last+m) % i;
        
        return last;
    }
    
};
```
