```
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        //终点位置如果大于0则设为0，反之不改变
        //因为这个值可以理解为终点是加血还是掉血，骑士只要能活着到终点就行，不需要在意他的血量，所以t>0是无效的
        dungeon[dungeon.length-1][dungeon[0].length-1]=
            dungeon[dungeon.length-1][dungeon[0].length-1]>0?0:dungeon[dungeon.length-1][dungeon[0].length-1];
        //最后一列初始化
        //从倒数第二行开始，t记录其值与它下一行的值之和
        //t>0则清0,反之不变
        // 因为这个t可以理解为从该位置向终点走，是加血还是掉血，如果你人死了，就算加再多的血也不会复活，所以t>0是无效的
        //将t赋给dungeon
        for(int i=dungeon.length-2;i>=0;i--){
            int t=dungeon[i][dungeon[0].length-1]+dungeon[i+1][dungeon[0].length-1];
            dungeon[i][dungeon[0].length-1]=t>0?0:t;
        }
        //最后一行初始化，同最后一列初始化
        for(int i=dungeon[0].length-2;i>=0;i--){
            int t=dungeon[dungeon.length-1][i]+dungeon[dungeon.length-1][i+1];
            dungeon[dungeon.length-1][i]=t>0?0:t;
        }
        //以上为初始化
        //从倒数第二行的倒数第二列开始，一行一行向左遍历数组
        //因为只能走两个方向，所以利用贪心算法，挑减血少的路走
        //规则和初始化一样，t>0清空
        for(int i=dungeon.length-2;i>=0;i--)
            for(int j=dungeon[0].length-2;j>=0;j--){
                int t=dungeon[i][j]+Math.max(dungeon[i+1][j],dungeon[i][j+1]);
                dungeon[i][j]=t>0?0:t;
            }
        //最终答案
        //位置0,0如果该位置的值大于等于0,只需要确保刚开始活着就行了，最优路是加血的，返回1
        //反之，这个负数代表到达终点最小要减的血量，只需确保刚开始的血量大于这个值即可
        return 1-dungeon[0][0];
    }
}
```
