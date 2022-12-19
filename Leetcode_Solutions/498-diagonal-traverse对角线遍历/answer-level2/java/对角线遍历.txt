执行用时 : 5 ms, 在所有 Java 提交中击败了82.45%的用户

内存消耗 :50.4 MB, 在所有 Java 提交中击败了61.28%的用户

```
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if(matrix==null||matrix.length==0||matrix[0]==null||matrix[0].length==0){
            return new int[0];
        }
        int[] res=new int[matrix.length*matrix[0].length];
        int index=0;
        int tR=0,tC=0,dR=0,dC=0;
        int endR=matrix.length-1;
        int endC=matrix[0].length-1;
        boolean flag=false;
        while(index<matrix.length*matrix[0].length){
            if(flag){
                for(int i=dR,j=dC;i<=tR&&j>=tC;){
                    res[index++]=matrix[i++][j--];
                }
            }else{
                for(int i=tR,j=tC;i>=dR&&j<=dC;){
                    res[index++]=matrix[i--][j++];
                }
            }   
            flag=!flag;
            tC=tR==endR?tC+1:tC;
            tR=tR==endR?tR:tR+1;
            dR=dC==endC?dR+1:dR;
            dC=dC==endC?dC:dC+1;
        }
        return res;
    }
}
```