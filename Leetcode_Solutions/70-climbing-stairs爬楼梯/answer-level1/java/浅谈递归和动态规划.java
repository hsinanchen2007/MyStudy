### 解题思路
这题最简单的思路是递归，好理解，然后测试45，我发现超时了，mmp。
于是我想到了另一种与递归差不多的想法，DP。
动态规划是一个有记忆的递归，用一个数组把一些中间结果存储，避免了重复调用。
递归是自上而下的，而动态规划是自底向上，与之相反。
### 代码

```java
class Solution {
    
    public static int climbStairs(int n) 
	{
		if( n == 1)
		{
			return 1;
		}
		else if( n == 2)
		{
			return 2;
		}
		else
		{
			int[] a = new int[n];
			a[0] = 1;
			a[1] = 2;
			for(int i = 2; i < n; i++)
			{
				a[i] = a[i-1] + a[i-2]; // 动态规划表达式
			}
			return a[n-1];    
		} 
	}
    
}
```