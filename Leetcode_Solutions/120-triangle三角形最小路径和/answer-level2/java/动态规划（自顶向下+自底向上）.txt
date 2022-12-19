
动态转移方程就很简单：dp[i] = min(dp[i],dp[i-1])+curNum    
第一反应是使用自顶向下的动态规划，一维数组，问题是需要处理数组越界以及数据被覆盖问题
```
public int minimumTotal(List<List<Integer>> triangle) {
		int n = triangle.size();//三角形的总行数
		int[]dp=new int[n];
		int min = Integer.MAX_VALUE;
		for(int i=0;i<n;i++) {
			List<Integer>list = triangle.get(i);
			int pre = dp[0];//防止数据被覆盖
			for(int j=0;j<=i;j++) {
				int tmp = dp[j];//提前存一下数据
				if(j==0) {//处理边界问题
					dp[j] = dp[j]+list.get(j);
				}else if(j==i){
					dp[j] = pre+list.get(j);
				}else {
					dp[j] = Math.min(dp[j], pre)+list.get(j);
				}
				pre = tmp;
			}
		}
		for(int i=0;i<n;i++) {
			min = Math.min(min, dp[i]);
		}
		return min;
	}
```
然后我们再来看一下自底向上的动态规划，需要完全可以避免上面带来的两个麻烦的问题，代码也变得精简了许多。
动态转移方程：dp[i] = min(dp[i],dp[i+1])+curNum
```
//大神解法之自底向上的动态规划
	public int minimumTotal2(List<List<Integer>> triangle) {
		int n= triangle.size();
		int[]dp=new int[n];
		for(int i=0;i<n;i++)//初始化最后一行
			dp[i] = triangle.get(n-1).get(i);
		for(int i=n-2;i>=0;i--) {
			List<Integer> list=triangle.get(i);
			for(int j=0;j<=i;j++) {
				dp[j] = Math.min(dp[j], dp[j+1])+list.get(j);
			}
		}
		
		return dp[0];
	}
```
