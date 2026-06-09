### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {

        List<Integer> pairList=new ArrayList();
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){

                    pairList.add(i);
                    pairList.add(j);
                }
            }
        }
        for(int m=0;m<pairList.size();m+=2){
            clearData(matrix,pairList.get(m),pairList.get(m+1));
        }
    }
    public void clearData(int[][] matrix,int row,int clo){
        for(int i=0;i<matrix.length;i++){
            matrix[i][clo]=0;
        }
        for(int j=0;j<matrix[0].length;j++){
            matrix[row][j]=0;
        }
    }
    
}
class Position{
        int row;
        int clo;
        public void Position(int row,int clo){
            this.row=row;
            this.clo=clo;
        }
}
```