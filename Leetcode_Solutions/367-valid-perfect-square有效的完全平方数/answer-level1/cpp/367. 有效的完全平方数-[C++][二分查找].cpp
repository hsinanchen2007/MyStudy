```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 1) return true;
        
        int lo = 1, hi = num / 2;
        while (lo < hi) {
            int mid = lo + (hi - lo >> 1);
            if (mid >= num / mid) { // mid * mid >= num
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return (long)lo * lo == num;
    }
};
```
