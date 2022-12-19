1.如果用递归做,那么一条一条路径走，如果能走通则返回存储的路径。
对于每个节点，它可以往下走，也可以往右走。
obstacleGrid[i][j]表示机器人所在的节点。
得出递归公式：
```
obstacleGrid[i][j]能否到底目标的boolean == 
obstacleGrid[++i][j](往下走)能否到达目标的boolean || obstacleGrid[i][++j](往右走)能否到达目标的boolean
```
边界条件：
```
1.当j == obstacleGrid[0].length - 1  只能往下走
2.当i == obstacleGrid.length - 1 只能往右走
3.当同时满足1和2那么 递归结束，到达目的地
```
代码如下：
```
class Solution {
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        int i = 0;
        int j = 0;
        LinkedList<List<Integer>> arr = new LinkedList<>();
        System.out.println(method(obstacleGrid, i, j, arr));
        return arr;
    }
    public boolean method(int[][] obstacleGrid, int i, int j, LinkedList<List<Integer>> arr) {
        if(i > obstacleGrid.length - 1) {
            return false;
        }else if(j > obstacleGrid[0].length - 1) {
            return false;
        }
        if(obstacleGrid[i][j] == 1) {
            return false;
        }
        ArrayList<Integer> list = new ArrayList<>();
        list.add(i);
        list.add(j);
        arr.add(list);
        if(i == obstacleGrid.length - 1 && j == obstacleGrid[0].length - 1) {
            return true;
        }
        boolean b = method(obstacleGrid, ++i, j, arr);
        if (b) {
            return b;
        }
        boolean b1 = method(obstacleGrid, --i, ++j, arr);
        if(!b1) {
            arr.removeLast();
        }
        return b1;
    }
}
```
2.分析存在大量计算。
不存在最优子结构及重复子问题
3.动态规划
```
class Solution {
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        LinkedList<List<Integer>> arr = new LinkedList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        boolean flag = true;
        for (int i = 0, j = 0; i < obstacleGrid.length && j < obstacleGrid[0].length; i = flag ? ++i : i, j = !flag ? ++j : j) {
            if(obstacleGrid[0][0] == 1) {
                return arr;
            }
            map.put(i,j);
            if(obstacleGrid[i][j] == 1) {
                if(flag) {
                    if(j == obstacleGrid[0].length - 1) {
                        return new LinkedList<>();
                    }
                    --i;
                    flag = false;
                }else {
                    if(i == 0) {
                        return new LinkedList<>();
                    }
                    int k = j;
                    --i;
                    j = map.get(i);
                    for (int l = j; l < k; l++) {
                        obstacleGrid[i + 1][l] = 1;
                        arr.removeLast();
                    }
                }
            }else {
                flag = true;
                ArrayList<Integer> list = new ArrayList<>();
                list.add(i);
                list.add(j);
                arr.add(list);
            }
            if (i == obstacleGrid.length - 1) {
                flag = false;
            }
            if(j == obstacleGrid[0].length - 1) {
                flag = true;
            }
        }
        return arr;
    }
}
```

 