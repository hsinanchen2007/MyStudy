先把第一列通过行变换变为全1，通过将每一列变成1最多即可

```
class Solution {
    public int matrixScore(int[][] A) {
        int m = A.length;
        int n = A[0].length;
        int sum = 0;
        
        //首先通过行变换将第一列变为1
        int[] flag = new int[m];
        for(int i =0; i<m;i++){
            if(A[i][0] == 0){
                flag[i] = 1; //该行需要进行行变换
            }
        }
        int aa = 1;
        for(int j = n-1;j>=1;j--){
            int temp = 0;
            for(int i =0; i<m; i++){
                if(flag[i] == 1){
                    temp += 1- A[i][j];
                }else{
                    temp += A[i][j];
                }
            }
            if(temp <= m /2){
                temp = m - temp;
            }
            sum += aa * temp;
            aa = aa * 2;
        }
        sum += m * aa;
        return sum;
    }
}