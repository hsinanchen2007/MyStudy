```
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        int row=matrix.length;
        if(row==0) return new int[0];
        int col=matrix[0].length;
        if(row==1) return matrix[0];
        int[] ou=new int[row*col];
        int up=0,dn=row-1,lf=0,rt=col-1;
        int cnt=0,max=ou.length;
        while(up<=dn && lf<=rt){
            for(int j=lf;j<=rt;j++){
                ou[cnt++]=matrix[up][j];
                if(cnt==max) return ou;
            }
            for(int i=up+1;i<=dn;i++){
                ou[cnt++]=matrix[i][rt];
                if(cnt==max) return ou;
            }
            for(int j=rt-1;j>=lf;j--){
                ou[cnt++]=matrix[dn][j];
                if(cnt==max) return ou;
            }
            for(int i=dn-1;i>up;i--){
                ou[cnt++]=matrix[i][lf];
                if(cnt==max) return ou;
            }
            up++;dn--;lf++;rt--;
        }
        return ou;
    }
}
```
