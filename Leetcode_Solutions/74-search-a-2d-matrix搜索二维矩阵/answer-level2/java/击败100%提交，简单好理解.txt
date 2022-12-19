### 解题思路
实际上我感觉用`O(nlogn)`是最传统的了
首先在第0列中用二分查找找出`target`:
1.  如果有`target`:就直接返回第几行;
2.  如果没有`target`:就返回数值小于`target`的最大行数。比如下列的`3×3`矩阵`m`,target为3:
    [
        [1,2,3]
        [2,5,6]
        [4,8,9]
    ]
显然，我们应该返回1,因为m[1][0]=2，该数值小于3而且处在行数最大的位置上。
接下来，确定了最大行数maxrow后，我们就应该很清楚，target的可能位置只能是前maxrow行中的某一行。比如上面那个矩阵，3要么在第0行，要么在第1行。
所以，只需从0～maxrow用二分查找寻找每一行的元素即可。
### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) 
    {
        if(matrix.length==0||matrix[0].length==0)return false;
        if(matrix[0][0]>target||matrix[matrix.length-1][matrix[0].length-1]<target)
            return false;
        
        int maxrow=searchRow(matrix,0,0,matrix.length-1,target);
        if(matrix[maxrow][0]==target)return true;
        //System.out.println("maxrow:"+maxrow+",matrix[maxrow][0]:"+matrix[maxrow][0]);
        for(int i=0;i<=maxrow;i++)
        {
            int col=searchCol(matrix,i,0,matrix[0].length-1,target);
            if(matrix[i][col]==target)return true;
        }
        return false;
        
    }
    //return the index which is the max number of the smaller ones.
    private int searchRow(int[][] matrix,int col,int left,int right,int target)
    {
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(matrix[mid][col]>target)
                right=mid-1;
            else if(matrix[mid][col]<target)
                left=mid+1;
            else return mid;
        }
        if(left==right)
            return matrix[left][col]<=target?left:left-1;
        return right;
    }
    //return the index which is the mini number of the greater ones.
    private int searchCol(int[][] matrix,int row,int left,int right,int target)
    {
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(matrix[row][mid]>target)
                right=mid-1;
            else if(matrix[row][mid]<target)
                left=mid+1;
            else return mid;
        }
        return left;
    }
}
```