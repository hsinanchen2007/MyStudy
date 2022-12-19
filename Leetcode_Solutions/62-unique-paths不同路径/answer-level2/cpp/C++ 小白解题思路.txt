### 解题思路
1.建立二维m*n数组
2.第一行，第一列均为1
3.填写其他空格，res[i][j] = res[i-1][j] + res[i][j-1];
4.返回表格右下角的值

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int res[n][m] = {0};
        for(int i=0;i<n;i++)
            res[i][0] = 1;
        for(int j=0;j<m;j++)
            res[0][j] = 1;

        for(int k1=1;k1<n;k1++)
            for(int k2=1;k2<m;k2++)
                res[k1][k2] = res[k1-1][k2] + res[k1][k2-1];
        return res[n-1][m-1];
    }
};
```
执行结果：通过
执行用时 :0 ms
在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.6 MB
在所有 C++ 提交中击败了100.00%的用户