执行结果：
通过
显示详情
执行用时 :
7 ms
, 在所有 Java 提交中击败了
16.37%
的用户
内存消耗 :
54.9 MB
, 在所有 Java 提交中击败了
21.75%
的用户
```
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        if(m==0)return;
        int n = matrix[0].length;
        
        Set<Integer> mlist = new HashSet<>();
        Set<Integer> nlist = new HashSet<>();
        for(int i=0 ; i<m; i++){
            for(int j=0 ; j<n; j++){
                if(matrix[i][j]==0){
                    mlist.add(i);
                    nlist.add(j);
                }
            }
        }
        for(Integer i: mlist){
             for(int j=0 ; j<n; j++){
                 matrix[i][j]=0;
             }
        }
        for(Integer i: nlist){
             for(int j=0 ; j<m; j++){
                 matrix[j][i]=0;
             }
        }
        
    }
}
```
