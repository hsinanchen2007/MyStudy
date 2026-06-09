二分模板题

```
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 0;
        int r = n;
        while (l < r) {
            int mid = l + (r-l)/2;
            int res = guess(mid);
            if (res == 0) {
                return mid;
            } else if (res == 1) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
```