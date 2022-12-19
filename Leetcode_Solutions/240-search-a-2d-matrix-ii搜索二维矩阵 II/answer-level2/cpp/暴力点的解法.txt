### 解题思路
排除大于该值的行，排除大于该值的列；
排除小于该值的行，排除小于该值的列；
麻烦了点，不过
内存消耗 :10.8 MB, 在所有 C++ 提交中击败了100.00%的用户
//
### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        if(rows==0)
           return false;
        int cols=matrix[0].size();

        if(cols==0)
            return false;

        int row=rows-1;
        int col=cols-1;
//排除不可能的行（行首数值超过target）
        while(target<matrix[row][0]){
            --row;
            if(row<0)
              return false;
        }
//排除不可能的列（列首数值超过target）
        while(target<matrix[0][col]){
            --col;
            if(col<0)
               return false;
        }

        int startRow=0;
        int startCol=0;
//排除不可能的行（行尾数值小于target）
        while(target>matrix[startRow][col]){
            ++startRow;
            if(startRow>row)  //防止不存在时越界
               return false;
        }
  //排除不可能的列（列尾数值小于target）
        while(target>matrix[row][startCol]){
            ++startCol;
             if(startCol>col)   //防止不存在时越界
               return false;
        }

//这里其实还可以加个二分查找
        for(int i=startRow;i<=row;i++){
            for(int j=startCol;j<=col;j++){
                if(matrix[i][j]==target)
                    return true;
            }    
        }


        return false;

    }
};
```