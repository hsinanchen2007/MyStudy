```cpp
class Solution {
public:
    int cuttingRope(int n) {
        std::ios::sync_with_stdio(false);
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return n;
        int m=n%3;
        int l=n/3;
        if(m==0) return pow(3,l);
        if(m==1) {
            return pow(3,l-1)*2*2;
        }else{
            return pow(3,l)*2;
        }
    }
};
```