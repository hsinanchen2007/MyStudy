### 解题思路
按照向右走（需要满足不能向上走），向下走，向左走，向上走的顺序一个while循环解决。

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n){
        int res[][]=new int[n][n];
        int count=1;
        int i=0;
        int j=0;
        while(count<=n*n){
                res[i][j] = count;
                //如果右边可以走并且上边不可以走
                if((j+1<n&&res[i][j+1]==0)&&!(i-1>=0&&res[i-1][j]==0)){
                    j++;
                }else if(i+1<n&&res[i+1][j]==0){//如果下边可以走
                    i++;
                }else if(j-1>=0&&res[i][j-1]==0){//如果左边可以走
                    j--;
                }else {//如果上边可以走
                    i--;
                }
            count++;
        }
        return res;
}
}
```