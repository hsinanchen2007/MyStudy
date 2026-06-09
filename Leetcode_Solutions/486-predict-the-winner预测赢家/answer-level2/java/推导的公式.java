java

先手A，后手B， sum是分数总和，sumA是A的最优解的分数，sumB是B的最优解的分数
结果就是 sumA >= sum - sumB

思路1：暴力破解 超时
A先拿一个最优解，B要从剩下的里面找个最优的一个拿，然后依次循环

思路2：这个用120ms, 
数组下标1开始，f(1-2) 指的是算出 下标1到2的子数组的最优解， sum(1-2) 是指下标1到2的子数组的合

f(1)=n1
f(1-2)=max(n1,n2)=sum(1-2)  -  min(n1,n2)
f(1-3)=max(n1 + min(n2,n3), n3 + min(n1,n2))
      =max(n1 + sum(2-3) - f(2-3), n3 + sum(1-2) - f(1-2))
	  =max(sum(1-3) - f(2-3), sum(1-3) - f(1-2))

思路3：这个用17ms, 但依然只击败了 20%
在2的基础上去掉重复计算
用一个Map 存计算过的子数组

思路4：将map 换成数组 0ms

大家可以先不要看代码，看公式 写一下，我觉得还是比较好理解的

```
      long [] bp;
	public boolean PredictTheWinner(int[] nums) {
		bp = new long[nums.length*nums.length];
		long sum = 0;
		for(int i=0; i<nums.length; i++) {
			sum += nums[i];
		}
		
		long sum1 = PredictTheWinner(nums, 1, nums.length-1, sum-nums[0]);
		long sum2 = PredictTheWinner(nums, 0, nums.length-2, sum-nums[nums.length-1]);
		long play1 = Math.max(sum-sum1, sum-sum2);
		return play1 >= sum - play1 ;
     }
	public long PredictTheWinner(int[] nums, int start, int end, long sum) {
		if (start>end) return 0;
		if (start==end) return nums[start];
		if (end-start==1) return Math.max(sum-nums[start], sum-nums[end]);
		int key = start*nums.length+end;
		if (bp[key]>0) {
			return bp[key];
		}
		long sum1 = PredictTheWinner(nums, start+1, end, sum-nums[start]);		
		long sum2 = PredictTheWinner(nums, start, end-1, sum-nums[end]);
		long max = Math.max(sum-sum1, sum-sum2);
		bp[key] = max;
		return max;
	}
```
