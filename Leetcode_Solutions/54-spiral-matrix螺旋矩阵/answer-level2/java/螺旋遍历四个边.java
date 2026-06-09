执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
91.02%
的用户
内存消耗 :
34.9 MB
, 在所有 Java 提交中击败了
47.47%
的用户
```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<Integer>();
        int m = matrix.length;
         if(m==0)return res;
        int n = matrix[0].length;
       
        
        int half =Math.min((n-1)/2,(m-1)/2); 
        for(int i=0; i<=half; i++){
            for(int j=i; j<n-i; j++){
                res.add(matrix[i][j]);
            }
            for(int k=i+1; k<m-i; k++){
                if(n-i-1>=0)res.add(matrix[k][n-i-1]);
            }
            for(int s=n-i-2; s>=i; s--){
                if(m-i-1>i)res.add(matrix[m-i-1][s]);
            }
            for(int x=m-i-2; x>i; x--){
                if(i<n-i-1)res.add(matrix[x][i]);
            }
            
        } 
        return res;
    }
}
```
