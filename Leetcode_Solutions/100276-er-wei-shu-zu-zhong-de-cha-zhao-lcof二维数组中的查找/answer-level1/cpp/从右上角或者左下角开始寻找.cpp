从左往右递增，从上往下递增
对于右上角的数A来说：A的那一行，A的左边都比A小，若target<A，则去A的左边找；A的那一列，A的下边都A大，若target>A，则去A的下边找
对于左下角的数B来说：B的那一行，B的右边都比B大，若target>B，则去B的右边找；B的那一列，B的上边都B小，若target<B，则取B的上边找

从右上角或者左下角开始寻找都一样，都是通过比较然后不断地缩小搜寻的范围，直至找到target或者

```
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        
        int rows=matrix.size();
        if(rows==0) return false;
        int cols=matrix[0].size();

        int curRow=rows-1;
        int curCol=0;

        while(curRow>=0&&curCol<=cols-1){
            if(matrix[curRow][curCol]>target){
                curRow=curRow-1;
            }
            else if(matrix[curRow][curCol]<target){
                curCol=curCol+1;
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};
```
