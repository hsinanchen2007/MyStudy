![QQ浏览器截图20200407195934.png](https://pic.leetcode-cn.com/abcb946f8c3702765febf8efffeb9e3fd3a32dd9b5a221004bac30b0bc4fc7d9-QQ%E6%B5%8F%E8%A7%88%E5%99%A8%E6%88%AA%E5%9B%BE20200407195934.png)



将整体的旋转转化为单独处理每一外圈的旋转，i表示左边界，j表示右边界，处理单个外圈时只要一次旋转上下左右的对应元素就行了，然后i++,j--,继续处理内层的圈，直到全部旋转完毕。




```

class Solution {
    public void rotate(int[][] matrix) {
        int i=0;
        int j=matrix.length-1;
        while(i<j){
            for(int k=0;k<j-i;k++){
                int temp=matrix[i][i+k];
                matrix[i][i+k]=matrix[j-k][i];
                matrix[j-k][i]=matrix[j][j-k];
                matrix[j][j-k]=matrix[i+k][j];
                matrix[i+k][j]=temp;
                
            }
            i++;
            j--;
        }
    }
}
```
