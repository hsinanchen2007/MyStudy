本题可以转变思路。想象成为爬楼梯的问题。即用最少的步数到达第amount层台阶。每一步你可以迈coins中的任何一个数。
我们可以用一个数组存放凑齐n元需要的最少硬币数。
```
class Solution {
    int count = Integer.MAX_VALUE;
    public int coinChange(int[] coins, int amount) {
        if(coins == null || coins.length == 0){
            return -1;
        }
        int[] state = new int[amount + 1];       
        for(int i = 0; i < state.length; i++){
            state[i] = Integer.MAX_VALUE;
        }
        state[0] = 0;
        for(int i = 0; i <= amount; i++){
            if(state[i] == Integer.MAX_VALUE) continue;
            for(int j = 0; j < coins.length; j++){
                if(i + coins[j] < state.length){
                    if(Integer.MAX_VALUE - i < coins[j]) continue;
                    state[i + coins[j]] = Math.min(state[i + coins[j]], state[i] + 1);
                }
            }
        }
        if(state[state.length - 1] == Integer.MAX_VALUE) return -1;
        return state[state.length - 1];
    }
}
```
