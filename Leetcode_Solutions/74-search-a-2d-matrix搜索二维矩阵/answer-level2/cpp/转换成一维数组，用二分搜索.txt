算法思路  
根据二维数组数值特点，将其想象成为我们熟悉的一维数组求解。而这里二维转成一维的关键是一维数组的下标mid和二维数组下标[i][j]的换算关系：[i][j]=[mid/列数][mid%列数]。直接上代码，比较简介应该很容易看懂，就不再赘述了。

代码实现
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()){
            return false;
        }
        int rows=matrix.size();//行数
        int collums=matrix[0].size();//列数
        int left=0;
        int right=rows* collums-1;
        while(right>=left){
            int mid=(left+right)/2;
            int i=mid/collums;//一维数组下标mid对应的行坐标i；
            int j=mid%collums;//一维数组下标mid对应的列坐标j；
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return false;      
    }
};
```
运算结果：一次运行中，12ms,78.10%;9.6MB,98.38%.
