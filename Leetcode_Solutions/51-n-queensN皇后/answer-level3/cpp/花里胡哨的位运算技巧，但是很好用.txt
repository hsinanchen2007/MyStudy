![51. N皇后.PNG](https://pic.leetcode-cn.com/333a02fe0c51894114c70dec5350e379d60ebb6b7e498ca0ce95cc4446c05cfc-51.%20N%E7%9A%87%E5%90%8E.PNG?imageMogr2/auto-orient/strip%7CimageView2/2/w/220)

基本回溯思路很多优质的题解都讲得很清楚了，在这里就不再赘述。
按行递推，按列回溯，利用位来标记正上方、右上方、左上方已经有棋子的位置，当且仅当三个标记上（`up`, `upright`, `upleft`）第`k`位都为`0`，当前这行第`k`列这个位置才能放棋子。这个是真的很方便！！
这是从[WNJXYK大佬]()的B站[算法ABC栏目](https://www.bilibili.com/video/BV1Y7411N7Bn)学来的，强烈推荐这位UP主，基本周赛排行榜的第一页都能看到他的ID。
```
class Solution {
public:
    int n;
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<vector<string>> ans;
        vector<string> state(n, string(n, '.'));
        backTrace(ans, state, 0, 0, 0, 0);
        return ans;
    }
    
    void backTrace(vector<vector<string>>& cache, vector<string>& state, int r, int up, int upleft, int upright) {
        if (r == n) {
            cache.push_back(state);
            return ;
        }
        for (int k = 0; k < n; ++k) {
            int gridLoc = 1 << k;
            if (gridLoc & up || gridLoc & upleft || gridLoc & upright) continue ;
            state[r][k] = 'Q';
            backTrace(cache, state, r + 1, up | gridLoc, (gridLoc | upleft) >> 1, (gridLoc | upright) << 1);
           // 这里upleft和upright的右移和左移操作，自己画一画就清楚了
            state[r][k] = '.';
        }
    }
};
```
