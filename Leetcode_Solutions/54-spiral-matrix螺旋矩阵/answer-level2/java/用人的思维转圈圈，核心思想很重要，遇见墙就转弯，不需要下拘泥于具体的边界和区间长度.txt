核心思想下一个节点访问只跟当前节点位置有关系
```
class Solution {
    boolean[][] visted;

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<Integer>();
        if (matrix == null || matrix.length == 0)
            return list;
        int count = 0;
        //核心思想下一个状态只跟上一个节点有关系
        int[] initPosition = new int[]{0, 1};
        visted = new boolean[matrix.length][matrix[0].length];
        int x = 0, y = 0;
        while (count != matrix.length * matrix[0].length) {
            //当前节点已经到需要转变方向的转折点，进行方向变更
            if (isBoundary(x + initPosition[0], y + initPosition[1])) {
                list.add(matrix[x][y]);
                //转弯，下一个方向
                initPosition = position(initPosition);
                visted[x][y] = true;
                x = x + initPosition[0];
                y = y + initPosition[1];
                count++;
            } else {
                list.add(matrix[x][y]);
                visted[x][y] = true;
                x = x + initPosition[0];
                y = y + initPosition[1];
                count++;
            }
        }
        return list;
    }
     //方向转移，右(0,1)--->下(1,0)---->左(0,-1)----->上(-1,0)-----右(0,1)
    public int[] position(int[] currentposition) {
        if (currentposition[0] == 0 && currentposition[1] == 1)
            return new int[]{1, 0};
        if (currentposition[0] == 1 && currentposition[1] == 0)
            return new int[]{0, -1};
        if (currentposition[0] == 0 && currentposition[1] == -1)
            return new int[]{-1, 0};
        if (currentposition[0] == -1 && currentposition[1] == 0)
            return new int[]{0, 1};
        return new int[]{0, 0};
    }

    //如何判断需要下一个状态机，一旦当前元素遇见边界或者遇见访问过的元素，需要转移到下一个方向
    public boolean isBoundary(int x, int y) {
        if (x < 0 || x >= visted.length || y < 0 || y >= visted[0].length || visted[x][y])
            return true;
        else
            return false;
    }
}
```
