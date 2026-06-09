### 解题思路
1. 定义八个方向
2. 循环这八个方向寻找
3. 找到第一个黑皇后就返回，或者达到边界就返回
4. 返回结果

### 代码

```java
class Solution {
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if(queens.length == 0 || king.length == 0){
            return list;
        }

        int[][] direction = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
        for(int i = 0; i < direction.length; i++){
            int[] pos = findBlackWife(queens, king, direction[i], 8);
            if(pos[0] != -1){
                List<Integer> onePos = new ArrayList<Integer>();
                onePos.add(pos[0]);
                onePos.add(pos[1]);
                list.add(onePos);
            }
        }
        return list;
    }

    private int[] findBlackWife(int[][] queens, int[] king, int[] direct, int length) {
        int[] pos = new int[] {king[0] + direct[0], king[1] + direct[1]};
        while (pos[0] >= 0 && pos[0] < length && pos[1] >= 0 && pos[1] < length){
            if(isFind(queens, pos)){
                return pos;
            }
            pos[0] += direct[0];
            pos[1] += direct[1];
        }
        return new int[] {-1, -1};
    }

    private boolean isFind(int[][] queens, int[] pos) {
        for(int i = 0; i < queens.length; i++){
            if(queens[i][0] == pos[0] && queens[i][1] == pos[1]){
                return true;
            }
        }

        return false;
    }
}
```