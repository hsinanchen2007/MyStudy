
典型的递归题目,这里写下递归关系和动态规划优化

思路1:
    1. 递归关系, 当前结点的最小路径值 等于上一步(有两种可能,上或者左)的最小值+当前结点的值
    2. 动态规划优化, 由于在递归过程中, 某些路径会被重复用到, 如果重复计算不是很必要, 这里可以定义一个m*n的数组,
用于存储路径的每一个结点的最小路径, 当第一次计算的时候需要填值, 第二次就直接取值使用就好了

思路2:
    1. 这里不是使用递归, 而是使用循环, 把距离左上结点的距离作为循环条件, 每层循环更新距离左上角相同距离的结点最小路径
    2. 这里距离作为条件, 一定是从最小到最大, 这样就把上一步的最短路径作为当前结点计算的根据

这里用的思路2, 另外有个坑, 我带注释去提交 30% 5ms 不带注释87% 3ms,这区别挺大啊!!

```
public int minPathSum(int[][] grid) {
        if (grid.length == 0) {
            return 0;
        }
        int distance = 0;
        int maxDistance = grid[0].length+grid.length-2;

        // 定义当前结点的坐标, x表示内层数组的索引,
        // y表示外层数组的索引(其实无所谓, 都一样, 但是抽象的越具体思考起来越简单)
        // x表示距离左上结点的横向距离, y表示距离左上结点的纵向距离
        int x = 0, y = 0;
        // 定义x,y坐标的最大值, 防止越界,可能会用不到
        int maxX = grid[0].length-1, maxY = grid.length-1;
        // 定义上和左结点的最小值
        int topMin = 0, leftMin = 0;
        while (++distance <= maxDistance) {
            // 这里就是表示距离左上结点的某个距离一层最小距离的获取
            for (x = distance;x >= 0; x--) {
                y = distance-x;
                // 表示x或者y越界, 此时直接continue
                if (x > maxX || y > maxY){
                    continue;
                }
                // 这里表示如果当前结点是上或者左边界则通过上或左无法到达, 也就是取最大值
                topMin = (y-1 >= 0 ? grid[y-1][x] : Integer.MAX_VALUE);
                leftMin = (x-1 >= 0 ? grid[y][x-1] : Integer.MAX_VALUE);
                // 取左和上结点中最小的路径值
                grid[y][x] += topMin < leftMin ? topMin : leftMin;
            }
        }

        return grid[maxY][maxX];
    }
```
