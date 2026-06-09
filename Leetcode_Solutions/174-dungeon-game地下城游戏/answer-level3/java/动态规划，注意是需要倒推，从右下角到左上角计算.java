执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
95.74%
的用户
内存消耗 :
38.2 MB
, 在所有 Java 提交中击败了
60.43%
的用户
```
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int x = dungeon.length;
        if(x==0)return 0;
        int y = dungeon[0].length;
        int[][] res = new int[x][y];
        res[x-1][y-1]=Math.max(1,1-dungeon[x-1][y-1]);
        for(int j=y-2; j>=0;j--){
            res[x-1][j]=Math.max(1,res[x-1][j+1]-dungeon[x-1][j]);
        }
        for(int i=x-2; i>=0;i--){
            res[i][y-1]=Math.max(1,res[i+1][y-1]-dungeon[i][y-1]);
        }
        for(int i=x-2; i>=0;i-- ){
            for(int j=y-2;j>=0;j--){
                 res[i][j]=Math.max(1,Math.min(res[i+1][j],res[i][j+1])-dungeon[i][j]);
            }
        }
        return res[0][0];
    }
}
```
