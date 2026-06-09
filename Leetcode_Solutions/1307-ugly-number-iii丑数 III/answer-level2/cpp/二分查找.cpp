通过二分查找，判断 mid 是第几个丑数，套用 lower_bound 的模板。
求第几个丑数用到最小公倍数。
```c++
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long ab = static_cast<long>(a) / __gcd(a, b) * b;
        long ac = static_cast<long>(a) / __gcd(a, c) * c;
        long bc = static_cast<long>(b) * static_cast<long>(c) / __gcd(b, c);
        long abc = a * bc / __gcd(static_cast<long>(a), bc);
        int left = 0;
        int right = INT_MAX;
        int mid;
        while(left < right) {
            mid = (right - left) / 2 + left;
            int count = mid / a + mid / b + mid / c - mid / ab - mid / ac - mid / bc + mid / abc;
            if(count < n) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
```