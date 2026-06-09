![批注 2020-03-15 225346.png](https://pic.leetcode-cn.com/f6472e98f6d1c36da926fc94365772bf244fab28c73a2697757e36eeccf1ce45-%E6%89%B9%E6%B3%A8%202020-03-15%20225346.png)

### 解题思路

1.首先遍历数组，以每一个为值1的数组位置作为根节点，利用深度优先搜索算法遍历其所在岛的面积，利用一个成员变量保存面积最大值。

2.真正的神来之笔是： grid[y][x] = 0; 简直是一行顶一万行，想了各种方法取避免重复计数导致越写越复杂，最后恍然大悟，个人的感触是编程千万不要在一条道上走到黑，感觉困难时一定要尝试切换思路。

3.最开始写，在ilandArea()方法中声明了很多成员变量导致执行效率不高，消耗资源也很多。最后去掉许多不必要的变量得到如下代码。

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res=0;
        for(int y=0; y<grid.length; y++){
            for(int x=0; x<grid[y].length; x++){
                if(grid[y][x] == 1)
                    res = Math.max(res, ilandArea(y, x, grid));
            }
        }
        return res;
    }

    public int ilandArea(int y, int x,int [][] grid){
        
        if(y<0 || x<0 || y >= grid.length || x >= grid[y].length || grid[y][x] == 0 ){
            return 0;
        }
        grid[y][x] = 0;                  //经典剖, 避免重复计数
        int sum = 1;
        sum += ilandArea(y-1, x, grid);  //上
        sum += ilandArea(y+1, x, grid);  //下
        sum += ilandArea(y, x-1, grid);  //左
        sum += ilandArea(y, x+1, grid);  //右
        return sum;
    }
}
```