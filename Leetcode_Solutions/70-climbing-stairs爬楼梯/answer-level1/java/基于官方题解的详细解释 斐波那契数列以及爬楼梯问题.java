# [查看推导过程](https://blog.csdn.net/weixin_42322309/article/details/104423040)
## 斐波那契数列
斐波那契数列（Fibonacci sequence），又称黄金分割数列、因数学家列昂纳多·斐波那契（Leonardoda Fibonacci）以兔子繁殖为例子而引入，故又称为“兔子数列”，指的是这样一个数列：1、1、2、3、5、8、13、21、34、……在数学上，斐波那契数列以如下被以递推的方法定义：F(1)=1，F(2)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 3，n ∈ N*）。

### 要点
$$F(n)=F(n-1)+f(n-2)$$

---
#### 暴力递归代码
时间复杂度:$O(2^N)$
将公式代入递归结构，找到基础的情况。
```java
public int f1(int n) {
	if (n < 1) {//2、1、2、3、5、8、13、21、34 如果传入的n比1小，不用计算。
		return 0;
	}
	if (n <= 2) {//3. base case： n=1，n=2 的时候返回 1
		return 1;
	}
	return f1(n - 1) + f1(n - 2);//1.将公式代入递归结构
}
```
#### 解释
![斐波那契数列图片](https://pic.leetcode-cn.com/4730e3b7d70ec8bfd2c95a27688928316558f00fd81ae50f1c0a212b59bb69a8.png)
**我们以图片为例**
如果当前传入的 $n=8$，在递归过程中会分解成如图结构。
这里没有将其它的分支全部画完，细心的朋友应该能发现它们在到达最底部的时候总会分解成如下结构:
![base case](https://pic.leetcode-cn.com/797edffdb8d956acabfc02c8e1ba5da4f48cce6a953a6c571f9d864948c31c5c.png)
那么当到达 ```f(2)```的时候，如果此时已经知道 ```f(2) = f(1) 、f(0) = 0```，那么在返回上层的时候就能够计算出结果。

---
#### 备忘录
当前理解了暴力递归的过程，再仔细看看图例。
你会发现在递归分解的过程中出现太多重复的```递归子结构```(同颜色标记)
![递归子结构](https://pic.leetcode-cn.com/29a071087214e096611d53f3caecc60314216d9a7ebb0b59c73e9b4ca3cbc57d.png)
这里可以看到实在是有太多重复了，并且随着```N```的增加，这些重复运算呈指数级增长。
所以想办法将这些重复的运算只保留一次，当下次遇到相同的```递归子结构```的时候直接使用之前运算出来的结果。

```java
HashMap<Integer, Integer> f2Map = new HashMap<>();
public int f2(int n) {
	if (n < 1) {
		return 0;
	}
	if (n <= 2) {
		return 1;
	}
	if (f2Map.containsKey(n)) {//1.如果备忘录已经存在某个n的结果，直接使用就行了。
		return f2Map.get(n);
	}
	int res = f2(n - 1) + f2(n - 2);
	f2Map.put(n, res);//将当前n的结果记录到备忘录。
	return res;
}
```

> 时间复杂度:$O(N)$ 
> 额外空间复杂度:$O(N)$

---
#### 顺序累加
斐波那契数列存在明显的特征，先看一下公式
![斐波那契数列](https://pic.leetcode-cn.com/48667ba8058254ab229741db1280bd423a52377415b6bfd877f580e2f1481937.png)
整个的运算过程已经很明显了，只要把这个过程实现。
```java
public int f3(int n) {
	if (n < 1) {
		return 0;
	}
	if (n <= 2) {
		return 1;
	}
	int now = 2;//1.记录第三个位置的结果。
	int pre = 1;//2.记录上一个位置的结果。
	for (int i = 3; i < n; i++) {//3.从第四个位置开始累加。
		int tmp = now; //5.记录计算前的结果，当做新的上一个值
		now = now + pre;//4.当前+之前 = 新的结果
		pre = tmp;//6.修改上一个值。
	}
	return now;
}
```
> 时间复杂度:$O(N)$ 
> 额外空间复杂度:$O(1)$
---
#### 大杀器：矩阵运算$O(logN)$
这个需要具备一点数学功底，当然你也可以边看边学习。
已知公式 $F(n)=F(n-1)+f(n-2)$是一个二阶递推数列
> 所谓二阶递推数列，就是已知前两项（一般都是），然后给出连续三项的之间的关系，然后让你确定通项公式。
> 
# [查看推导过程](https://blog.csdn.net/weixin_42322309/article/details/104423040)
代码中 **一、二、三...** 代表阅读顺序。
```java
public int f4(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	int[][] base = {{1, 1}, {1, 0}};//1.推到出来的基础情况矩阵
	int[][] res = matrixPower(base, n - 2);//2.计算矩阵的n-2次方，n<=2的时候已经直接返回了。
	return res[0][0] + res[0][1];// 3. 相当于矩阵 ×（1，1）
}

public static int[][] matrixPower(int[][] m, int p) {
	if (m == null || m.length == 0) {//0.直接返回
		return null;
	}
	int[][] res = new int[m.length][m[0].length];//1.创建一个单位矩阵，与某个矩阵x相乘之后保证x保持不变。
	for (int i = 0; i < res.length; i++) {
		res[i][i] = 1;
	}
	int[][] tmp = m;
	for (; p != 0; p >>= 1) {//2.每次都将p右移一个位置，比如二进制 1010>>101>10>1>0 即 10>5>2>1>0
		if ((p & 1) != 0) {//3.判断是不是奇数，奇数的情况特殊,没办法直接做矩阵平方的运算，将它乘以单位矩阵保存下来。
			res = muliMatrix(res, tmp);//5.比如在5的时候 tmp * tmp^4，如果不将左侧的tmp记录下来那么结果就错了。
		}
		tmp = muliMatrix(tmp, tmp);//4.矩阵平方。
	}
	return res;
}

public static int[][] muliMatrix(int[][] m1, int[][] m2) {
	//1.矩阵乘法，要求m1的行等于m2的列。
	if (m1 == null || m2 == null || m1.length == 0 || m2.length == 0 || m1.length != m2[0].length) {
		return null;
	}
	int col = m1.length;//2.结果矩阵的行数等于m1的行数。
	int row = m2[0].length;//3.结果矩阵的列数等于m2的列数。
	int[][] res = new int[col][row];//4.根据行列创建一个结果矩阵
	//5.将计算结果存入结果矩阵，用两层for循环的遍历结果矩阵的每一个格子
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < m2.length; k++) {//将m1这一行的数分别乘以m2这一列的数,其中m2.length控制相层的个数。
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	return res;
}
```

##  Leetcode 70. 爬楼梯
### 要点
**设结果为 x**
当$n=1$ 的时候，$x=1$
当$n=2$ 的时候，$x=2$
当$n=3$ 的时候，$x=3$
当$n=4$ 的时候，$x=5$
这个过程与斐波那契数列是一致的，但是需要注意这里是```1,2,3,5```不是```1,1,2,3,5```
那么只要将n的值往上加1```n = n+1```,此时结果与斐波那契数列一致。
### 解法
$f(n) = f(n+1)$
将题目给的n加上1，调用斐波那契数列的解题方法就能得出结果。
#### 代码
```java
public int f4(int n) {
	n+=1;//加1
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	int[][] base = {{1, 1}, {1, 0}};//1.推到出来的基础情况矩阵
	int[][] res = matrixPower(base, n - 2);//2.计算矩阵的n-2次方，n<=2的时候已经直接返回了。
	return res[0][0] + res[0][1];// 3. 相当于矩阵 ×（1，1）
}
```
##### 解释
这里可以把矩阵赋值```	int[][] tmp = m;```去掉，直接使用```m```对提交的性能提升。
---
## 结尾 
##### [1.博客地址](https://blog.csdn.net/weixin_42322309
> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发