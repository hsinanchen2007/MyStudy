

### Go
![9667cdc106beac7d6fd8ef12f73767c.png](https://pic.leetcode-cn.com/a528903c171d681cd916e29502574d5be02d8a789cad4d2dfff17d75b374d011-9667cdc106beac7d6fd8ef12f73767c.png)
### Python
![c6c82971e75b320194b8d333a327477.png](https://pic.leetcode-cn.com/14710be36d509892e3f44947c0acfadf0602b37e3295100533643d1c5a24c2e6-c6c82971e75b320194b8d333a327477.png)
### 解题思路
本题是经典的分治法，用递归（recursion）和迭代（iteration）都可以完成。

### 递归 Recursion
```go []
func help(x float64, n int) float64 {
	if n == 1 {
		return x
	} else if n&1 == 0 {
		return help(x*x, n/2)
	} else {
		return x * help(x, n-1)
	}
}

func myPow(x float64, n int) float64 {
	if n < 0 {
		return help(1.0/x, -n)
	} else if n == 0 {
		return 1
	} else {
		return help(x, n)
	}
}

```
```python []
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n > 0:
            return __help(x, n)
        elif n == 0:
            return 1
        else:
            return __help(1/x, -n)
    
    def __help(a, b):
            if b == 1:
                return a
            elif b & 1:
                return a * __help(a, b-1)
            elif not b & 1:
                return __help(a*a, b//2)

```

### 迭代 Iteration
```go []
func myPow(x float64, n int) float64 {
    if n < 0 {
        x = 1.0/x
        n = -n
    } else if n == 0 {
        return 1
    }
    ans := 1.0
    for n > 1 {
        if n & 1 == 1 {
            ans *= x
            n--
        } else {
            x = x*x
            n /= 2
        }
    }
    ans *= x
    return ans
}

```
```python []
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1 / x
            n = -n
        elif not n:
            return 1
        
        ans = 1
        while n > 1:
            if n & 1:
                ans *= x
                n -= 1
            else:
                x = x * x
                n //= 2
        ans *= x
        return ans
```