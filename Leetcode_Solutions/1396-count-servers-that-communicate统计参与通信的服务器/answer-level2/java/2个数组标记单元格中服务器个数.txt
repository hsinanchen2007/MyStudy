![OE4SQY(B4{3NXRUKZA7\[XPB.png](https://pic.leetcode-cn.com/2e38e585220d36e8a803f76f2824d3443d9404afb39eb51d9ad677a13600c81e-OE4SQY\(B4%7B3NXRUKZA7%5BXPB.png)
### 解题思路
我们采用x,y两个数组，x[i]表示在矩阵的第i行有多少台服务器，y[j]表示在矩阵的第j列有多少台服务器。
根据题意我们可以知道，如果grid[i][j] == 1那么x[i]和y[j]最少都是1.而且不会出现x[i]==1 y[j]==0或者x[i]==0 y[j]==1的情况。
假设grid[1][2] == 1 并且 x[1] == 1 y[2] == 2就代表着在grid[1][2]这一行只有他自己一台服务器，但是在grid[1][2]这一列，有包含这个服务器在内的2台服务器，
所以我们们将count++
明确了判断过程接下来我们需要做的就是首先建立x,y这两个标记数组。
随后遍历grid矩阵，如果grid[i][j] == 1，判断x[i]和y[j]有没有大于1的，因为grid[i][j]已经是1了，代表x[i]和y[i]的最小值是1.那么如果x[i]和y[i]中有任意一个大于了1，就代表grid[i][j]所在的列或行有其他服务器，那么我们执行count++
遍历完矩阵的所有元素之后输出count
### 代码

```java
class Solution {
    public int countServers(int[][] grid) {
        int []x = new int[grid.length];
        int []y = new int[grid[0].length];
        for(int i = 0;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
                if(grid[i][j] == 1){
                    x[i]++;
                    y[j]++;
                }
            }
        }
        int count = 0;
        for(int i = 0;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
                if(grid[i][j] == 1){
                    if(x[i] > 1 || y[j] > 1){
                        count++;
                    }
                }
            }
        }
        return count;
    }
}
```