运行用时265ms,还需要优化。这是本笨比想出来的第二版，我觉得挺好理解

第一版是用的dfs，超时了。超时的原因就是重复搜索的次数太多，解决重复搜索的办法就是用dp去记录搜索结果。

这一版也有很大的可以优化的地方，时间有点紧张，日后再说

思路：先根据宽度从小到大排序，宽度相同的情况下，再根据高度从小到大排序。
得到的信封数组中，越后面的信封越大.
dp[i]表示第i个信封为可最大嵌套次数。
所以我们很容易得到，dp[dp.length-1]=1， 因为他是最大的，没有再能容纳他的信封了
那对于倒数第二个信封，只有倒数第一个信封，可能能容纳得了他。所以他的值，要么是1，要么是1+dp[dp.length-1]

······

对于更一般的情况，第i个信封，dp[i]的值，取决于什么呢？1.其他人都容纳不了他，则dp[i]=1。2.其他人能容纳得了他，在所有能容纳他的值里面取一个最大值作为dp[i]。
举例，假如已经求得dp[3]=2, dp[4]=1, dp[5]=1, 那么对于dp[2]，如果他能被3容纳，那dp[2]就可能是2+1=3,往后继续检查，他可能被4容纳，这时候1+1=2,是小于被3容纳的情况，所以仍然被3容纳；
到5，被5容纳的时候仍然小于被3容纳的情况，所以选择被3容纳，所以dp[2]=dp[3]+1

代码如下
````
class Solution {
    int max = 1;
    public int maxEnvelopes(int[][] envelopes) {
        if (envelopes == null)
            return 0;
        if (envelopes.length == 0)
            return 0;
        Arrays.sort(envelopes, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0])
                    return o2[1] - o1[1];
                return o1[0] - o2[0];
            }
        });
        int[] dp = new int[envelopes.length];
        dp[envelopes.length-1] = 1;
        //从尾向首倒推
        for(int i = envelopes.length-2 ; i >= 0;i--){
            cover(i,1,envelopes,dp);
        }
        return max;
    }
    public void cover(int cur,int sum,int[][] envelopes,int[] dp){
        dp[cur] = 1;
        int temp =1;
        for(int i = cur+1;i<envelopes.length;i++){
            if(envelopes[cur][0] < envelopes[i][0] &&envelopes[cur][1] < envelopes[i][1]){
                temp = Math.max(temp,dp[cur]+dp[i]);                
            }
        }
        dp[cur] = temp;  
        max = Math.max(max,dp[cur]);
    }
}
````