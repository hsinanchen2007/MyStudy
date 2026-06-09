exchange A[i][j] and A[i][A[i].length-j-1]
meanwhile invert image

class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int i=0;i<A.length;i++)
            for(int j=0;j<(A[i].length+1)/2;j++){
                int k=A[i][j];
                A[i][j]=1-A[i][A[i].length-j-1];
                A[i][A[i].length-j-1]=1-k;                    
            }
        return A;
    }
    
}