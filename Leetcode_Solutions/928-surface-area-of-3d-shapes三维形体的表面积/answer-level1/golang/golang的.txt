```
func surfaceArea(grid [][]int) int {
	ans := 0
	lenY := len(grid)
	if lenY == 0 {
		return ans
	}
	lenX := len(grid[0])
	for i := 0; i < lenY; i++ {
		for j := 0; j < lenX; j++ {
			//遍历每个坐标
			if grid[i][j] == 0 {
				continue
			}
			//每个方块前后左右各有一面,总的上下各有一面,所以4*方块数加上下2
			ans += grid[i][j]*4 + 2
			//每个格子只需要看后方和右方,全部遍历完就把前后左右的接触面都处理了
			if j+1 < lenX {
				//x轴后方如果有方块堆,则看矮的有几个,两边各少2倍矮个数的面数
				ans -= lessOne(grid[i][j+1], grid[i][j]) * 2
			}
			if i+1 < lenY {
				//y轴同理
				ans -= lessOne(grid[i+1][j], grid[i][j]) * 2
			}
		}
	}
	return ans
}
//取更矮的
func lessOne(x, y int) int {
	if x < y {
		return x
	}
	return y
}
```
![搜狗截图20年01月11日1426_1.png](https://pic.leetcode-cn.com/1bf06330a8848744cd5f7960a9b419ce2d04265323a577d2385b598b78d33099-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B401%E6%9C%8811%E6%97%A51426_1.png)

