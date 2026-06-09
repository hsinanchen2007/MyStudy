```
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
        // 如果所有整数的总和都小于总目标，则先手者不可能赢
        if (maxChoosableInteger * (maxChoosableInteger+1) / 2 < desiredTotal)
            return false;
        
        // 如果总目标不超过最大整数，则先手者可通过直接选择desiredTotal而一步取胜
        if (desiredTotal == 0 || maxChoosableInteger >= desiredTotal)
            return true;
        
        // 备忘录：所有整数的被选择情况，共有2 ** maxChoosableInteger种
        // 由于最多有20个整数，故最大值为2 ** 20 < 2000000
        // 这提示我们可以用数组来存储在每种整数的被选择情况下，先手者是否能取胜
        // 每种选择情况，都可以用一个整数来表示，其二进制的倒数第i位标志着i是否已被选走
        // 例如: stat = 2 = 010 表示共3个数，其中2已被取走，1和3还未被取走
        // dp[stat]表示，在stat的情况下，先手方是否能赢：0-未知待求解，1-先手方赢，2-后手方赢
        int dp[1 << maxChoosableInteger] = {0};
        return recursive(maxChoosableInteger, 0, desiredTotal, dp);
    }
    
    bool recursive(int n, int stat, int target, int dp[]){
        //如果该种情况已经被求解过，则直接查表即可
        if (dp[stat] != 0)
            return dp[stat] == 1;
        
        bool res = false;
        // 在递归中，可以保证target一定是大于0的，此时整数池中一定还有可待选取的整数
        // 先手方应从中选取一个整数
        for (int i=n; i>0; i--){
            int cur = 1 << (i-1);
            // 这个括号必须要加，因为在c++中，位运算的优先级是高于算术运算的
            // 如果i已被选走，则跳过
            if ((stat & cur) != 0)
                continue;
            // 如果i>=target，则可一步成功
            // 否则，选取i之后再递归调用，如果对于选取i之后的情况，先手方必输，则此步的先手方选i必胜
            if (i >= target || !recursive(n, stat | cur, target - i, dp)){
                res = true;
                break;
            }
        }
        
        // 记录子问题的解
        dp[stat] = res ? 1:2;
        return res;
    }

};
```
