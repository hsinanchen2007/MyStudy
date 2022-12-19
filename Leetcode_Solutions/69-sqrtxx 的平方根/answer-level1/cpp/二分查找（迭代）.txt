```
class Solution {
public:
    int mySqrt(int x) {
        if(x==1 || x==2) return 1;
        if(x==0) return 0;
        int low=1, high = x-1;
        int mid;
        while(1){
            mid = (low+high)/2;
            if(high-low == 1) return mid;
            if(x/mid == mid) return mid;
            if(x/mid > mid) low=mid;
            else high=mid;
        }
    }
};
```
