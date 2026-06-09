**思路：**
我们把Point(i, arr[i], arr[j])看作三位空间中的一个点
那么题目就是要求所有这些点中曼哈顿距离最远的两个点的距离

“任意两个点的曼哈顿距离就等于：这两个点到8个角落的曼哈顿距离差绝对值的最大值”

因此我们只需要针对每一个角落，找到最近、最远的点，然后计算他们的距离差
然后把八个角落结果再取最大就是我们要的结果

```
class Solution {
public:
    const int MAX_N = 2e6;
    int CORNER[8][3] = {
        {0, 0, 0}, {0, 0, MAX_N}, {0, MAX_N, MAX_N}, {0, MAX_N, 0},
        {MAX_N, 0, 0}, {MAX_N, 0, MAX_N}, {MAX_N, MAX_N, MAX_N}, {MAX_N, MAX_N, 0}};
    
    int manhatten(int x1, int y1, int z1, int x2, int y2, int z2) {
        return abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2);
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int N = arr1.size();
        vector<vector<int> > d(8, vector<int>(N, 0));
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < N; ++j) {
                d[i][j] = manhatten(j, arr1[j] + MAX_N / 2, arr2[j] + MAX_N / 2, CORNER[i][0], CORNER[i][1], CORNER[i][2]);
            }
        }
        int res = 0;
        for (int i = 0; i < 8; ++i) {
            int mx = *max_element(d[i].begin(), d[i].end());
            int mn = *min_element(d[i].begin(), d[i].end());
            res = max(res, mx - mn);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/b7fa9879f54bb223bc17810155930370f16c77ab6b96d880ee18d38b49aa94ba-image.png)
