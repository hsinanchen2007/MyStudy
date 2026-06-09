# 69 - 2的幂

## 题目

给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

> 输入: 1
> 输出: true
> 解释: $2^0$ = 1

示例 2:

> 输入: 16
> 输出: true
> 解释: $2^4$= 16

示例 3:

> 输入: 218
> 输出: false

## 解答

看到题目，第一反应就是在考数学😂😂，肯定有什么骚操作的题解

### log2

> https://leetcode.com/problems/power-of-two/discuss/283725/JavaScript-Solutiuon

$n = 2^x$也就是说$x = log_2(n)$，只要这个x是整数，那么这个n就是2的幂

```js
var isPowerOfTwo = function (n) {
  return Math.log2(n) % 1 === 0
};
```

> Runtime: 80 ms, faster than 29.44% of JavaScript online submissions for Power of Two.
>
> Memory Usage: 35.5 MB, less than 69.23% of JavaScript online submissions for Power of Two.

`%1`的意思是判断有没有小数点。如果是整数，那么就是0

```go
func isPowerOfTwo(n int) bool {
	if n <= 0 {
		return false
	}
	log := math.Log2(float64(n))
	return !strings.Contains(strconv.FormatFloat(log, 'f', -1, 64), ".")
}
```

> Runtime: 0 ms, faster than 100.00% of Go online submissions for Power of Two.
>
> Memory Usage: 2.3 MB, less than 25.00% of Go online submissions forPower of Two.

go里面的取余，需要两边都是int，然而既然都是整数了，那么`%1`也就失去作用了。

那么怎么判断log出来的float64有没有小数点呢？我的做法是让它变成字符串，然后找一下里面有没有`.`

