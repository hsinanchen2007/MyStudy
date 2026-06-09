### 解题思路
1.方向数组的问题：因为从左上角开始走，所以只要遍历每一个坐标的右下方就可以完成对整个grid的遍历
2.计算位数之和 采用的是除10取余的方法
3.采用二维数组的必要在于记录已经遍历过的位置
![QQ截图20200408141013.png](https://pic.leetcode-cn.com/b71654e3d46a6a132a4e25205a2b2983e231d8396856fa91691e0378472ed4ff-QQ%E6%88%AA%E5%9B%BE20200408141013.png)
### 代码

```java
public class Solution {
    int [] dr = {1,0};
    int [] dc = {0,1};
    int count = 0 ;
    public int movingCount(int m, int n, int k) {
        //网格数组，用来记录已经到达过的坐标
        int [][] grid = new int[m][n];
        movingCount(grid,k,0,0);
        return count;
    }
    public void movingCount(int[][] grid,int k,int x ,int y ) {
        grid[y][x] = 1 ;
        count++;
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i <2 ; i++) {
            int xoff = dc[i], yoff = dr[i], nx = x + xoff, ny = y + yoff;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || numericalSum(nx) + numericalSum(ny) > k || grid[ny][nx] == 1) {
                continue;
            } else {
                movingCount(grid, k, nx, ny);
            }
        }
    }
    //计算位数之和
    public int numericalSum(int a){
        int sum = 0 ;
        while (a>=1){
            sum += a%10;
            a /= 10;
        }
        return sum;
    }
}

```