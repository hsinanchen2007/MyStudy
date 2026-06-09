# 思考

1. 二分法
1. 牛顿迭代法，枚举切线逼近最后的根

![1.png](https://pic.leetcode-cn.com/263d917ff95e94f6a20543c5a5075d68958025ba1031dc0ec007b04d91ba06de-1.png)


# C++实现二分法

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x==0||x==1) return x;
        int l = 1, r = x, res;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m==x/m) {
                return m;
            } else if (m>x/m) {
                r = m - 1;
            } else {
                l = m + 1;
                res = m;
            }
        }
        return res;
    }
};
```

# Python实现牛顿迭代法

```python
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        r = x
        while r * r > x:
            r = (r + x/r) / 2
        return r
```

# Go实现

```go []
func mySqrt(x int) int {
	r := x
	for r*r > x {
		r = (r + x/r) / 2
	}
	return r
}
```
```go []
func mySqrt(x int) int {
	if x == 0 || x == 1 {
		return x
	}
	l, r, res := 1, x, 0
	for l <= r {
		m := l + (r-l)/2
		if m == x/m {
			return m
		} else if m > x/m {
			r = m - 1
		} else {
			l = m + 1
			res = m
		}
	}
	return res
}
```


