```
class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        int left=1, right = x/2+1;
        long long mid=(right+left)/2;
        while(left<=right) {
            if(mid*mid>x){
                right = mid-1;
            }else if(mid*mid<x) {
                left = mid+1;
            }else break;
            mid = (right+left)/2;
        }
        return mid;
    }
};
```