[float64转字符串](https://studygolang.com/articles/5003)很麻烦的感觉。。一大堆参数

- f，表明没有指数。这是默认的缺省值。
- -1，精度-1就全部变成字符串。如果规定精度，那么就一定有小数点了。
- 64是制定浮点类型，是float64

### 迭代

> https://leetcode.com/problems/power-of-two/discuss/63966/4-different-ways-to-solve-Iterative-Recursive-Bit-operation-Math

```js
var isPowerOfTwo = function (n) {
  if (n === 0) {
    return false;
  }
  while (n % 2 === 0) {
    n = Math.floor(n / 2)
  }
  return n === 1;
};
```

> Runtime: 68 ms, faster than 83.02% of JavaScript online submissions for Power of Two.
>
> Memory Usage: 35.6 MB, less than 46.15% of JavaScript online submissions for Power of Two.

之前发现了一个骚操作，可以用`>>>`来代替`Math.floor(n/2)`。但似乎在大数的时候就不行。

反例是`-2147483648`，理应是false，但用`>>>`是true

看来在js里，还是[不要乱用位操作啊](https://jerryzou.com/posts/do-you-really-want-use-bit-operators-in-JavaScript/)

```go
func isPowerOfTwo(n int) bool {
	if n == 0 {
		return false
	}
	for n%2 == 0 {
		n /= 2
	}
	return n == 1
}
```

> Runtime: 4 ms, faster than 40.71% of Go online submissions for Power of Two.
>
> Memory Usage: 2.2 MB, less than 100.00% of Go online submissions for Power of Two.

### 递归

```js
var isPowerOfTwo = function (n) {
  return n > 0 && (n === 1 || (n % 2 === 0 && isPowerOfTwo(Math.floor(n / 2))));
};
```

> Runtime: 68 ms, faster than 82.73% of JavaScript online submissions for Power of Two.
>
> Memory Usage: 35.4 MB, less than 100.00% of JavaScript online submissions for Power of Two.

```go
func isPowerOfTwo(n int) bool {
	return n > 0 && (n == 1 || (n%2 == 0 && isPowerOfTwo(n/2)))
}
```

> Runtime: 0 ms, faster than 100.00% of Go online submissions for Power of Two.
>
> Memory Usage: 2.2 MB, less than 100.00% of Go online submissions for Power of Two.

### 骚操作之n&(n-1)

> 作者：jyd
>
> 链接：https://leetcode-cn.com/problems/power-of-two/solution/power-of-two-er-jin-zhi-ji-jian-by-jyd/

简言之，满足`n > 0` 且 `n & (n - 1) == 0`的，就是2的幂。

```js
var isPowerOfTwo = function (n) {
  return n > 0 && (n & (n - 1)) === 0
};
```

> Runtime: 68 ms, faster than 83.12% of JavaScript online submissions for Power of Two.
>
> Memory Usage: 35.9 MB, less than 15.38% of JavaScript online submissions for Power of Two.

```go
func isPowerOfTwo(n int) bool {
	return n > 0 && (n&(n-1)) == 0
}
```

> Runtime: 0 ms, faster than 100.00% of Go online submissions for Power of Two.
>
> Memory Usage: 2.2 MB, less than 75.00% of Go online submissions forPower of Two.

### 超级骚操作

> https://leetcode.com/problems/power-of-two/discuss/63966/4-different-ways-to-solve-Iterative-Recursive-Bit-operation-Math

还是从这个大佬看到的

```js
var isPowerOfTwo = function (n) {
  return n > 0 && (1073741824 % n == 0);
};
```

> Runtime: 76 ms, faster than 45.28% of JavaScript online submissions for Power of Two.
>
> Memory Usage: 35.7 MB, less than 23.08% of JavaScript online submissions for Power of Two.

整数范围是 -2147483648 (-2^31) ~ 2147483647 (2^31-1)，因此2的最大幂为 2^30 = 1073741824.

1. 如果n是2的幂，$n=2^k$，其中k是整数

$2^{30} = (2^k)*2^{30-k}$，即$2^{30}$ % $2^k$ === 0

2. 如果n不是2的幂，假设$n=j*2^k$，其中k是整数，j是奇数

$2^{30}$ % $j*2^k$ == $2^{30-k}$ % j !=0

【其实我不太懂，为啥j是一个奇数，或者说不应该是$2^k$加上某个数吗？】

```go
func isPowerOfTwo(n int) bool {
	return n > 0 && (1073741824%n == 0)
}
```

> Runtime: 0 ms, faster than 100.00% of Go online submissions for Power of Two.
>
> Memory Usage: 2.2 MB, less than 75.00% of Go online submissions forPower of Two.

### 数一下1的个数

如果是2的幂，那么1的个数就只有一个

js没有现成的数二进制个数的方法，只能手写一个

> https://blog.csdn.net/qq_27954643/article/details/88981058

```js
bitCount = function (n) {
  if (n < 0) {
    n = n >>> 0; // 获取到负数的补码
  }
  let res = n.toString(2);
  let count = 0;
  for (let i = 0; i < res.length; i++) {
    if (res[i] == 1) {
      count++;
    }
  }
  return count;
}
var isPowerOfTwo = function (n) {
  return n > 0 && bitCount(n) === 1;
};
```

> Runtime: 72 ms, faster than 65.74% of JavaScript online submissions for Power of Two.
>
> Memory Usage: 36.2 MB, less than 15.38% of JavaScript online submissions for Power of Two.

js里面数1个数的方法有许多，比如说还有：

```js
bitCount = function (n) {
  let count = 0;
  while (n) {// 直至整数变成0
    count++;
    n = n & (n - 1); // 把整数最右的1变成0，有多少个1，就能进行多少次这样的操作
    // 在计算机中，数值一律用补码存储。而这里用的是位运算，所以无所谓正数负数。
    // 因为位运算之前，需要把整数转换成二进制数。
  }
  return count;
}
```

> Runtime: 76 ms, faster than 45.28% of JavaScript online submissions for Power of Two.
>
> Memory Usage: 35.7 MB, less than 23.08% of JavaScript online submissions for Power of Two.

这个也用了`n&(n-1)`的骚操作

还有：

> https://blog.csdn.net/zjw_python/article/details/82431768

```js
bitCount = function (n) {
  if (n === 0) return 0;
  let count = 0;
  for (let i = 0; i < 32; i++) {
    if ((n >>> i & 1) === 1) {
      count++;
    }
  }
  return count
}
```

> Runtime: 76 ms, faster than 45.28% of JavaScript online submissions for Power of Two.
>
> Memory Usage: 35.6 MB, less than 23.08% of JavaScript online submissions for Power of Two.



go里面也没现成的方法，只能手写。手写的方法和js差不多

```go
func bitCount(n int) int {
	count := 0
	for n != 0 {
		count++
		n = n & (n - 1)
	}
	return count
}
func isPowerOfTwo(n int) bool {
	return n > 0 && bitCount(n) == 1
}
```

> Runtime: 0 ms, faster than 100.00% of Go online submissions for Power of Two.
>
> Memory Usage: 2.2 MB, less than 75.00% of Go online submissions forPower of Two.

剩下的懒得写了。

### 这也能叫算法吗？

32位整数下，2的幂一共就只有31个，所以。。

```js
var isPowerOfTwo = function (n) {
  const all = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824]
  return all.indexOf(n) !== -1
};
```

> Runtime: 64 ms, faster than 92.65% of JavaScript online submissions for Power of Two.
>
> Memory Usage: 35.7 MB, less than 23.08% of JavaScript online submissions for Power of Two.

速度拉满😂😂



go用这个不好查，得用map写。我就懒得写了。。反正怎么写都0ms封顶了


