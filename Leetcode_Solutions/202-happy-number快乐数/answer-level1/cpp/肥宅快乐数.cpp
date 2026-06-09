```cpp
class Solution {
public:
    int convert(int x){
        int res=0;
        while(x){
            res+=(x%10)*(x%10);
            x/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        while(n>=10){
            n=convert(n);
        }
        return n==1||n==7;
    }
};
```