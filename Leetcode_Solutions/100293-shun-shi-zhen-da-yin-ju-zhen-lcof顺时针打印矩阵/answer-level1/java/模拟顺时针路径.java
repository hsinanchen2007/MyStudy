```
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length==0||matrix[0].length==0){
            return new int[0];
        }
        int rowR=matrix.length;
        int columnR=matrix[0].length;
        int rowL=1;
        int columnL=0;
        int [] res=new int[rowR*columnR];
        int index=0;
        int count=0;
        int i=0;
        int j=0;
        while(index<res.length){
            //向右
            if(count==0&&index<res.length){
                while(j<columnR){
                    res[index]=matrix[i][j];
                    index++;
                    j++;
                }
                columnR--;
                count=(count+1)%4;
            }
            j--;
            i++;
            //向下
            if(count==1&&index<res.length){
                while(i<rowR){
                    res[index]=matrix[i][j];
                    index++;
                    i++;
                }
                rowR--;
                count=(count+1)%4;
            }
            i--;
            j--;
            //向左
            if(count==2&&index<res.length){
                while(j>=columnL){
                    res[index]=matrix[i][j];
                    index++;
                    j--;
                }
                columnL++;
                count=(count+1)%4;
            }
            j++;
            i--;
            //向上
            if(count==3&&index<res.length){
                while(i>=rowL){
                    res[index]=matrix[i][j];
                    index++;
                    i--;
                }
                rowL++;
                count=(count+1)%4;
            }
            i++;
            j++;
        }
        return res;
    }
}
```
