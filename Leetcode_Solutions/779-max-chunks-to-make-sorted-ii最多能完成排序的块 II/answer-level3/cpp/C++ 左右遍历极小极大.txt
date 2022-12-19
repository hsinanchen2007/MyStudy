贪心算法：
思路：只有对于某个位置，其左边（包括该数本身）的最大值不大于位置右侧的最小值，在该处就可以分段
详见代码：
```
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int N = arr.size();
        vector<int> lmax(N, INT_MIN);
        vector<int> rmin(N, INT_MAX);
        lmax[0] = arr[0];
        rmin[N - 1] = arr[N - 1];
        for (int i = 1; i < N; ++i) {
            lmax[i] = max(lmax[i - 1], arr[i]);
            rmin[N - 1 - i] = min(rmin[N - i], arr[N - 1 - i]);
        }
        int res = 1;
        for (int i = 0; i < N - 1; ++i) {
            res += lmax[i] <= rmin[i + 1];
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/66fbdbc54633f91ebe688d2af23f458a3381bbde8068f1f6b4d7f2191e8903af-image.png)
