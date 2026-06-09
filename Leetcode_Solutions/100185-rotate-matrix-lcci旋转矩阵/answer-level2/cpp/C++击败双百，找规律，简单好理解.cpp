# 解题思路


![image.png](https://pic.leetcode-cn.com/05e63e0e1850d247fafe6f2bf3828f13b8d43b7b5c3b5f2202e7d9fa0cf1d916-image.png)



原地顺时针旋转`90°`，通过观察上图原矩阵的`[0,1]`这个元素`1`。经过变换，它会在`[1,3]`位置，而元该位置的元素`10`变换后位置是`[3,2]`，同样原位置的元素`12`变换后位置是`[2,0]`，原位置的`13`变换后位置是`[0,1]`。       
`[0,1]->[1,3]->[3,2]->[2,0]->[0,1]`这就是相关位置的元素的位置变换（我们先称这么一个变换为一个完整旋转）。它们的规律其实就很简单了：前一个位置的列等于后一个位置的行，前位置的行加上后位置的列等于方阵的阶`n`减一。表示出来就是`[i,j]->[j,n-1-i]`。

# 细节分析
![image.png](https://pic.leetcode-cn.com/1e17a5dd508011d70352e4728b32b710f52f6062684b6a750c73cbbbe33a3b17-image.png)


* 如上图方阵来说，我么只需要对该方阵的红方框内的子式中每个元素进行一次完整旋转就可以完成题目任务。


* 对于奇数阶方阵来说，我们主要是要考虑其中间行列的元素。此时我们选取如下子式：




![image.png](https://pic.leetcode-cn.com/77c659e962dd0239de7d9d215daf344175495b69fab84adf99ac7f90343eed98-image.png)

# 代码
```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), jj = n/2;
        if(n%2 == 1) jj++;
        for(int i=0; i<n/2; i++)
            for(int j=0; j<jj; j++)
            {
                int a=matrix[i][j], b=matrix[j][n-1-i],
                    c=matrix[n-1-i][n-1-j], d=matrix[n-1-j][i];
                matrix[i][j]         = d;
                matrix[j][n-1-i]     = a;
                matrix[n-1-i][n-1-j] = b;
                matrix[n-1-j][i]     = c;
            }
    }
};
```