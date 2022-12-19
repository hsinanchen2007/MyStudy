这周570刚开始讲dp,想找个题试一下
我思考的过程就是画图，首先想到的是让i = 每个完全平方数 j = 小于n的数
![IMG_6486.JPG](https://pic.leetcode-cn.com/831bd41a87723adc9575275b2d40a643d60abbcd38c20528255b13452bb69770-IMG_6486.JPG)

为了能得到完全平方数，我又写了一个函数来生成完全平方数数组squares（可以知道完全平方数的个数等于sqrt(n)）
不难发现 当有新得完全平方数加入后 会有两种情况
case 1: 不选择用新加入的完全平方数，这样的话不会发生改变 d[i][j] = d[i - 1][j];
case 2: 选择使用新加入的完全平方数，这样的话d[i][j]会等于 所用新加入的完全平方数的个数，以及剩余的值在上一行所对应的d[i-1][j]   d[i][j] = (j / squares[i]) + dp[i - 1][j - squares[i] * (j / squares[i])]
(补充一点 d[0][j] d[j][0]都是base case的情况 直接默认等于0即可; d[1][j] = j)
所以状态转移方程式Min((dp[i - 1][j], (j / squares[i]) + dp[i - 1][j - squares[i] * (j / squares[i]))
由此 我们就可以写出代码了
```
class Solution {
	public int numSquares(int n) {
		int sqrt = (int)Math.sqrt(n);
		int[][] dp = new int[sqrt + 1][n + 1];
		int[] squares = generateNumsSquares(n); //生成完全平方数
		for (int i = 1; i <= sqrt; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (i == 1) { // i = 1时 显然...
					dp[i][j] = j;
					continue;
				}
				if (squares[i] > j) { // 防止数组越界 如果新加入的完全平方数大于当前的j, 那么新加入的完全平方数肯定不会被选用 直接等于上一行
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = Math.min(dp[i - 1][j], (j / squares[i]) + dp[i - 1][j - squares[i] * (j / squares[i])]);
				}
			}
		}
		return dp[sqrt][n];
	}
	
	private int[] generateNumsSquares(int n) {
		int len = (int) Math.sqrt(n);
		int[] nums = new int[len + 1];
		for (int i = 1; i <= len; i ++) {
			nums[i] = i * i;
		}
		return nums;
	}
	
	public static void main(String[] args) {
		Solution s = new Solution();
		int n = 13;
		int res = s.numSquares(n);
		System.out.print(res);
		
	}
}
```

上述方法是我最开始的想法，但是效率很低，原因是表中的元素会不断的更新，很多元素的计算是没有必要的（我们根本不可能一直用1） 所以考虑将行列调换，从考虑每个完全平方数的使用情况转换成考虑每个数可能组合的情况。
同样先画表，在画表的过程中我发现，虽然这个是二维的，但是实际上我们用的的数据只有每一行的最后一个不为零的数（也就是最优的情况） 所以，我们没有必要再用二维数组在保存结果，用数组即可。
![QQ图片20200224074433.png](https://pic.leetcode-cn.com/47ddaa72a5c38493e648fd414a52b548854318835ccf9d925c34dd8aed4f92de-QQ%E5%9B%BE%E7%89%8720200224074433.png)

具体来说：原本我们用d[i][j] 现在采用d[i]代替 因为我们知道d[i][j + 1]相比于d[i][j]来说肯定是更优的结果（在不为零且经过Min()的前提下） 所以我们把存储转换为更新，只保留最新的d[i].（注意：在不用Min()时，d[i][j + 1]不一定比d[1]更优，当数为13时会出现这种情况）
这种方法下的状态转移方程和上面所有方法基本一直
dp[i] = Math.min(dp[i], i / squares[j] + dp[i - (i / squares[j]) * squares[j]]);
但是完成之后 我发现 效率并没有提高多少QAQ.

然后我又重新想了一下状态方程，发现其实有更好的写法,没必要再去计算需要多少个完全平方数，因为之前都已经计算过了，我们只需要先减掉一次完全平方数 这样我们就可以直接通过之前计算的得到 最后再+1补上即可。
Min(dp[i], dp[i - squares[j]] + 1)

而且，这种方法不需要再一下的到所有完全平方数了，这样只会带来多余的计算（数组越界时发现QAQ）
最后去掉生成数组 改了状态方程 发现还是不快… :)
至于Runtime comlexity 我感觉是O(n²)?
下面是代码：
```
class Solution {
	public int numSquares(int n) {
		int sqrt = (int )Math.sqrt(n);
		int[] dp = new int[n + 1];
		
		for (int i = 1; i <= n; i ++) {
			dp[i] = i; // 通过画表发现
			for (int j = 2; j * j <= i ; j ++) { // j = 1已经由上赋值了
				dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
	}
	
	public static void main(String[] args) {
		Solution s = new Solution();
		int n = 12;
		int res = s.numSquares(n);
		System.out.print(res);
		
	}
}
```


