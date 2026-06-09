# 变量解释
1. dp[i][j][0]/dp[i][j][1]数组表示 石子堆从第i个开始到第j个结束时，先手和后手分别能拿最多拿到多少个石头
2. getRight:先手在此状态下，若先拿右边石头的收益；
3. getLeft:先手在此状态下，若先拿左边石头的收益；


# 步骤解释
1. 确定dp数组的含义（一般地，组合博弈的动态规划题目，可以多加一个维度用【0】【1】，表示两个人的收益）
2. 确定dp初始值。二维dp问题，所以初始值不是一个值或两个值，而是一排值，且为一个斜线。即，数组只有0号，1号……时的收益
3. 从dp[0][1]开始进行推演，若先手取左边，则其收益为：仅有 左边元素时先手的收益+去掉左边元素后后手的收益
4. 若先手取右，同理
5. 最后判断数组最后一位，先后手谁大谁小


```
class Solution {
    public boolean stoneGame(int[] piles) {
        int length = piles.length;
        int[][][] dp = new int[length][length][2];
        
        for(int i=0;i<length;i++)
        {
            dp[i][i][0] = piles[i];
            dp[i][i][1] = 0;
        }
        
        for(int i=0;i<length-1;i++)
        {
            for(int k=1; k<length; k++)
            {
                int getRight = dp[i][k-1][1]+dp[k][k][0];
                int getLeft = dp[i+1][k][1]+dp[i][i][0];
                
                if(getLeft>getRight)
                {
                    dp[i][k][0] = getLeft;
                    dp[i][k][1] = dp[i+1][k][0];
                }
                else
                {
                    dp[i][k][0] = getRight;
                    dp[i][k][1] = dp[i][k-1][0];                    
                }
            }
        }
        
        return (dp[length-1][length-1][0] - dp[length-1][length-1][1] > 0);
    }
}
```


祝自己明天比赛好运啦~~
