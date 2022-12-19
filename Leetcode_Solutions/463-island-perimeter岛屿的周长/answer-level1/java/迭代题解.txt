### 解题思路
采用迭代的方式，第一次迭代遍历每个方格，将方格的总长度计算出，行中左右相邻的方格需要减去重叠部分，此时的总长度必定大于真正的周长。随后便将列中上下相邻的方格减去重叠部分，迭代结束后得到周长。

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {

        List<Boolean> list = new ArrayList<Boolean>(grid[0].length);
        for(int i = 0; i < grid[0].length; i++) {
            list.add(false);
        }
        int length = 0;
        for(int[] subGrid : grid) {
            int prev = 0;
            for(int i = 0; i < subGrid.length; i++) {
                if (subGrid[i] == 1) {
                    if (prev == 0) {
                        length += 4;
                        prev = 1;
                    } else {
                        length += 2;
                    }

                    if (list.get(i)) {
                        length -= 2;
                    }
                    list.set(i, true);
  
                } else {
                    prev = 0;
                    list.set(i, false);
                }
            }
        }

        return length;
        
    }
}
```