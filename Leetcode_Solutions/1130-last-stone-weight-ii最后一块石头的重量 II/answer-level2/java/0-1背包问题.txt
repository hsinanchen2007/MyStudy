问题可以转化成背包大小为石头总重量的一半，最多可以装多重的石头，能想到这里就很简单了。
```
class Solution {
    public int lastStoneWeightII(int[] stones) {
        int n = stones.length;
        int sum = 0;
        for(int stone:stones){
            sum += stone;
        }
        int[] dp = new int[(sum >> 1) + 1];
        for(int stone:stones){
            zeroOnePack(dp, stone, stone);
        }
        return sum - (dp[(sum >> 1)] << 1);
    }
    
    private void zeroOnePack(int[] dp, int cost, int val){
        for(int i = dp.length - 1; i >= cost; i--){
            dp[i] = Math.max(dp[i], dp[i - cost] + val);
        }
    }
}
```
