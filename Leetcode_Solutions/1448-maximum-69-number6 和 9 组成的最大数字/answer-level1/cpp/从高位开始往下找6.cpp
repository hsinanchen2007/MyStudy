```
class Solution {
public:
    int maximum69Number (int num) {
        int m = 1000000000;
        while(m != 0 && (num/m)%10 != 6)
            m /= 10;
        return num+m*3;
    }
};
```
