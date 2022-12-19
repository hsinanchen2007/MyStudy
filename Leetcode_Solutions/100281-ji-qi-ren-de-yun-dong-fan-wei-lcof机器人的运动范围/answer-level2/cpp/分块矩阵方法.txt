大家都知道这道题用dfs或者bfs搜索即可，在搜索方向上做优化减少位数和运算。我做这道题的时候思路比较清奇，用了分块矩阵降低常数时间复杂度（无法降低复杂度但是能更快一些）的方法。

首先将矩阵分解为若干个10*10的子矩阵，每个子矩阵满足沿行和列方向位数和增大，并且增量为1。我们将子矩阵编号设为(r,c)，那么子矩阵的最小元素值为r+c，最大元素为r+c+18。如果一个子矩阵的主对角线可以达到，那么(r+1,c)和(r,c+1)矩阵皆可以达到。

因此该题可以将问题分解为两部分，首先计算第一行能有多少个子矩阵被访问到，然后用这些子矩阵不断地向下搜索，如果不可达即终止。并且计算每个子矩阵能访问到的元素。

可以看到代码较为复杂，在计算子矩阵的访问元素时采用了大量的等差数列求和，如果不小心算错下界和上界很容易出错。

因此不推荐写这样的代码，不过提出这样一种思路供大家思考。
```C++
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int row = (m + 9) / 10, col = (n + 9) / 10, max_col = min(max(k - 7, 1), col), tcol, counter = 0;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < max_col; c++){
                counter += cnt(m, n, r, c, k);
                if(k - r - c >= 9)
                    tcol = c + 1;
            }
            max_col = tcol;
            tcol = 0;
        }
        return counter;
    }
    int cnt(int m, int n, int r, int c, int k){
        int counter = 0, lb = r + c, ub = r + c + 18, row = m - r * 10, col = n - c * 10;
        if((r + 1) * 10 >= m && (c + 1) * 10 >= n){ // 处理角
            for(int i = lb; i < lb + row; i++){
                if(k >= i + col - 1)
                    counter += col;
                else if(k >= i)
                    counter += k - i + 1;
                else
                    break;
            }
            return counter;
        } else if((r + 1) * 10 >= m || (c + 1) * 10 >= n){ // 处理边
            if((c + 1) * 10 >= n){
                swap(r, c);
                swap(m, n);
                swap(row, col);
            }
            if(k - lb + 1 <= row)
                return (k - lb + 2) * (k - lb + 1) / 2;
            else if(k <= lb + 9)
                return (k - lb + 2) * (k - lb + 1) / 2 - (k - lb - row + 1) * (k - lb + 2 - row) / 2;
            else if(k <= lb + row + 8)
                return row * 10 - (row - k + lb + 8) * (row - k + lb + 9) / 2;
            else
                return row * 10;
        } else{ // 处理内部
            if(k <= lb + 9)
                return (k - lb + 2) * (k - lb + 1) / 2;
            else if(k <= ub)
                return 100 - (1 + ub - k) * (ub - k) / 2;
            else
                return 100;
        }
    }
};
```