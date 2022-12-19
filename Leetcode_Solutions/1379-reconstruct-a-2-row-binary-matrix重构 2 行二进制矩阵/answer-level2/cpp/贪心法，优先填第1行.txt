### 解题思路
使用2个计数变量curUpper、curLower分别表示当前上下2行当前的和。
贪心策略：
首先要处理colsum = 2的情况：第1行、第2行都填1，很简单；
然后考虑剩余列，都是colsum = 1的情况，分2种情况：
（1）当colsum = 2时：第1行、第2行都填1；
（2）当colsum = 1时：优先把1填充到第1行，即当curUpper < upper时填1到第1行，否则填1到第2行。
最终判断curUpper == upper 且 curLower == lower才满足题意。

为了加快无法找到解的情况，可以先对每列的colsum求和，如果不等于upper+lower，则必不满足题意，也就无需做上面的计算，可以省不少时间。


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> result(2, vector<int>(n, 0));
        int curUpper = 0;
        int curLower = 0;

        int sum = 0;
        for (auto val : colsum) {
            sum += val;
        }
        if (upper + lower != sum) {
            return {};
        }
        
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                result[0][i] = 1;
                result[1][i] = 1;
                curUpper++;
                curLower++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                continue;
            }

            if (colsum[i] == 1) {
                if (curUpper < upper) {
                    result[0][i] = 1;
                    curUpper++;
                } else {
                    result[1][i] = 1;
                    curLower++;
                }
            }
        }

        if (curUpper != upper || curLower != lower) {
            return {};
        }
        return result;
    }
};
```