# “动态规划”用于多阶段最优化问题的求解
## 斐波那契数列、LeetCode-70. 爬楼梯
### 斐波那契数列
为什么把 <u>**斐波那契数列**</u> 跟 <u>**LeetCode-70. 爬楼梯**</u> 放在一起哈，因为你如果做过或者看过<u>**LeetCode-70. 爬楼梯**</u> 相关的题解，里面用动态规划来解题的公式跟<u>**斐波那契数列**</u>居然是一模一样的。

那么这里就从就先从大家所熟悉的 <u>**斐波那契数列**</u> 开始讲起。
#### 要点
斐波那契数列公式，也就是所谓的 <u>**状态转移方程**</u>：
$$F(n)=F(n-1)+F(n-2)\tag{1.1}$$

第一行是 **下标** ,第二行是 **和** 。
![斐波那契数列](https://pic.leetcode-cn.com/e72c1900effd6100e8eed0601dc263a74055c47c5adb65bb299db705e31ad8b4.png)
<center>图1.1</center>

![状态转移方程](https://pic.leetcode-cn.com/8a6268a1fa6c6fecda6959389f49751376e27c3d4eb25717e32616a1a0d75391.png)
<center>图1.2</center>

>将```N-2、N-1```的结果转移到```N```的结果
#### 解法
当前如果传入的数为```Ｎ```，可以创建一个长度```Ｎ＋１```(*[0...N]*)空间的 **dp table**来记录。
斐波那契数列
　　**N=0，Value=0
　　N=1，Value=1
　　N=2，Value=1
　　N=3，Value=2
　　N=4，Value=3
　　...
　　Value：$F(n)=F(n-1)+F(n-2)$**
　　
##### 代码片段
**详细题解点击这里 [斐波那契数列、 Leetcode 70. 爬楼梯 矩阵($O(logN)$)运算、累加($O(N)$)、递归备忘录($O(N)$)](https://blog.csdn.net/weixin_42322309/article/details/104423040)**
本篇文章只针对动态规划进行讲解。
```java
public int fibonacciDP(int n) {
	if (n < 1) {//1.小于1的值都是0步
		return 0;
	}
	if (n <= 2) {//2.由dp表可以知道 n=1、n=2 都是1直接返回
		return 1;
	}

	int[] dp = new int[n + 1];//3.创建一个一维数组，存放转移的结果。
	//4.base case
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];//5.从i=3开始，计算在i位置从 i-2、i-1转移过来应该走多少步。
	}
	return dp[n];//返回最后一格，最终结果
}
```

> 到这里同学们都知道了用dp数组来记录斐波那契数列的方法了，当然这里可以只用两个常量来写， [见上文链接](https://blog.csdn.net/weixin_42322309/article/details/104423040)。

###  LeetCode 70. 爬楼梯
这里主要讲一下二维dp表推导到一维
这里省略了其它的解法，你可以通过[见上文链接](https://blog.csdn.net/weixin_42322309/article/details/104423040)查看详细的解法。
![动态规划表](https://pic.leetcode-cn.com/83baf83586805ac64557a49dc1196a24e285654981965b862d053cada623b76a.png)
<center>（图1.3）</center>
<html><br></html>

现在有两种步数，分别是走```1```步跟走```2```步
如果每次都只走一步的话，到```N```的时候还是只有一种走法，所以在```dp[0]```的这一列都是```1```
![动态规划表](https://pic.leetcode-cn.com/c197c71ef8998f6af051122328d095cc5875c7a45b62c4fd2566dbc585b5e508.png)
<center>（图1.4）</center>
<html><br></html>

当在```index=3```这一列的时候，```dp[1][3]```可能是```dp[1][1]```走两步到达或者```dp[0][2]```走一步到达。
$$dp[1][3]=dp[1][1]+dp[0][2]\tag{1.3}$$
$$dp[i][j]=dp[i][j-2]+dp[i-1][j-1]\tag{1.4}$$

在```index=3```这一阶不管是怎么到达的，它拥有的走法一致，同步这一阶的走法数：```dp[1][3]=>dp[0][3]```，
$$dp[i-1][j]=>dp[i][j]\tag{1.5}$$
```java
public int climbStairsDPX(int n) {
	if (n < 1) {
		return 0;
	}
	if (n <= 2) {
		return n;
	}//1.已知的结果直接返回了。

	int[][] dp = new int[2][n + 1];
	
	for (int i = 1; i <= n; i++) {
		dp[0][i] = 1;//2.都直走一步，那么只有一种啊
	}

	dp[0][0] = 0;//没有台阶都是0
	dp[1][0] = 0;//没有台阶都是0
	dp[0][1] = 1;//有1(1)  种步数的时候，1阶台阶只有1种方法 走一步
	dp[1][1] = 1;//有2(1,2)种步数的时候，1阶台阶只有1种方法 走一步
	dp[0][2] = 2;//有2(1,2)种步数的时候，2阶台阶有2种方法
	dp[1][2] = 2;//有2(1,2)种步数的时候，2阶台阶有2种方法
	for (int i = 1; i < 2; i++) {//遍历所有的走法，因为当i=0的时候已经都默认给值了
		for (int j = 3; j <= n; j++) {
			dp[i][j] = dp[i][j - 2] + dp[i - 1][j - 1];//4.根据表格可以知道dp[i][j]的来源。
			dp[i - 1][j] = dp[i][j];//5.同步当前这个阶层的走法，不然i=0这列还以为自己是1种走法。
		}
	}
	return dp[1][n];//6.返回最后一阶的结果。
}
```
OutPut:测试通过。
![测试结果](https://pic.leetcode-cn.com/5082761e330aff67dddbd83cd9e95e3cd023163442f9a950dc5ed30edce189f4.png)
这个时候再回过头来看一下 **（图1.4）** ，可以明显的看到其实上下两列的结果一致，并不需要用二维数组来记录结果。
合并数组看一下：
![爬楼梯](https://pic.leetcode-cn.com/3e7f9f9bab4257f2da3bd964f7a76f419d68211c85933ca7756388165c39e7ac.png)
<center>（图1.6）</center>
<html><br></html>

其实就是$F(n)=F(n-1)+F(n-2)$

**不就是斐波那契数列嘛！**

唯一的区别在于：
　　斐波那契数列：```１，１，２，３，５，８，．．．```
　　爬楼梯：```１，２，３，５，８，．．．```
那么这里可以将 ```N```往右移动一位数```N+1```，那么将这个值代入斐波那契数列函数(*从第二位开始取结果*)得出来的结果就是 <u>[70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)</u> 的结果。


---

## 64. 最小路径和
[原题链接](https://leetcode-cn.com/problems/minimum-path-sum/)
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

**示例:**
```
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
```
### 要点
计算每次到达一个格子的时候，记录到达这个位置最短的路径是多少，那么从它这个位置再往下或者往右的时候就能够**通过两个目前最短的路径计算出当前这个格子的最短路径**。
![最小路径和](https://pic.leetcode-cn.com/d37011c0edd78d3f057bbef97322ce44b6705ca84ca73c889ee5203c22db4a3c.png)
<center>（图2.1）</center>
<html><br></html>

### 解法
题目告诉我们只能向右或者向下行走，那么首先可以计算出：
　　第1行(*只能通过由左向右这一种走法*)```dp[0][j]```行走的距离
　　第1列(*只能通过由上向下这一种走法*)```dp[i][0]```行走的距离
这里已经是通过 ```dp[0][1]、dp[1][0]```的值推算出```dp[1][1]```的值了。
![最小路径和](https://pic.leetcode-cn.com/3e6f99505205acc4390f8ebba13a3c72e5130539fce651e38b602c25f067380c.png)
<center>（图2.2）</center>
<html><br></html>
即相邻两个位置拿一个最短的距离与当前位置相加，得出到这个格式一共走了多少路径距离。

**状态转移方程：**
$$dp[i][j]=Min(dp[i-1][j]+dp[i][j-1])+arr[i][j]\tag{2.3}$$

#### 代码片段
```java
public int minPathSum(int[][] m) {
	if (m == null || m.length == 0 || m[0] == null || m[0].length == 0) {//1.传入的矩阵有问题就直接返回0了
		return 0;
	}
	int col = m.length;//2.一共有多少行
	int row = m[0].length;//3.一共有多少列
	int[][] dp = new int[col][row];//4.创建一个行列二维dp数组。
	//5.由左向右
	dp[0][0] = m[0][0];
	for (int i = 1; i < row; i++) {
		dp[0][i] = dp[0][i - 1] + m[0][i];
	}
	//6.由上向下
	for (int i = 1; i < col; i++) {
		dp[i][0] = dp[i - 1][0] + m[i][0];
	}

	for (int i = 1; i < col; i++) {
		for (int j = 1; j < row; j++) {
			dp[i][j] = Math.min(dp[i][j - 1], dp[i - 1][j]) + m[i][j];//7.取相邻位置具有最短路径的与当前位置相加，得出当前位置最短路径。
		}
	}
	return dp[col - 1][row - 1];//8.返回到达终点的距离。
}
```
#### 完整数组
![矩阵最小路径](https://pic.leetcode-cn.com/b472c8348b07a1f8c4689f0195102df724a8787b2a7d9430a0ee5a8b13c23979.png)
<center>（图2.3）</center>
<html><br></html>

#### 代码片段
```java
public int minPathSum1x(int[][] m) {
	if (m == null || m.length == 0 || m[0] == null || m[0].length == 0) {
		return 0;
	}
	int more = Math.max(m.length, m[0].length);
	int less = Math.min(m.length, m[0].length);
	//假设directed == true 是横向
	boolean directed = more == m[0].length;
	int[] dp = new int[less];
	dp[0] = m[0][0];
	for (int i = 1; i < less; i++) {
		dp[i] = dp[i - 1] + (directed ? m[i][0] : m[0][i]);
	}
	for (int i = 1; i < more; i++) {
		dp[0] = dp[0] + (directed ? m[0][i] : m[i][0]);
		for (int j = 1; j < less; j++) {
			dp[j] = Math.min(dp[j - 1], dp[j]) + (directed ? m[j][i] : m[i][j]);
		}
	}
	return dp[less - 1];
}
```
> 这里以```dp[1][1]=5```特别说明一下，这个位置的结果来自```9，4```,```dp[0][0]=1```这个位置的结果已经不重要了，所以这里只需要一维数组来存储结果，实现路径压缩。
---
## 322. 零钱兑换
[原题链接](https://leetcode-cn.com/problems/coin-change/)
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

**示例 1:**
```
输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
```
**示例 2:**
```
输入: coins = [2], amount = 3
输出: -1
```
**说明:**
你可以认为每种硬币的数量是无限的。
### 要点
每一种的金额都可能由任意的硬币组成。
如果```arr```的长度为```N```，生成行数为```N```、列数为```aim+1```的dp表。
```dp[i][j]```表的含义是，在可以使用任意```arr[i...0]```货币的情况下，组成```j```所需的最小张数。
![动态规划表](https://pic.leetcode-cn.com/d505c3a16445812d91e2c611e8c112cbb22ded1f7ef601dc9380fcdd3b38acd5.png)
<center>（图3.1）</center>
<html><br></html>

### 解法
以图片示例
```
coins = [2, 3, 4]
aim  = 8
```
可以知道当只有一种硬币```coin=2```的时候，将dp表格修改如下：
![动态规划表](https://pic.leetcode-cn.com/0500f6dd358c0af11c7d69c2657f9fa2a6d86b4f130da8c0b3e58e4f0074825d.png)
<center>（图3.2）</center>
<html><br></html>

也就是：
　　只有2元的零钱时，无法兑换```1,3,5,7```这些面额，
　　1张2元可以换2元，2张2元可以换4元，
　　3张2元可以换6元，4张2元可以换8元，
　　**那么比如在兑换6元的时候，目前只有2元的硬币所以肯定是4元那个位置的张数2+1张2元**：
　　$$dp[0][j] = dp[0][j-coin[0]]+1\tag{3.3}$$
　　也就是找到一个坐标，它加上当前这种零钱能够找零，那么比之前的结果加上1张，
　　动态转移方程：
　　$$dp[i][j] = dp[i][j-coin[i]]+1\tag{3.4}$$

![在这里插入图片描述](https://pic.leetcode-cn.com/87958d8d21815b2d757440f00dc4148b2241e1e692a7dd2001ed87d459ff52d5.png)
<center>（图3.5）</center>
<html><br></html>

我们现在填充```dp[1][3]=1```，代表只能用一张3元来兑换。<u>思考一下哪里不对劲？？？</u>
我们要求能兑换这个钱的最小张数，从```dp[1][0]->dp[1][2]```明显应该是```1```张，但从图片上来看，之前在第一行```dp[0][2]=0```的时候是```0```+1=1张，最小值```min(0,1)=0```，也就是说这里的默认值```0```是错误的。应该是```min(?,1)=1```，所以这里我们应该将默认值设置成最大值。
![动态规划表](https://pic.leetcode-cn.com/8ca89d9562a151ea986693401261e573293cecbaf3276c93169a6ffe41715bb2.png)
<center>（图3.6）</center>
<html><br></html>

**dp[1][1]=Max：**
　　```dp[1][1]```的位置无法从```dp[1][-2]```的位置获取张数，并且在只有2元的时候，也无法找钱

**dp[1][2]=1：**
　　```dp[1][2]```的位置无法从```dp[1][-1]```的位置获取张数，但是在只有2元的时候，可以用一张2元

**dp[1][3]=1：**
　　```dp[1][3]```的位置从```dp[1][0]```的张数+1，在只有2元的时无法找，所以可以用一张3元的找

$$dp[1][2]=dp[0][2]\tag{3.7}$$
$$dp[i][j]=dp[i-1][j]\tag{3.8}$$

#### 代码片段
```java
public int minCoins1(int[] arr, int aim) {
	if (arr == null || arr.length == 0 || aim < 0) {//1.传入错误参数直接返回-1无法找。
		return -1;
	}
	int maxValue = Integer.MAX_VALUE;//2.取一个最大值，用来设置无法找的情况。也就是如果遇到一个可以找的零钱，就使用它。
	int[][] dp = new int[arr.length][aim + 1];//3.创建一个二维的dp数组
	for (int j = 1; j <= aim; j++) {//4.填充第一行只有2元的时候，可以找就设置张数，不能找就设置为maxValue
		dp[0][j] = maxValue;
		if (j - arr[0] >= 0 && dp[0][j - arr[0]] != maxValue) {
			dp[0][j] = dp[0][j - arr[0]] + 1;
		}
	}

	for (int i = 1; i < arr.length; i++) {//5.遍历每一个坐标点，求对应的最小张数。
		for (int j = 1; j <= aim; j++) {
			int left = maxValue;
			if (j - arr[i] >= 0 && dp[i][j - arr[i]] != maxValue) {//7.计算横向状态转移的的结果，如果是从一个可以计算的位置出发，那么张数+1
				left = dp[i][j - arr[i]] + 1;
			}
			dp[i][j] = Math.min(left, dp[i - 1][j]);//8.取一个最小值作为当前坐标的结果。
		}
	}
	
	return dp[arr.length - 1][aim] != maxValue ? dp[arr.length - 1][aim] : -1;//6.我们设置了最大值是无法找，所以在最后一格返回的时候对无法找的maxValue返回-1。
}
```
---

## 121. 买卖股票的最佳时机
[原题链接]()

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。
**示例 1:**
```
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 ```
**示例 2:**
```
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```
### 解法
1. 口袋里的钱都可能由任意操作之后形成。
2. 这里设置买入卖出2种动作，生成行数为```2```、列数为```prices```的dp表。
3. ```dp[i][j]```表的含义是，在```prices[0,prices.length]```的时候，买入或者卖出口袋剩下多少钱。
4. <u>这里需要注意卖出只能在买入之后。</u>
5. 一开始不赚不亏设置为0。
![动态规划表](https://pic.leetcode-cn.com/d4b9877e2570137900e86b7a0ae140609461dffe32d918077c94678aed15263a.png)
#### 代码片段
```java
public int maxProfitDp(int[] prices) {
	if (prices == null || prices.length < 2) {//0.传入的数组错误直接返回，长度为1只能买不能卖。
		return 0;
	}
	int[][] dp = new int[2][prices.length];//1.根据说明创建一个
	dp[0][0] = -prices[0];//2.如果在第一天买入花了prices[0]
	dp[1][0] = 0;//3.第一天没法卖出，只能买入。
	for (int i = 1; i < prices.length; i++) {//4.看看每一天在执行买入或者卖出口袋能剩下最多钱。
		dp[0][i] = Math.max(dp[0][i - 1], -prices[i]);//5.比如到了第二天，之前第一天花了dp[0][i-1],即第2步，那么与今天比较哪天花费最少。
		dp[1][i] = Math.max(dp[1][i - 1], dp[0][i - 1] + prices[i]);//6.比如到了第二天，可以观望，也可以看看卖出能不能赚钱。
	}
	return dp[1][prices.length - 1];//7.返回到最后一天时，口袋最多能赚多少钱。
}
```
---

## 5. 最长回文子串
# [最长回文子串详解](https://blog.csdn.net/weixin_42322309/article/details/104474978)
