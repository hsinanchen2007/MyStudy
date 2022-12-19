### 解题思路
冒泡排序法：
比较相邻行对角线元素，较大值下移，将对角线最大元素排列在最后一行；
重复以上过程，依次将对角线最大元素排列在倒数第二行、倒数第三行……；
完成排序。

### 代码

```cpp
/*
冒泡排序法：
比较相邻行对角线元素，较大值下移，将对角线最大元素排列在最后一行；
重复以上过程，依次将对角线最大元素排列在倒数第二行、倒数第三行……；
完成排序。
*/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> rmat=mat;
        int r=mat.size();//rows
        int l=mat[0].size();//col
        //缩小排列范围，已经排列好的不需再次排序
        for(int k=0;k!=r-1;k++)
        {
            //冒泡排序，依次排列最后一行至第二行
            for(int i=1;i!=r-k;i++)
            {
                //相邻行对角线元素较大值下移
                for(int j=1;j!=l;j++)
                {
                    //swap(rmat[i][j],rmat[i-1][j-1])
                    if(rmat[i][j]<rmat[i-1][j-1])
                    {
                        rmat[i][j]=rmat[i][j]+rmat[i-1][j-1];
                        rmat[i-1][j-1]=rmat[i][j]-rmat[i-1][j-1];
                        rmat[i][j]=rmat[i][j]-rmat[i-1][j-1];
                    }
                }
            }
        }

        return rmat;
    }
};
```