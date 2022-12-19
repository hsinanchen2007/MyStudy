![截图.PNG](https://pic.leetcode-cn.com/09330f1bede828dd5fd4788255eea45a25992f705f1d9d6fec447e04b7522350-%E6%88%AA%E5%9B%BE.PNG)
```
class Solution {
public:
    bool isPerfectSquare(long long num)
    {
        // 二分查找
        long long left = 0;
        long long right = num;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            // cout << mid << endl;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
```

