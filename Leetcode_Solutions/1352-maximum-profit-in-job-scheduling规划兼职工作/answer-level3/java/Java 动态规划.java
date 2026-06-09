### 解题思路
序列型dp
**dp[i]表示到第i个所能赚到的最大金钱**
**建立一个类保存工作的startTime,endTime,profit**
根据endTime从小到大排序
转移:
**if(job[j].end<=job[i].start)    dp[i]=Math.max(dp[i],dp[j]+job[i].profit);
没有的话,dp[i]=Math.max(dp[i-1],job[i].profit);  第i个选择第i-1个的状态或选择自己单独一个**
### 代码

```java
class jobs{
    int start,end,profit;
    jobs(int s,int e,int p){
        start=s;
        end=e;
        profit=p;
    }
}
class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n=startTime.length;
        int dp[]=new int[n+1];
        jobs[] job=new jobs[n];
        for(int i=0;i<n;i++)
            job[i]=new jobs(startTime[i],endTime[i],profit[i]);
        Arrays.sort(job,Comparator.comparingInt(o->o.end));
        for(int i=0;i<n;i++)
            dp[i]=job[i].profit;
        for(int i=1;i<n;i++){
            dp[i] = Math.max(dp[i-1], job[i].profit);
            for(int j=i-1;j>=0;j--)
                if(job[j].end<=job[i].start){
                    dp[i]=Math.max(dp[i],dp[j]+job[i].profit);
                    break;
                }
        }
        return dp[n-1];
    }
}
```