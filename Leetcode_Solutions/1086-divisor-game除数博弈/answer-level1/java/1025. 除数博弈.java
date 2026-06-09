```
class Solution {
    public boolean divisorGame(int N) {
        /*
            归纳：
            1. 首先确定获胜条件，第一个拿到2的人会赢，拿到1的人会输，所以爱丽丝只要保证拿到2就是必胜的。
            2. 任意一个数N，若N为奇数，满足条件的N的因数x也为奇数，N-x为偶数；若N为偶数，则N的因数x可以是奇数，
                也可以是偶数，N-x可以是奇数也可以是偶数。
            3. 玩家都以最佳状态参与游戏，故爱丽丝为奇数时，不论如何鲍勃都是偶数，鲍勃为偶数时，只要x=N-1即可，
                如此一来，爱丽丝拿到的永远是奇数，而鲍勃拿到的永远是偶数，爱丽丝必输；反之，爱丽丝是偶数时，爱丽丝必赢。
        */
        return N%2==0;

        /*  
            1. 建立结果数组dp[N+1]表示拿到1-N时对应的结果，爱丽丝拿到1必输，拿到2必胜；
            2. 初始化结果数组。当前数为i，初始化其为false，即默认爱丽丝失败，遍历1-i，如果其中存在i的因数j，
                并且dp[i-j]为false，说明爱丽丝可以选取该j为x，操作后得到i-j给鲍勃，则鲍勃输，此时当前i位置为true。
        */
        if(N == 1) return false;
        if(N == 2) return true;

        boolean[] dp = new boolean[N+1];
        dp[1] = false;
        dp[2] = true;

        for(int i = 3; i<=N; i++){
            dp[i] = false;
            for(int j = 1; j<i; j++){
                if(i % j == 0 && !dp[i - j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];

    }
}
```
