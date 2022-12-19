```
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        int[][] ans=new int[mat.length][mat[0].length];
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[i].length;j++){
                ans[i][j]=sum(mat,i,j,K);
            }
        }
        return ans;
    }
    public int sum(int[][] mat,int i,int j,int K){
        int ansSum=0;
        for(int t=i-K;t<=i+K;t++){
            for(int f=j-K;f<=j+K;f++){
                if(t<0||f<0||t>=mat.length||f>=mat[0].length){
                    continue;
                }
                ansSum+=mat[t][f];
            }
        }
        return ansSum;
    }
}
```
