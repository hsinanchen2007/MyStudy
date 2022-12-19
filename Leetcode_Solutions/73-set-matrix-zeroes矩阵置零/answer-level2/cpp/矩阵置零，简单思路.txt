### 解题思路
![QQ图片20200117102129.png](https://pic.leetcode-cn.com/fd9e9e28a58252d1c2303cf97df8f6610e74ada22d35f72f5fcf21f557bc95d0-QQ%E5%9B%BE%E7%89%8720200117102129.png)

+ 先找出第一0元素所在的行记为index
+ 扫描其他行，若有0，记该元素所在列为tar，将[index,tar]元素记为0,即该列元素要置0
+ 再扫描一边，置0

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return;
        int row = matrix.size();
        int column = matrix[0].size();
        int index;
        bool status= false;
        for(int i=0;i<row;i++)//扫描出第一个不为零的数，并找出需要清零的列
            for(int j=0;j<column;j++)
            {
                if(matrix[i][j]==0&&!status)
                    index = i,status=true;
                if(matrix[i][j]==0)
                    matrix[index][j]=0;
            }
        if(!status) //没有0
            return;
        for(int i=index+1;i<row;i++)//将行清零
            for(int j=0;j<column;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i].assign(column,0);  
                    break;
                }     
            }

         for(int j=0;j<column;j++) 
            {
                if(matrix[index][j]==0)//该列清零
                {
                    for(int i=0;i<row;i++)
                        matrix[i][j]=0;
                }
            }   

         matrix[index].assign(column,0);
    }
};
```