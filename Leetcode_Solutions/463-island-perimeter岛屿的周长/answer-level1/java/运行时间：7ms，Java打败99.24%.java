### 解题思路
该方法来源于提交者，具体是谁没有找到；我只是看懂了分享下思路。
![1.png](https://pic.leetcode-cn.com/cf37e5125d8189cbb392e5d66069b8333174c06f59b7bf460ad510a8692c27a8-1.png)
若给方格编号，则图中橙色的方块（即岛屿）分别是2-5-6-7-10-13-14,
当`grid[i][j]==1`时，统计oneCount，用于表示岛屿有多少个，
而`j<grid[i].length-1 && grid[i][j+1] == 1`，则是统计水平方向中重叠的边长个数`recount`，如方块5和6重叠，在周长中，该部分需要去掉，因而在结尾需减去`2 * recount`
同理在竖直方向`i<grid.length-1 && grid[i+1][j] == 1`，重叠的边长个数也需要减去`2 * recount`

思路清晰，并且简单，挺佩服这位提交者！！！
![2.png](https://pic.leetcode-cn.com/14fe8b25e317395374e5b1c582d330b2d7069388ee276ab8278f7ef5c342346c-2.png)


### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {int OneCount = 0;
        int reCount = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==1){
                    OneCount++;
                    if(j<grid[i].length-1 && grid[i][j+1] == 1){
                        reCount++;
                    }
                    if(i<grid.length-1 && grid[i+1][j] == 1 ){
                        reCount++;
                    }
                }
            }
        }
        return OneCount*4-2*reCount;
    }
}
```