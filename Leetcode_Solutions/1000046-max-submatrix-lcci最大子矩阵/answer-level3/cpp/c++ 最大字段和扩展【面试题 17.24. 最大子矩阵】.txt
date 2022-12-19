### 解题思路
书上例题 dp，最大字段和不会求的先去熟悉一下其求法，这题单纯是最大子段和的扩展
我们用i表示起始行，j表示结束行，将第i行至第j行的值加和到sumarr中（第x列的加和到sumarr[x]中）
然后对sumarr求最大字段和。
对每个起始行i和每个结束行j，迭代一个列的结束位置k，这样可以确定返回结果中的三个值，
分别是左上角行数i，右下角行数j，右下角列数k，唯一需要确定的是左上角列数m。
在求sumarr的最大子段和时，刚好可以确定m的值。

### 代码

```cpp
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int tt = 0, tl = 0, bb = 0, br = 0, gmax = INT_MIN;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> sumarr(matrix[0].size(), 0); // 对每个起始行i，创建一个对应的sumarr数组，初始置0
            for (int j = i; j < matrix.size(); ++j) {
                int m = 0, curmax = INT_MIN;
                for (int k = 0; k < matrix[0].size(); ++k) { 
                    sumarr[k] += matrix[j][k];      // 加和当前行当前位的值到sumarr数组中。
                    if (curmax <= 0) {              // 对sumarr[0,k]数组求最大字段和
                        m = k;                      // curmax<=0，说明以sumarr[k]结尾的最大字段和起点为自己
                        curmax = sumarr[k];
                    } else {
                        curmax += sumarr[k];
                    }
                    if (curmax > gmax) {            // 当curmax大于gmax时，更新tt，tl，bb，br
                        gmax = curmax;
                        tt = i;
                        tl = m;
                        bb = j;
                        br = k;
                    }
                }
            }
        }
        return {tt, tl, bb, br};
    }
};
```