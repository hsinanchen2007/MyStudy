1.如果使用递归做，那么必须列举出所有的路径，找到最小的路径和。
对于每个节点它可以向下移动或者向右移动
grid[i][j] 表示当前节点，得出递归公式如下：
```
grid[i][j]的步数和num = {
    grid[++i][j]的步数和num + grid[i][j] 向下走
or  grid[i][++j]的步数和num + grid[i][j] 向右走 
}
```
边界条件：
```
{
1.当j == grid[0].length - 1  只能往右走
2.当i == grid.length - 1 只能往下走
3.当同时满足1和2那么 递归结束 
}
```
代码如下：
```
class Solution {
    public int minPathSum(int[][] grid) {
        int i = 0;
        int j = 0;
        int min = method(grid, i, j);
        return min;
    }
    public int method(int[][] grid, int i, int j) {
        if(i == grid.length - 1 && j == grid[0].length - 1) {
            return grid[grid.length - 1][grid[0].length - 1];
        }
        int down = 0;
        int right = 0;
        if(j == grid[0].length - 1) {
            down = method(grid, ++i, j) + grid[--i][j];
            return down;
        } else if(i == grid.length - 1) {
            right =method(grid, i, ++j) + grid[i][--j];
            return right;
        }else {
            down = method(grid, ++i, j) + grid[--i][j];
            right = method(grid, i, ++j) + grid[i][--j];
        }
        return Math.min(down, right);
    }
}
```
2.分析存在大量重复计算：
表格如下：
0.0   0.1   0.2

1.0   1.1   1.2

2.0   2.1   2.2
递归所走的路程如下：
0.0——>1.0——>2.0——>2.1——>2.2
0.0——>1.0——>1.1——>2.1——>2.2
0.0——>1.0——>1.1——>1.2——>2.2
0.0——>0.1——>1.1——>2.1——>2.2
0.0——>0.0——>1.1——>1.2——>2.2
0.0——>0.1——>0.2——>1.2——>2.2

其中grid[2][1]就计算了三次

3.带备忘录的递归
```
class Solution {
    public int minPathSum(int[][] grid) {
        int i = 0;
        int j = 0;
        HashMap<String, Integer> hashMap = new HashMap<>();
        int min = method(grid, i, j, hashMap);
        return min;
    }
    public static int method(int[][] grid, int i, int j, HashMap<String, Integer> hashMap) {
        String key = i + "," + j;
        if (hashMap.containsKey(key)) {
            return hashMap.get(key);
        }

        if(i == grid.length - 1 && j == grid[0].length - 1) {
            int result = grid[grid.length - 1][grid[0].length - 1];
            hashMap.put(i + "," + j, result);
            return result;
        }
        int down = 0;
        int right = 0;
        if(j == grid[0].length - 1) {
            down = method(grid, ++i, j, hashMap) + grid[--i][j];
            hashMap.put(i + "," + j, down);
            return down;
        } else if(i == grid.length - 1) {
            right =method(grid, i, ++j, hashMap) + grid[i][--j];
            hashMap.put(i + "," + j, right);
            return right;
        }else {
            down = method(grid, ++i, j, hashMap) + grid[--i][j];
            right = method(grid, i, ++j, hashMap) + grid[i][--j];
        }
        int result = Math.min(down, right);
        hashMap.put(i + "," + j, result);
        return result;
    }
}
```
4.自下而上的动态规划
表格如下：
0.0 0.1 0.2
1.0 1.1 1.2
2.0 2.1 2.2

自下而上遍历出 每个节点到 最右下节点的最短路径和 
例子：
2.2——>2.1——>2.0——>1.2——>1.1——>1.0——>0.2——>0.1——>0.0
这里还做了一个优化：备忘录不用map做，用原来是二维数组即可。
```
public class Solution {
    public int minPathSum(int[][] grid) {
        for (int i = grid.length - 1; i >= 0; i--) {
            for (int j = grid[0].length - 1; j >= 0 ; j--) {
                if((i == grid.length - 1) && (j == grid[0].length - 1)) {
                    continue;
                }else if (i == grid.length - 1 ){
                    grid[i][j] = grid[i][j + 1] + grid[i][j];
                }else if(j == grid[0].length - 1) {
                    grid[i][j] = grid[i+1][j] + grid[i][j];
                }else {
                    grid[i][j] = Math.min(grid[i][j + 1], grid[i + 1][j]) + grid[i][j];
                }
            }
        }
        return grid[0][0];
    }
}

```

未完待续。。。。
