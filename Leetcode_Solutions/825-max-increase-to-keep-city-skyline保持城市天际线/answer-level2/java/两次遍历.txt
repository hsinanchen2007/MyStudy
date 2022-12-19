    题目意思嘛，从顶部和从底部看阴影是一样的，因为都是只能看见最高的那一个啊。同理，左右也是一样的。
    那么，我们就可以找到每一行每一列的最大值，然后遍历数组，加上它们和*最大值里的较小值的差值*就可以了。这里要注意理解这个*最大值里的较小值*，打个比方，第i行最大值是10，第j列最大值是7，那么一定有**grid[i][j] <= 7**。
    所以我们首先通过一次遍历找到每一行，每一列的最大值，然后加上这个较小值就好了。

### 代码

```java
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] corw = new int[grid.length];//行的最大值
        int[] line = new int[grid[0].length];//列的最大值
        int sum = 0;//结果和
        for (int i = 0;i < grid.length;i++){
            for (int j = 0;j < grid[i].length;j++){
                if (corw[i] < grid[i][j]){//找出行最大值
                    corw[i] = grid[i][j];
                }
                if (line[i] < grid[j][i]){//找出列最大值
                    line[i] = grid[j][i];
                }
            }
        }
        for (int i = 0;i < grid.length;i++){
            for (int j = 0;j < grid[i].length;j++){
                sum += Math.min(corw[i],line[j]) - grid[i][j];//计算结果和
            }
        }
        return sum;
    }
}
```