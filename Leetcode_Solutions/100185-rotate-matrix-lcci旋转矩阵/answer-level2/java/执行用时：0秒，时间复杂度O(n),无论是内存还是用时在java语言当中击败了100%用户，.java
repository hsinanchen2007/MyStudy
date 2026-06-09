```
class Solution {
    public void rotate(int[][] matrix) {
        int tR = 0;
        int tC = 0;
        int dR = matrix.length-1;
        int dC = matrix[0].length-1;
        while(tR<dR){
            rotatEdge(matrix,tR++,tC++,dR--,dC--);
        }
    }
    public void rotatEdge(int[][]m,int tR,int tC,int dR,int dC){//由外向里分圈依次比较
        int tmp = 0;
        int times = dC-tC;
        for(int i = 0;i!=times;i++){
            tmp = m[tR][tC+i];
            m[tR][tC+i] = m[dR-i][tC];
            m[dR-i][tC] = m[dR][dC-i];
            m[dR][dC-i] = m[tR+i][dC];
            m[tR+i][dC] = tmp;
        }
    }
}
```
