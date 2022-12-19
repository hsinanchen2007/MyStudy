### 解题思路

	我看到这题的时候，想法就是要先找到每一步的最优解。但是最优解怎么找到呢？正着来肯定不行。所以从最后入手。
	还有就是，题目虽然是两个人，但是默认是两个人都可以拿到最优解，所以我们只需要考虑alice的得分的最大值即可。
	倒序的话，从最后的几个数字开始，每次可以选一到三个。所以每一步的最优解其实就是找到alice可以达到分数的最大值和剩下的分数比较。如果剩下的分数更多，就选择剩下的分数。
	可能有人会有疑惑，这样做的话，岂不是每一步都是Alice最优解？Alice怎么可能会输？这里就要看到Alice是必须拿第一堆的。除了第一堆之外，Alice都可以尽可能拿到最多的分数，但是第一堆，也就是dp[0]是无法改变的。dp[0]只能是sum-dp[j]。即每次先手只能拿到后手剩下的东西。


### 代码

```java
class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int sum=0;
		int[] dp=new int[stoneValue.length+3];
		for(int i=stoneValue.length-1;i>=0;i--)
		{
			dp[i]=-2147483648;
			sum+=stoneValue[i];
			for(int j=i+1;j<=i+3;j++)
			{
				dp[i]=(dp[i]>sum-dp[j]?dp[i]:sum-dp[j]);
			}
		}
		if(dp[0]>sum-dp[0])
			return "Alice";
		else if(dp[0]==sum-dp[0])
			return "Tie";
		else
			return "Bob";
    }
}
```