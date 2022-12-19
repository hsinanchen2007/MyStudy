### 解题思路
此处撰写解题思路
2 => 2
3 => 2
4 => 2x2
5 => 2x3
6 => 3x3
7 => 2x2x3
8 => 2x3x3
9 => 3x3x3
10=> 2x2x3x3

如果是3的倍数 就是拆分成3的乘积
否则就是尽量将值分散到2和3  
举个例子2*2*2 比3*3小

![截屏2020-02-15下午5.20.19.png](https://pic.leetcode-cn.com/6183ad01eb36fbad3c41529ec969ae7132998f9430a7e9c92c4d6dd8f349e924-%E6%88%AA%E5%B1%8F2020-02-15%E4%B8%8B%E5%8D%885.20.19.png)


### 代码

```golang
func integerBreak(n int) int {
	if n == 2 {
		return 1
	}
	if n == 3 {
		return 2
	}
	x := n % 3
	if x == 0 {
		return int(math.Pow(3, float64(n/3)))
	} else if x == 1 {
		return 4 * int(math.Pow(3, float64((n-4)/3)))
	} else {
		return 2 * int(math.Pow(3, float64((n-2)/3)))
	}
}
```