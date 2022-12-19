# 思路

- 暴力循环乘积O(N)
- 分治，x 的 n 次方，
  - n是偶数-计算 y=x^(n/2)，然后计算y的平方
  - n是奇数-y = y * y * x
  - O(logn)

# Python实现

## 递归实现

```python
class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if not n:
            return 1
        if n < 0: # n为负数，倒数
            return 1 / self.myPow(x, -n)
        if n % 2: # n为奇数，n-1
            return x * self.myPow(x, n-1)
        return self.myPow(x*x, n/2) # n为偶数，直接n/2
```

## 非递归实现

```python
class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0:
            x = 1 / x
            n = -n
        pow = 1
        while n:
            if n & 1: # 如果2进制位等于1
                pow *= x
            x *= x
            n >>= 1 # n 右移一位即n/=2
        return pow
```

# Go实现
使用折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1，

这个时候再往回乘，如果此时n是偶数，直接把上次递归得到的值算个平方放回即可，

如果是奇数，则还需要乘上个x的值。

还有一点需要注意的是n有可能为负数，对于n是负数的情况，可以先用其绝对值计算出一个结果再取其倒数即可。

```go
func myPow(x float64, n int) float64 {
	if n == 0 { // 递归终止条件
		return 1
	}
	if n < 0 { // n为负数，先用其绝对值计算，然后取其倒数
		return 1 / myPow(x, -n)
	}
	if n%2 != 0 { // n 为奇数
		// n-1为偶数，再递归一次
		return x * myPow(x, n-1)
	}
	// 执行真正的运算逻辑，x的平方，n/2
	return myPow(x*x, n/2)
}
```

## 位运算

```go
func myPow(x float64, n int) float64 {
	if n < 0 { // n为负数，进行转换
		x = 1 / x
		n = -n
	}
	pow := float64(1)
	for n != 0 {
		if n&1 == 1 {
			pow *= x
		}
		x *= x
		n >>= 1
	}
	return pow
}
```