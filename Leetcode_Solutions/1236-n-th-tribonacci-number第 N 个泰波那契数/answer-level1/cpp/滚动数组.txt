滚动数组，空间复杂度 O(1)
```
class Solution {
public:
    int tribonacci(int n) {
        int a[4] = {0,1,1,2};
        if(n < 4) return a[n];
        for(int i = 3;i <= n; ++i) {
            a[(i) % 4] = a[(i - 3) % 4] + a[(i - 1) % 4] + a[(i - 2) % 4];
        }
        return a[n%4];
    }
};
```
