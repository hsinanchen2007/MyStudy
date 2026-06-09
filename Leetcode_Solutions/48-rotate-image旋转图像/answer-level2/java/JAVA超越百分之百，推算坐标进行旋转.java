```
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix.length==1)
        return;
        int indexI=0,indexJ=0,i=0,j=0,change;
        int t1,t2;
        int len=matrix.length-1;
        boolean rotate[][]=new boolean[matrix.length][matrix.length];
        while (indexI!=(len+1)/2+1){
            if(rotate[indexI][indexJ]){
                indexI++;
                indexJ=indexI;
                continue;
            }
            t1=matrix[indexI][indexJ];
            for(i=indexJ,j=len-indexI;!rotate[i][j];i=j,j=len-change){
                t2=matrix[i][j];
                matrix[i][j]=t1;
                t1=t2;
                rotate[i][j]=true;
                change=i;
            }
            indexJ++;
        }
    }
}
```
