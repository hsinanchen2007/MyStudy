### 解题思路
本道题目做了很久才通过，感觉有很多的坑等着自己。
首先刚拿到手，觉得题目很简单，开始时，分了两种情况（指数为正和负）+一些特殊情况（底数为0，指数为0）在做
但运行过程中，仍然有报错，第一个错误时n=-2147483648时的错误，刚开始没有反应过来，后来通过题意，才想明白，自己平时做题也没有去考虑过int型的范围，
在n=-2147483648时，由于我先转换成了abs(n)，而正数n最大值为2147483647，因此报错。
第二个遇到的问题是，总是运行超时，一开始我写的pow()函数，是一般的循环算法，但是进行运行测试发现需要2700多ms，所以这种方法不行；
![image.png](https://pic.leetcode-cn.com/ee88c71f08fdd72d238364445b9f01ca60335f8c9e8a91d80f6e8c1a1bc79d40-image.png)
剑指offer中的公式
参考了剑指offer中的转换为递归的思路，
n为偶数，pow(8)=pow(4)*pow(4),pow(4)=pow(2)*pow(2),pow(2)=pow(1)*pow(1)
n为奇数，pow(9)=pow(4)*pow(4)*base,pow(4)=pow(2)*pow(2),pow(2)=pow(1)*pow(1)
在其编写的代码中，也了解到通过异常捕获，使程序鲁棒性更强，通过位运算，能实运行速度更加地快（B格也高了不少）；
总之，学习了。

### 代码

```cpp
class Solution {
public:
#define EPSILON 0.000001 //根据精度需要进行调整
	bool g_InvalidInput = false;
	double myPow(double x, int n) {
		//基数为0且指数<0
		if (fabs(x - 0.0) < EPSILON && n <= 0)
		{
			g_InvalidInput = true;
			return 0.0;
		}
		//如果指数为负时，为临界值时，要特殊处理
		if (n == -2147483648) {
			return 1.0 / (x * Pow(x, abs(n + 1)));
		}
		else
		{
			int absN = abs(n);
			//指数<0，返回其倒数
			return n > 0 ? Pow(x, absN) : 1.0 / Pow(x, absN);
		}

	}
	double Pow(double base, int e)
	{
		if (e == 0) return 1;
		if (e == 1) return base;
		//右移1位，相等于/2，位运算速度更快
		double result = Pow(base, e >> 1);
		result *= result;
		//如果指数为奇数，根据公式，最后还要*base
		//此处判断奇数，通过与1相与，速度更快
		if (e & 0x1 == 1) result*= base;
		return result;
	}
};
```