```
class Solution {
    public int mySqrt(int x) {
        int left = 0;
        int right = x;
        while(left<=right) {
            int mid = left + (right-left)/2;
            if((long)mid*mid <=x && (long)(mid+1)*(mid+1) >x)
                return mid;
            if((long)mid*mid>x) {
                right = mid-1;
                continue;
            }
            if((long)(mid+1)*(mid+1) <=x) {
                left = mid+1;
                continue;
            }
        }
        return 0;
    }
}
```
