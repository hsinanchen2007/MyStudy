### 解题思路
![1.png](https://pic.leetcode-cn.com/b62a21c4e9733ec9fd75a405e0da19d0bcb72edb0b992ee7578508ace5ae965c-1.png)

**解题思路**
这道题考虑如果直接计算幂次可能会存在超时的风险，所以我决定尝试用位运算的办法求解，从1开始，每次左移一位，看看是不是能匹配到target，如果可以就返回true,如果左移到比target大还配不上就必定配不上了，返回false.

**过程如下所示**：
target:=8

1<<0 = 1
0000 0001

1<<1 = 2
0000 0010

1<<2 = 4
0000 0100

1<<3 = 8  （配上了即可返回true，如果target为7，配到这里大于7且没配上，则返回false）
0000 1000

### 代码

```golang
func isPowerOfTwo(n int) bool {
    for i:=0;(1<<i)<=n;i++{
		if 1<<i == n{
			return true
		}
	}
	return false

}
```