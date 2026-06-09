### 写在前面
这个问题类似于斐波那契数列问题，可以用记忆化递归高效地解决

具体细节在代码中

### 代码

```java
class Solution {
    public int numWays(int n) {
        // 存放从第0~n阶爬到第n阶的爬法数，例如nemo[0]表示从第0阶爬到第n阶的爬法数
		long memo[] = new long[n + 1];
		// 得到从第0阶爬到第n阶的爬法数
		return (int) climb_Stairs(0, n, memo);
    }
    public long climb_Stairs(int i, int n, long memo[]) {
		if (i > n) { // 基本情况1--超出第n阶的走法不能算一种
			return 0;
		}
		if (i == n) { // 基本情况2--能到达第n阶的走法算一种
			return 1;
		}
		if (memo[i] > 0) { // 基本情况3--利用记忆化的到的昂贵结果直接得到几种走法
			return memo[i];
		}
		// 到达第n阶的前一次状态可能有两种，可能是爬两阶上来的，也可以是爬一阶上来的，要得到的结果是两种爬法数之和
		// 将这次的memo[i]记忆化，memo[i]表示从第i阶爬到第n阶的爬法数
		memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
		// 返回记忆化结果中第i阶爬到第n阶的爬法数
		return memo[i] % 1000000007;
	}
}
```