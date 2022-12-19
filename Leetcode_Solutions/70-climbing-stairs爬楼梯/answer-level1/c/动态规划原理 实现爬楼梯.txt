### 解题思路

    动态规划（Dynamaic Programming）是“运筹学”的一个分支，是求解“决策过程最优化的”数学方法。它是20世纪50年代初美国数学家R.E.Bellman
等人提出的“最优化原理”，它利用各阶段之间的关系，逐个求解，最终求得“全局最优解”。在设计动态规划算法时，需要确认原问题与子问题、动态
规划状态、边界状态值、状态转移方程等关键要素。
    在算法面试中，动态规划是最常考察的题型之一，大多数面试官都以“可否较好地解决动态规划”相关问题来区分候选是否“聪明”。
    
    【动态规划原理】
	1.确认“原问题”与“子问题”
	原问题为求n阶台阶所有爬法的数量，子问题是求1阶台阶、2阶台阶、...、n-1阶台阶的走法。
	
	2.确认状态
	本题的动态规划状态单一，第i个状态即为i阶台阶的所有爬法数量； 
	
	3.确认边界状态值
	边界状态为1阶台阶与2阶台阶的走法，1阶台阶有1种走法，2阶台阶有2种走法，即 dp[1] = 1，dp[2] = 2； 
	
	4.确定状态转移方程 
	将求第i个状态的值转移为求第i-1个状态的值与第i-2个状态的值，动态规划转移方程为：dp[i] = dp[i-1] + dp[i-2]；（i>=3） 

例1：爬楼梯
	选自：LeetCode 70. Climbing Stairs	
	https://leetcode.com/pro
	难度：Easy
	 
    【问题描述】
	在爬楼梯时，每次可向上走1阶台阶或2阶台阶，问有n阶楼梯有多少种上楼的方式？ 
	
	递归方式（当n比较大时，算法会超时）求解： 
		#include <iostream>
		#include <cstdio>
		using namespace std;
		
		int climbStairs(int n) {
			if (n==1 || n==2) {
				return n;
			} else {
				return climbStairs(n-1) + climbStairs(n-2);
			}
		} 
		
		int main() {
			cout << climbStairs(10000);
		}
	
	【算法分析】
	到达楼梯的“第i阶”有多少种爬法，与“第几阶”的爬法“直接相关”？如何递推的求出第i阶爬法的数量？
	
	由于每次最多爬2阶，楼梯的第i阶，只可能从楼梯第i-1阶与第i-2阶到达。到达第i阶有多少种爬法，只与第i-1阶、第i-2阶的
爬法数量“直接相关”。 

	第i阶的爬法数量 = 第i-1阶的爬法数量 + 第i-2阶的爬法数量
	
	1.设置“递推数组”dp[0...n]，dp[i]代表到达第i阶有多少种爬法，初始化元素为0；
	2.设置到达第1阶台阶，有1种爬法；到达第2阶台阶，有2种爬法；
	3.利用i循环递推从第3阶至第n阶结果：到达第i阶的方式数量=到达第i-1阶的方式数量+ 达第i-2阶的方式数量
		dp[0] = 0
		dp[1] = 1
		dp[2] = 2
		dp[3] = dp[1] + dp[2] = 3
		...
		dp[i] = dp[i-1] + dp[i-2]
		...
		dp[n] = dp[n-1] + dp[n-2]		 


#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
	//int dp[n+1] = {0};
	
	int *dp;
	dp = (int *) calloc(n+1, sizeof(int));	
	
	if (n < 1) {
		return 0;
	} else if (n < 3) {
		return n;
	} else {
		dp[1] = 1;
		dp[2] = 2;
		for (int i=3; i<=n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		} 
		return dp[n];
	}
} // end climbStairs()

int main() {
	printf("%d", climbStairs(10000));		// 2132534333
}

### 代码

```c
int climbStairs(int n){
	//int dp[n+1] = {0};
	
	int *dp;
	dp = (int *) calloc(n+1, sizeof(int));	
	
	if (n < 1) {
		return 0;
	} else if (n < 3) {
		return n;
	} else {
		dp[1] = 1;
		dp[2] = 2;
		for (int i=3; i<=n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		} 
		return dp[n];
	}
}
```