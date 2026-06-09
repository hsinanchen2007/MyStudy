
```
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n, 0);
        nums[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i) {
            int n2 = nums[i2] * 2, n3 = nums[i3] * 3, n5 = nums[i5] * 5;
            int min_num = min(min(n2, n3), n5);
            nums[i] = min_num;
            if (min_num == n2) ++i2;
            if (min_num == n3) ++i3;
            if (min_num == n5) ++i5;
        }
        return nums[n - 1];
    }
};
```
