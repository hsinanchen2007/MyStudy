### 解题思路
借鉴[@hoorayeah](/u/hoorayeah/) 同学的py3完成的C++版解法。具体思路见注释。

### 代码

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int ans = 0, m = mat.size(), n = mat[0].size();
        //根据题意，不会为空，所以不用特判，否则要记得特判边界
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!mat[i][j]) continue;//是0的话，那么以该元素为最右下角元素肯定不存在全1正方形
                else if(!i || !j) ++ans;//边界的话，那么以该元素为最右下角元素肯定只有1个全1正方形
                else {
                    mat[i][j] = min(mat[i - 1][j - 1], min(mat[i - 1][j], mat[i][j - 1])) + 1;//重点是这里，直接覆盖前面的值就可以了，因为只需要计算整个矩阵有多少个全1正方形，所以不需要再存储原矩阵的值，矩阵可以用作存储“备忘录”，用来存储以某个元素为最右下角元素有多少个全1正方形
                    ans += mat[i][j];//累加到结果上
                }
            }
        }
        return ans;
    }
};
```