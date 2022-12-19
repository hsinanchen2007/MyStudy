```java
class Solution {
    private int[][] dp;
    public boolean splitArraySameAverage(int[] A) {
        int sum = 0;
        for(int i=0;i<A.length;i++)
            sum += A[i];
        dp = new int[sum+1][A.length+1];
        return avg(A, 0, 0, 0, sum);
    }
    private boolean avg(int[]A, int left, int llen, int start, int sum){
        if(dp[left][llen] != 0)
            return dp[left][llen] == 1;
        int right = sum - left;
        int rlen = A.length - llen;
        if(start == A.length){
            boolean flag = left*rlen == right*llen && llen != 0 && rlen != 0;
            if(flag){
                dp[left][llen] = 1;
            }else{
                dp[left][llen] = -1;
            }
            return flag;
        }
        boolean ret = avg(A,left+A[start],llen+1,start+1,sum) || avg(A,left,llen,start + 1,sum);
        if(ret)
            dp[left][llen] = 1;
        else
            dp[left][llen] = -1;
        return ret;
    }
}
```