c++ 二分即可
注意相等情况下不要提前返回，而是继续找最小
```
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 0, m, res = INT_MAX;
        for (int& n: nums) {
            r = max(r, n);
        }

        while(l <= r) {
            m = (l + r) / 2;
            int temp = 0;
            for (int& n: nums) temp += (n + m - 1) / m;
            if (temp > threshold) {
                l = m + 1;
            }
            else {
                r = m - 1;
                res = min(res, m);
            }
        }
        
        return res;
    }
};
```