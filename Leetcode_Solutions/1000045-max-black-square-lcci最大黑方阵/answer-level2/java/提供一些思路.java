![image.png](https://pic.leetcode-cn.com/036aff261b5adf141b49ca68d69b6e8e048f25c33ba750ebe354dff06814a317-image.png)
主要思路是预先确定最上和最左两个边界，再递归判断最右和最下边界。
```
class Solution {
    int[][] matrix;
    int[] result=new int[]{0,0,0};
    public int[] findSquare(int[][] matrix) {
        this.matrix=matrix;
        if(matrix.length==0){
            return new int[]{};
        }
        for(int i=0;i<matrix.length-result[2];i++){
            for(int j=0;j<matrix.length-result[2];j++){
                if(matrix[i][j]==0){
                    int count=1;
                    while(count+i<matrix.length&&count+j<matrix.length
                    &&matrix[count+i][j]==0&&matrix[i][count+j]==0
                    ){
                        count++;
                    }
                    int actualLen=isBlackMatrix(i,j,count);
                    if(actualLen>result[2]){
                        result[0]=i;
                        result[1]=j;
                        result[2]=actualLen;
                    }
                }
            }
        }
        if(result[2]==0){
            return new int[]{};
        }
        return result;
    }
    public int isBlackMatrix(int i,int j,int size){//recursive check
        if(size==1){
            return size;
        }
        else{
            for(int x=0;x<size;x++){
                if(matrix[i+size-1][j+x]==0&&matrix[i+x][j+size-1]==0){
                    continue;
                }
                else{
                    int miniLen=isBlackMatrix(i,j,size-1);
                    return miniLen;
                }
            }
            return size;
        }
    }
}
```

