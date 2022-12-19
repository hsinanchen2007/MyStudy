```
class Solution {
public:
    int reachNumber(int target) {
        target = (target > 0 ? target : -target);
        int left = 1, right = (target > sqrt(INT_MAX) ? sqrt(INT_MAX) : target), mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int low = mid * (mid - 1) / 2, high = mid * (mid + 1) / 2;
            if (low == target) {
                return mid - 1;
            } else if (high == target) {
                return mid;
            } else if (low < target && high > target) {
                if (((high - target) % 2) == 0)
                    return mid;
                if (target - low == 1)
                    return mid + 1;
                if (((mid + 1) * (mid + 2) / 2 - target) % 2 == 0)
                    return mid + 1;
                return mid + 2;
            } else if (high < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
```
![Screen Shot 2020-01-04 at 4.34.04 PM.png](https://pic.leetcode-cn.com/6700fc5c774e848ce75fd3ae85891831aa9541cf5934af38ad847afee3f1adc7-Screen%20Shot%202020-01-04%20at%204.34.04%20PM.png)
