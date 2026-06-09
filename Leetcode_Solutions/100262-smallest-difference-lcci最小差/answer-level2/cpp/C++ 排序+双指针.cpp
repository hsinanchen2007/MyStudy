排序加双指针比较
```c++
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long ans = INT_MAX;
        for (int i1 = 0, i2 = 0; i1 < a.size() && i2 < b.size();) {
            if (a[i1] == b[i2]) {
                return 0;
            }
            ans = min(ans, abs(long(a[i1]) - long(b[i2])));
            if (a[i1] < b[i2]) {
                i1++;
            } else {
                i2++;
            }
        }
        return ans;
    }
};
```
