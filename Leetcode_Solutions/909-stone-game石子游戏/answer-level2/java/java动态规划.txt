虽然直接return true 能通过，但是其实是不正确的 ,只是因为用例不够全面而已，比如 [1,10,2]时就应该返回false 这题可以使用动态规划来做，用d[i][j]表示从i到j这一段数组，先手的人比后手的人能多多少（负数表示少的最少情况） 可以看出d[i][j]=max(piles[i]-d[i+1][j],piles[j]-d[i][j-1] 表示当前选手选左右两端时的值要相应减去，对手先手的最好情况，代码如下：
```
class Solution {
    public boolean stoneGame(int[] piles) {
        int  [][]d=new int[piles.length][piles.length];
        //用d[i][j]表示先手能赢多少,小于0表示必输，大于0表示能赢
        for(int i=0;i<piles.length;i++){
            for(int j=0;j<piles.length-i;j++){
                if(i==0){
                    d[j][j]=piles[j];
                }else{
                    d[j][j+i]=Math.max(piles[j]-d[j+1][j+i],piles[j+i]-d[j][j+i-1]);
                }
            }
        }
        if(d[0][piles.length-1]<0){
            return false;
        }else{
            return true;
        }
    }
}
```
