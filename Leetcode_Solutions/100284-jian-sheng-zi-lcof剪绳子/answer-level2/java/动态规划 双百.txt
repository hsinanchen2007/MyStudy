class Solution {
    public int cuttingRope(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        int[] res = new int[n+1];
        res[2] = 2;
        res[3] = 3;
        for(int i = 4;i<=n;i++){
            for(int j = 2; 2*j<=i;j++){
                res[i] = Math.max(res[i],res[i-j]*res[j]);
            }
        }
        return res[n];
    }
}![捕获.PNG](https://pic.leetcode-cn.com/7fb1c51d133991751f2406425c8cd3f93e7e841ef895b8e8af96d761ed8e7c9b-%E6%8D%95%E8%8E%B7.PNG)
