二分基础题
```
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        int mid = left + (right - left)/2;
        while (left <= right) {
            mid = left + (right - left)/2;
            int g = guess(mid);
            if (g == 0) {
                return mid;
            }else if (g == -1) {
                right = mid - 1;
            }else if (g == 1){
                left = mid + 1;
            }
        }
        return mid;
    }
};
```
