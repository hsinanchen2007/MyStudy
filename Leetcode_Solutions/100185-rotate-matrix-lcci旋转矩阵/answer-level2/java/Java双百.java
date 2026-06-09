### 解题思路
关键在于把握矩阵旋转坐标变换的规律
因为题目说的不要额外的空间，那必然是需要找到一个坐标交换前和交换后的关系
然后利用这个关系完成矩阵的转换
说白了这道题考的是数学
我在草稿本上画了画就发现实际上旋转就是矩阵经过两次运算：
    第一次是沿对角线交换
    第二次是沿列的中线交换
就实现了原地转换

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int temp=0;
        int len=matrix.length;
        if(len==0||len==1)
            return;
        for(int k=0;k<len;k++)
            for(int j = k;j<len;j++){
                int i=j-k;
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        double mid=Math.floor(len/2);
            for(int i=0;i<len;i++)
                for(int j=0;j<mid;j++) {
                    temp=matrix[i][j];
                    matrix[i][j]=matrix[i][len-j-1];
                    matrix[i][len-j-1]=temp;
                }

    }
}
```