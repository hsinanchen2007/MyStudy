先找出来比n小的所有完全平方数
然后把这些数字的dp值设为1（因为自己组成自己）
从1开始数到n
第i个数分别减去比自己小的完全平方数得到i-x。找出dp[i-x]中最小的dp值
**dp[i]=min(dp[i-x])+1**

```
class Solution {
    public int numSquares(int n) {
        //记录每个数是被几个完全平方数相加得到的。（就是对它来说的最小组成，当大一点的数用到这个数的时候可以直接使用）
        //对于第i个数来说。i依次减去比它小的完全平方数，得到i-x
        //从这些dp[i-x]中使用最小的那个值+1即为dp[i]的值
        //首先找出比n小的那些完全平方数
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n>1&&n<4)
            return n;
        
        int point =1;
        List<Integer> all=new ArrayList();
        while((point*point)<=n){
            int temp=point*point;
            all.add(temp);
            point++;
        }
        int []dp=new int[n+1];//从1找到n
        for(int i=0;i<all.size();i++){//将这些完全平方数自己的组成元素数目设为1
            dp[all.get(i)]=1;
        }
        for(int i=1;i<=n;i++){
            int min=Integer.MAX_VALUE;
            for(int j=0;j<all.size();j++){//遍历减去这些完全平方数得到i-x
                if(i-all.get(j)>=0){
                if(dp[i-all.get(j)]<min)
                    min=dp[i-all.get(j)];
            }
                else
                    break;
            }
            dp[i]=min+1;
        }
        return dp[n];
    }
}
```
