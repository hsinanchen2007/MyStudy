```
public class Solution {
    public int[][] FlipAndInvertImage(int[][] A) {
        
        int p=0,j=0,k=0;
        
        for(int i=0;i<A.Length;i++){
            p=0;
            j=A[i].Length-1;
            //翻转每一行
            while(p<=j){
                k = A[i][p];
                A[i][p] = 1-A[i][j];
                A[i][j] =1-k;
                
                    
                p++;
                j--;
            }
            
            
        }
        return A;
    }
}
```
