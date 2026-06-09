### 解题思路
这个题目感觉和力扣上面有个水果感染的问题很像，按照类似的处理方法，1当做坏水果，0当做好水果，每天坏水果可以将周围的好水果感染，计算多少天可以将全部的水果都感染。没了。。。

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
if(grid == null || grid.length == 0)
            return -1;
        int ocan = 0;
        int index = -1;
        boolean[][] flag = new boolean[grid.length][grid.length];
        while(true){
            ocan = 0;
            index++;
            for(int i=0; i<grid.length; i++)
                for (int j = 0; j < grid.length; j++) {
                    if(grid[i][j] == 0)
                        continue;
                    else if (grid[i][j] == 1 && flag[i][j] != false)
                        continue;
                    else {
                        //将上下左右进行传染
                        if (i - 1 >= 0 && grid[i - 1][j] == 0) {
                            ocan++;
                            grid[i - 1][j] = 1;
                            flag[i - 1][j] = true;
                        }
                        if (i + 1 < grid.length && grid[i + 1][j] == 0) {
                            ocan++;
                            grid[i + 1][j] = 1;
                            flag[i + 1][j] = true;
                        }
                        if (j - 1 >= 0 && grid[i][j - 1] == 0) {
                            ocan++;
                            grid[i][j - 1] = 1;
                            flag[i][j - 1] = true;
                        }
                        if (j + 1 < grid.length && grid[i][j + 1] == 0) {
                            ocan++;
                            grid[i][j + 1] = 1;
                            flag[i][j + 1] = true;
                        }
                    }
                }
            //下一轮又可以重新传染
            for(boolean[] item:flag)
                Arrays.fill(item, false);
            if(ocan == 0)
                break;
        }
        return index == 0 ? -1 : index;
    }
}
```