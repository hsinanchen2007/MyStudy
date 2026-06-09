### 解题思路
先取循环条件，也就是row<2*start,col<2*start
接着按照每一圈循环输出，依次从左到右，从上到下，从右到左，从下到上输出，边界判断看注释。

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix==null||matrix.length<=0||matrix[0].length<=0)return new int[]{};
        int rows=matrix.length;
        int cols=matrix[0].length;
        int start=0;
        int[] res=new int[rows*cols];
        int index=0;
        while(rows>2*start&&cols>2*start){
            int top=start,left=start,bot=rows-1-start,right=cols-1-start;
            for(int i=start;i<=right;i++){//就算只有一个点也不需要边界判断
                res[index]=matrix[start][i];
                index++;
            }
            if(top<bot){//需要至少两行才能从上到下
                for(int i=start+1;i<=bot;i++){
                    res[index]=matrix[i][right];
                    index++;
                }
            }
            if(start<bot&&start<right){//需要至少两行两列才能从右到左
                for(int i=right-1;i>=start;i--){
                    res[index]=matrix[bot][i];
                    index++;
                }
            }
            if(start<right&&start<bot-1){//需要至少三行两列才能从下到上
                for(int i=bot-1;i>=start+1;i--){
                    res[index]=matrix[i][left];
                    index++;
                }
            }
            start++;
        }
        return res;
    }
}
```