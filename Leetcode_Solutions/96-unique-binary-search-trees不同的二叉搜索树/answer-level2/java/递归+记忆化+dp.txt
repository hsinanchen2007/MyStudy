### 第一种方法： 递归
这道题首先最容易想到的肯定是使用递归的解法，就是对于给出的二分搜索树的节点数，遍历以每一个节点为根节点的所有的情况，相加就是要求的结果

```
class Solution {
    public int numTrees(int n) {
        // 如果n的个数为0或者1，直接返回1
		if (n == 0 || n == 1)
			return 1;

		// 遍历以每一个节点为给节点的数量，相加返回就好啦
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res = res + (numTrees(i - 1) * numTrees(n - i));
		}

		return res;
    }
}
```

### 第二种方法： 递归+记忆化
这种递归的写法没有超时，可能是测试的数据不够大，这样的时间复杂度为O(n*2^n),这其中有大量的重复计算，例如对于n=3这个例子，画出的递归树如下所示：
![image.png](https://pic.leetcode-cn.com/30522eab5e885f3a3170d3a556dc513fa2e88081b2db2fb93b4ea9153c5097a5-image.png)
可以发现，这其中对于某个节点个数的二分搜索树的个数有好多重复的计算，所以这里使用一个memo数组记录对于节点数为n的二分搜索树有几个，这样就可以使得时间复杂度降低为O(n^2)
```
class Solution {
    private int[] memo;

	int dfs(int n) {
		// 如果n的个数为0或者1，直接返回1
		if (n == 0 || n == 1)
			return 1;

		if(memo[n]!=-1)
			return memo[n];
		
		// 遍历以每一个节点为给根节点的数量，相加返回就好啦
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res = res + (dfs(i - 1) * dfs(n - i));
		}

		memo[n]=res;
		return res;
	}

	public int numTrees(int n) {
		if(n==0||n==1) return 1;
		
        memo=new int[n+1];
        Arrays.fill(memo, -1);
        
        return dfs(n);
	}
}
```
### 第三种方法： 动态规划
定义的状态就是对于节点数为i的二分搜索树有几个，状态转移方程也很好定义，就是dp[i]=(dp[j-1]*dp[i-j]) j={1,i},也就是对于以1-i为根节点的二分搜索树的所有情况的和就是个数为i的二分搜索树的所有的情况,需要注意的是初始化的时候dp[0]=1，以便于后面的求解
```
class Solution {
    public int numTrees(int n) {
        //如果n为0或者1，直接返回1
        if(n==0||n==1) return 1;
        
        int[]dp=new int[n+1];
        dp[0]=1; dp[1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]=dp[i]+(dp[j-1]*dp[i-j]);
            }
        }
        
        return dp[n];
    }
}
```

