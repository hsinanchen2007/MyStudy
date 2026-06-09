
使用笨办法 遍历每个1位顶点 构成的正方形

```java
class Solution {
    public int maximalSquare(char[][] matrix) {
        int res = 0;
        boolean isOne = false;
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                //以每个1位定点去遍历最大的正方形
                if(matrix[i][j] == '1'){
                    isOne = true;
                    res = Math.max(res,getSquare(matrix,i,j));
                }
            }
        }
        //返回res为0 可能是元素全部为0 也有可能没有构成正方形
        return res == 0 && isOne ? 1 : res;
    }

    public int getSquare(char[][] matrix,int i,int j){
        //从边长1开始 逐渐增加
        int k = 1;
        int max = 0;
        while((i+k) < matrix.length && (j+k) < matrix[0].length){
            boolean flag = true;
            //遍历一圈
            for(int m = 0; m <= k; m++){
                if(matrix[i+m][j+k] == '1' && matrix[i+k][j+m] == '1'){
                    continue;
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                //满足条件的话 面积加大
                max = (k+1) * (k+1);
                k++;
            }else{
                break;
            }
        }
        return max;
    }

}
```