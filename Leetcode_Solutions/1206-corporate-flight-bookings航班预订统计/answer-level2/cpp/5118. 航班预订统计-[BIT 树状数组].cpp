早上睡过头了，错过了竞赛。。。补个题解。T_T

树状数组。不是最快的，但是可以提供一个参考。

![image.png](https://pic.leetcode-cn.com/d028ef1a83988b16b51de139c35105fe0809d01fb2d26f04a0b4429cd81c8508-image.png)



```cpp
class Solution {
public:
    // O(nlogn)
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        for (auto& e : bookings) {
            update(e[1], e[2]);
            update(e[0]-1, -e[2]);
        }
        vector<int> res(n);
        for (int i = 1; i <= n; ++i) {
            res[i-1] = getSum(i, n);
        }
        return res;
    }
private:
    #define lowbit(x) ((x)&(-(x)))
    // a[1..x] 都加 v
    // O(logn)
    void update(int x, int v) {
        for (int i = x; i > 0; i -= lowbit(i)) {
            c[i] += v;
        }
    }
    
    // O(logn)
    int getSum(int x, int n) {
        int sum = 0;
        for (int i = x; i <= n; i += lowbit(i)) {
            sum += c[i];
        }
        return sum;
    }

    int c[20010] = { 0 };
};
```
