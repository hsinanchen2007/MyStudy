### 解题思路
只能一条边一条边的打印，首先我们要从给定的mxn的矩阵中算出按螺旋顺序有几个环，注意最终间的环可以是一个数字，也可以是一行或者一列。环数的计算公式是 min(m, n) / 2，知道了环数，我们可以对每个环的边按顺序打印:
我们定义p，q为当前环的高度和宽度，当p或者q为1时，表示最后一个环只有一行或者一列，可以跳出循环。此题的难点在于下标的转换，如何正确的转换下标是解此题的关键，我们可以对照着上面的3x3的例子来完成下标的填写。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return {};

        int m = matrix.size();
        int n = matrix[0].size();

        int c = m > n?(n + 1)/2:(m + 1)/2;
        vector<int> ans;

        for(int i = 0;i < c;++i,m -= 2,n -= 2)
        {
            for(int col=i;col<i+n;++col)
                ans.push_back(matrix[i][col]);
            for(int row=i+1;row<m+i;++row)
                ans.push_back(matrix[row][i+n-1]);
            if(m==1||n==1) break;
            for(int col=i+n-2;col>=i;--col)
                 ans.push_back(matrix[m-1+i][col]);
            for(int row=i+m-2;row>i;--row)
                ans.push_back(matrix[row][i]);
        }
        return ans;
    }
};
```