### 解题思路
题目要求有比较好的三维空间思维，如果能力不强还是老实画图吧。
有几个比较关键的点。
1. 立方体的总表面积等于4n - 2；因为上下都有重合的地方所以还需要减掉重复面积，至于为什么是4n-2，纸上画一下就好。
2. 从左到右，减去和右侧相邻柱子重合的面积（左侧为原点不需要减，或者已经被上一个柱子减掉了，无需再算）
    重合的面积等于矮的那一边的高度*1*2（两面）。
3. 从下到上，减去和上方相邻的柱子重合面积（下方为原点也不需要减，或者已经被减掉，同上）
    重合的面积也同上，也是两面。
4. 最终返回结果。
### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid[i].length; j++){
                int v = grid[i][j];
                if (v > 0){
                    res += (4*v)+2;
                    //减去右侧重合高度
                    if (i+1 < grid.length){ //右侧有柱子才需要减面积
                        int right = grid[i+1][j];//右侧柱子高度
                        if (right>v){
                            res -= v*2;
                        }else{
                            res -= right*2;
                        }
                    }

                    //减去顶部重合高度 
                    if (j+1 < grid[i].length){ //上方有柱子才需要减面积
                        int top = grid[i][j+1];//上方柱子高度
                        if (top > v){
                            res -= v*2;
                        }else{
                            res -= top*2;
                        }
                    }
                }
            }
        }
        return res;
    }
}
```