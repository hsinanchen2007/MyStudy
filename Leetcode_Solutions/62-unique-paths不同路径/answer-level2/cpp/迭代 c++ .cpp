### 解题思路

![70E26568732FAAF6175891976A6C2D08.png](https://pic.leetcode-cn.com/9d65a265fbd0564049f1e859852c4686462b517eb1548dff3b3eb10fc6a6c157-70E26568732FAAF6175891976A6C2D08.png)
先从简单情况入手，行或列为1的迷宫路径只有一条。
行列均不为一时：
以出发点为（1,1），终点为（m，n）。到达终点必经（m-1，n）或（m，n-1），到达这两点后去往终点的路径都只有一条，所以到终点的路径数为到（m-1，n）和（m，n-1）两点的路径之和。


### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int square[m][n]={};
        for(int i=0;i<m;i++)
        {
            square[i][0]=1;
        }
        for(int j=0;j<n;j++)
        {
            square[0][j]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                square[i][j]=square[i-1][j]+square[i][j-1];
            }
        }
        return square[m-1][n-1];
    }
};
```