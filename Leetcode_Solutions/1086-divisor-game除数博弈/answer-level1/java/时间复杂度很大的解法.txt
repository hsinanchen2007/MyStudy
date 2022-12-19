```
class Solution {
    public boolean divisorGame(int N) {
        //如果初始数字N小于3，直接得结果，1和3爱丽丝输，2爱丽丝赢
        if(N == 1 || N == 3)
            return false;
        if(N == 2)
            return true;
        //设置动态规划数组dp
        boolean[] dp = new boolean[N + 1];
        //list将存放4到N的质数(包括1，如若数为4，将在list中存入1和2)
		List<Integer> list = new ArrayList<>();
		dp[1] = false;
		dp[2] = true;
		dp[3] = false;
        //循环将决定4之后所有的数在dp[i]中存的值
		for (int i = 4; i <= N; i++) {
            //求出i的素数
			for (int j = 1; j < i; j++) {
				if (i % j == 0) {
					list.add(j);
				}
			}
            //遍历list，查看dp的索引为i-num的值，如果存在dp[i - num] == false，那么dp[i] == true,且结束循环，否则dp[i] == false
			for (Integer num : list) {
				if(dp[i - num] == true)
					dp[i] = false;
				else{
					dp[i] = true;
					break;
				}
			}
			list.clear();
		}
		return dp[N];
    }
}
```
