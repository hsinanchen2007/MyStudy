# 斐波那契解法

斐波拉契数列形如

```
f(n) = f(n-1) + f(n-2)
```

常见的解法有：

1. 直接递归，时间复杂度为O(2^N)（主定理，或者枚举计算，等比求和），空间复杂度是O(n)，递归调用栈的空间

2. 递归加记忆化，把每个f（n）保存起来，如果计算过就不计算了，空间换时间的思维，时间复杂度为O(N)，空间复杂度O(N)

3. 递推，时间复杂度为O(N)，空间复杂度O(1)

4. 通项公式法，即是求解power(a, n)，时间复杂度O(lgN)，空间复杂度O(1)
![屏幕快照 2019-07-23 上午9.28.08.png](https://pic.leetcode-cn.com/9035f31284168bf413ca6f68280a50f190cb2e42df312938ca437e3ef03c9b9a-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-07-23%20%E4%B8%8A%E5%8D%889.28.08.png)

斐波那契数列通项公式：

```
f(n) = a1(b1)^n + a2(b2)^n
```

其中a1, b1, a2, b2四个数字都是常数。
通项公式的计算，并不能O(1)得到，而是一个a^n，即power(a, n)的求解过程。

另外，由于是浮点运算，受限于浮点运算的精度问题，需要做一个取整才能得到整数，计算机的浮点运算还是比较耗时的



5. 矩阵相乘法

   [winter老师介绍的办法](https://time.geekbang.org/dailylesson/detail/100028406?utm_source=pc&utm_medium=pcchaping1127&utm_term=pcchaping1127)是借助线性代数的矩阵运算，构造斐波那契数列的通项公式的形态，用矩阵相乘的办法来求解，把斐波那契数列转换成矩阵的幂运算，达到O(lgN)

6. 查表，空间换时间的极致，时间复杂度O(1)，空间复杂度(嗯，很大，不知道怎么表示？)

   ```java
     static final int[] fibs = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040};
     public int fib(int N) { return fibs[N]; }
   ```



## power(a, n)的求解

- 第一种解法：不断的乘以自己，的时间复杂度O(N)
- 第二种解法：递归分治，O(lgN)
- 第三种解法：通过N的二进制位，迭代分治，O(lgN)



## 矩阵相乘法

通过使用矩阵乘法和矩阵幂运算来实现时间复杂度O(lgN)，空间复杂度为O(1)

目标就是a，b变为b，a+b。 

最终的结果用矩阵来表示就是: ![屏幕快照 2019-07-24 上午10.40.52.png](https://pic.leetcode-cn.com/bcee4dc5118b7428fde42e8c854d485a0e999ee07cd2794770a2f9f6caecf2b5-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-07-24%20%E4%B8%8A%E5%8D%8810.40.52.png)

下面是用go来实现

```go
func fib(N int) int {
	if N == 0 || N == 1 {
		return N
	}
	// first 是第0个和第1个元素
	first := [][2]int{[2]int{0, 1}, [2]int{0, 0}}
	// temp为系数
	temp := [][2]int{[2]int{0, 1}, [2]int{1, 1}}
	res := matrix22_pow(temp, N - 1)
	return matrix22_mul(first, res)[0][1]
}

func matrix22_pow(x [][2]int, n int) [][2]int {
	r := x
	res := [][2]int{[2]int{1, 0}, [2]int{0, 1}}
	for n != 0 {
		if n & 1 == 1 {
			// 最低二进制位为1
			res = matrix22_mul(res, r)
		}
		// 2维矩阵相乘
		r = matrix22_mul(r, r)
		n >>= 1
	}
	return res
}

func matrix22_mul(x, y [][2]int) [][2]int {
	temp := make([][2]int, 2)
	temp[0][0] = x[0][0] * y[0][0] + x[0][1] * y[0][1]
	temp[0][1] = x[0][0] * y[0][1] + x[0][1] * y[1][1]
	temp[1][0] = x[1][0] * y[0][0] + x[1][1] * y[0][1]
	temp[1][1] = x[1][0] * y[1][0] + x[1][1] * y[1][1]
	return temp
}
```

# 参考

[极客时间 winter的讲解](https://time.geekbang.org/dailylesson/detail/100028406?utm_source=pc&utm_medium=pcchaping1127&utm_term=pcchaping1127)

[58沈剑架构师之路—别再问我斐波那契数列了](https://yq.aliyun.com/articles/646447?spm=a2c4e.11153940.bloghomeflow.69.70e1291aNGkuPW)