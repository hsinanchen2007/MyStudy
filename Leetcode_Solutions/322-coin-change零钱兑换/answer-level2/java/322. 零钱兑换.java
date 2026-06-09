### 解法一 dfs深度遍历+剪枝回溯
1. 要想用硬币的数量最少，所以硬币的额度高的数量要尽可能的多。
2. 我们将硬币额度排序，从最大的开始遍历，使用大额的金币先进一步填充兑换，然后余额用小点的金币兑换。
```
class Solution {
    private int minCount=-1;
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        return dfs(coins.length-1,amount,coins,0);
    }
    /**
    * index 下标，排序后硬币的位置，从大到小遍历
    * balance  前面兑换完之后的余额
    * int[] coins
    * count 已使用的硬币数量
    **/
    private int dfs(int index,int balance,int[] coins,int count){
        if(index<0) return -1;//已经遍历到最小的硬币了，无法组成总金额
        int currentDenomination=coins[index];//当前硬币的面额
        //计算当前余额用当前面额的硬币能换多少个
        int currentCount=balance/currentDenomination;
        //如果发现数量已经超过了前面符合要求的数量，那么不需要继续遍历了,肯定不是硬币数量最少的情况
        if(minCount!=-1 && count+currentCount>minCount) return -1;
        int currentBalance=balance%currentDenomination;//最大兑换完之后还余多少
        if(currentBalance==0) return currentCount+count;//余额为0，说明正好兑换完，则返回。
        for(int i=currentCount;i>=0;i--){//从最大数量开始兑换，余额用更小的硬币换
            int resultCount=dfs(index-1,balance-currentDenomination*i,coins,count+i);
            if(minCount==-1){
                //还没有记录过的情况，直接更新
                minCount=resultCount;
            }else if(resultCount!=-1){
                //取两者最小的
                minCount=Math.min(minCount,resultCount);
            }
        }
        return minCount;
    }
}
从评论区看到的思路是跟我一样的，但是他的代码极度精简，思路更清晰，效率也更高,太牛叉了
class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        recursion(coins, amount, 0, coins.length - 1);
        return minCount == Integer.MAX_VALUE ? -1 : minCount;
    }
    int minCount = Integer.MAX_VALUE;
    /**
     * 1、按金额从大到小，从多到少（排序，用余数一步到位）
     * 2、预判低于最优解，终止递归（可以返回最优解，不过提升有限，意义不大）
     * 3、能整除即可返回
     */
    void recursion(int[] coins, int amount, int count, int index) {
        if (index < 0 || count + amount / coins[index] >= minCount) return;
        if (amount % coins[index] == 0) {
            minCount = Math.min(minCount, count + amount / coins[index]);
            return;
        }
        for (int i = amount / coins[index]; i >= 0; i--) {
            recursion(coins, amount - i * coins[index], count + i, index - 1);
        }
    }
}
```
### 解法二 动态规划
有两种方式，一种是从1~amount来计算，还有一种是从amount~1来计算。
1. 对于要凑到amount金额的最少硬币数量，可以从凑amount-a的最少硬币数量，然后+1得到.
2. a是指coins里面的某个硬币的面额，如果没有符合的则说明不能凑到总金额。
3. 动态状态方程dp[i]=min{dp[i-coins[j]]}+1;
4. dp[i]是指凑成总金额i所需的最少硬币个数.dp[i-coins[j}]是指(金额i-某个硬币的面额)得到新的总金额所需的最少硬币个数，取个数最少的再加1就得到了总金额i所需的最少硬币个数
```
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] minCoins=new int[amount+1];//下标为需要凑成的金额，值为最少的硬币数量
        minCoins[0]=0;//总金额为0，需要0个硬币
        for(int i=1;i<=amount;i++){
            //从1开始到amount金额，依次算出每个金额所需的最少硬币个数
            int minCurrentcoins=-1;//假设要获取i金额，最少需要
            for(int coin:coins){
                //遍历所有可能的硬币.说明只有硬币面额小于总金额，才能凑，硬币面额就比总金额大，那无法兑换
                //i-coin<0，说明当前coin硬币的面额大于总金额，不符合条件，我们需要找比总金额小的硬币，这才能组合。
                //minCoins[i-coin]说明i-coin总金额无法凑成，则这个情况也不符合。
                if(i-coin<0 || minCoins[i-coin]==-1){
                    continue;
                }
                //minCoins[i-coin]，表示获取要凑成总金额i-coin所需要的最少硬币数量，那么再加1个当前coin硬币，就是凑成i金额所需最少的硬币个数.而i-coin肯定是小于i的，这个已经在前面获取到过
                if(minCurrentcoins==-1){
                    //找到的第一种可能
                    minCurrentcoins=minCoins[i-coin];
                }else{
                    //如果当前情况硬币个数要小，则替换更少的.
                    minCurrentcoins=Math.min(minCurrentcoins,minCoins[i-coin]);
                }
            }
            //更新存储凑总金额i所需要的最少硬币个数
            //因为minCurrentCoints是凑成总金额i-coin的最少硬币数字，则要凑到总金额i，需要加上一个coin才能凑成
            if(minCurrentcoins==-1){//-1说明没有无法凑成金额i
                minCoins[i]=-1;
            }else{
                minCoins[i]=minCurrentcoins+1;
            }
            
        }
        return minCoins[amount];
    }
}
官方解法，代码比我这个精简多了。。。。
class Solution {
    public int coinChange(int[] coins, int amount) {
        //1.对于要凑到amount金额的最少硬币数量，可以从凑amount-a的最少硬币数量，然后+1得到，
        //2.a是指coins里面的每个硬币的面额，如果没有符合的则说明不能凑到总金额。
        int max=amount+1;
        int[] minCoins=new int[max];//下标为需要凑成的金额，值为最少的硬币数量
        Arrays.fill(minCoins,max);//将个数设置为不可能的个数，因为硬币面额最小是1，那么要凑成总金额amount最多也就是amount个。
        minCoins[0]=0;
        for(int i=1;i<=amount;i++){//i，代表总金额
            for(int coin:coins){
                if(i>=coin){//硬币面额小于总金额，所以可以用于凑总金额
                    minCoins[i]=Math.min(minCoins[i],minCoins[i-coin]+1);
                }
            }
        }
        return minCoins[amount]==max? -1 : minCoins[amount];
    }
}
```

