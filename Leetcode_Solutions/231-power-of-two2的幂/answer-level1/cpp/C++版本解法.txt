第一个解

```
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        if(n == 1) return true;
        
        int i = 0, power = 1;
        
        // Calculate n^i,if out of range then exit
        while(power < n){
            // To prevent power *= out of int range
            if (power > INT_MAX/2) return false;
            power *= 2;
            if(power == n) return true;
        }
        return false;
    }
};
```
