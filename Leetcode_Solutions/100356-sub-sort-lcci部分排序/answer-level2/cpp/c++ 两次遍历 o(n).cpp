### 解题思路
array中某个数字在排序前后位置不变，必须满足两个条件：1. 前面没有比自己小的数字；2.后面没有比自己打的数字。
定义dp保存上面表述的信息， dp[i]=true表示array[i]在排序前后位置不变，dp[i]=false，表示在排序前后array[i]位置发生变化。
从前向后扫描数组，不断更新扫描到的最大值，既可以判断当前array[i]之前是否存在比自己小的数字，如果存在则dp[i]置为false;
从后向前扫描数组，不断更新扫描到的最小值，既可以判断当前array[i]之后是否存在比自己小的数字，如果存在则dp[i]置为false;
找到dp[i]为false的最小和最大的i，即为要返回的数据

### 代码

```cpp
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        if (!array.size()) return {-1, -1};
        vector<bool> dp(array.size(), true);
        int maxval = array[0];
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] < maxval) {
                dp[i] = false;
            } else {
                maxval = array[i];
            }
        }
        int minval = array[array.size()-1];
        int rmax = -1;
        int rmin = array.size();
        for (int i = array.size()-1; i >= 0; --i) {
            if (array[i] > minval) {
                dp[i] = false;
            } else {
                minval = array[i];
            }
            if (!dp[i]) {
                rmax = max(rmax, i);
                rmin = min(rmin, i);
            }
        }
        if (rmax == -1) return {-1, -1};
        return {rmin, rmax};
    }
};
```