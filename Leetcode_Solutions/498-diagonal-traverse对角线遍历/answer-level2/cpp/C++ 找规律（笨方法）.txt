做题小白，记录一下自己找的规律，有点复杂。
# 解题思路

这是个M×N的矩阵，m行，n列。
首先用循环遍历的角度看待串线。

第一个遍历:每一条线，总共有n+m-1条线。
这里可以先假设每一条线的顺序都是从右上往左下，这样可以将第一次遍历分为两个阶段。
阶段一：每条线从第一行 matrix[0][i] 开始，i从0到n-1
阶段二：每条线从最后一列 matrix[i][n-1] 开始，i从1到m-1


第二个遍历：第i条线上的每个元素，这里需要考虑元素的个数取决于什么。
第一阶段的时候：元素个数随i增加慢慢增加，但不会超过行数，所以是总共有min(m,i+1)个。
像这种情况
[
[1,2,3,4],
[6,7,8,9]
]

第二个阶段的时候：元素个数随i增加慢慢减少，但不会超过列数，所以是总共有min(n,m-i)个。
像这种情况
[
[1,2],
[3,4]，
[5,6],
[7,8]
]
知道了元素的个数就可以开始遍历了，由于假设每条线是从右上往左下。
所以就是行+j，列-j。
第一阶段初始位置为 matrix[0][i] 那就是 ans[k] = matrix[0+j][i-j];
第二阶段初始位置为 matrix[i][n-1] 那就是 ans[k] = matrix[i+j][n-1-j];

最后就是考虑从左下往右上的线。
对于从右上往左下，j是从0慢慢增加。
对于从左下往右上，j是从最大值慢慢减少。

# 代码
```
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m*n);
        
        int k = 0;
        for(int i = 0; i < n; i++)//第一个阶段，从第一行 matrix[0][i] 开始
        {
            if(i%2 == 1)//右上到左下
            {
                for(int j = 0; j < min(m, i+1); j++)
                {
                    ans[k] = matrix[0+j][i-j];
                    k++;
                }
            }
            else//左下到右上
            {
                for(int j = min(m, i+1)-1; j>=0; j--)
                {
                    ans[k] = matrix[0+j][i-j];
                    k++;
                }
            }
        }
        for(int i =1; i <m; i++)//第二个阶段，从第最后一列 matrix[i][n-1] 开始
        {
            if((n+i)%2 == 0)//右上到左下
            {
                for(int j = 0; j < min(n,m-i); j++)
                {
                    ans[k] = matrix[i+j][n-1-j];
                    k++;
                }
            }
            else//左下到右上
            {
                for(int j = min(n,m-i)-1; j >= 0; j--)
                {
                    ans[k] = matrix[i+j][n-1-j];
                    k++;
                }
            }
        }
        return ans;
    }
};
```
