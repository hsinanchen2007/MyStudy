执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
38.46%
的用户
内存消耗 :
41 MB
, 在所有 Java 提交中击败了
66.76%
的用户
```
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if(m==0)return false;
        int n = matrix[0].length;
        if(n==0)return false;
        int line = 0;
        // for(int i=0; i<m; i++){
        //     if(matrix[i][n-1]>=target){
        //         line=i;
        //         break;
        //     }
        // }
        line=getLine(matrix,target,n,0,m-1);
        
        for(int j=0; j<n; j++){
            if(matrix[line][j]==target){
                return true;
            }
        }
        return false;
    }
    private int getLine(int[][] ma, int target, int n, int s, int e){
        if(s>=e)return s;
        int m=(s+e)/2;
        if(ma[m][n-1]>=target){
            if(ma[m][0]<=target){
                 return m;
            }else{
                return getLine(ma,target,n,s,m-1);
            }
        }else{
            return getLine(ma,target,n,m+1,e);
        }
    }
}
```
