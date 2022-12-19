```c++
class Solution {
public:
    int numWays(int n, int k) {
        if (!n) {
            return 0;
        }
        if (n == 1) {
            return k;
        }
        int diff = k * (k - 1);
        int same = k;
        for (int i = 3; i <= n; ++i) {
            int tmp = diff;
            diff = same * (k - 1) + diff * (k - 1);
            same = tmp;
        }
        return diff + same;
    }
};