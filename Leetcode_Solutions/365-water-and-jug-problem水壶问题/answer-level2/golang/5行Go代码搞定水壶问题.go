看了那么多人提到最大公约数，但没怎么介绍推导过程，我就介绍推导过程。

# 推导公式
调整 x,  y，使得 x >= y

由水壶 y 往水壶 x 灌水，最多能灌水 a 次，水壶 x 还剩余 x1 空间。得出公式：
1. Fx(n) = a * Fy(n) + Fx(n+1)，Fx(n+1)  < Fy(n)，a 为整数
2. Fx(n+1) = Fx(n) % Fy(n)，Fy(n) != 0

此时问题变成：**如何用 Fx(n+1) 与 Fy(n) 算出 Fz(n) 来？**
即：**如何用水壶 x 剩余空间和水壶 y 来算出 z**
套用公式 1，得出：
3. Fy(n) = b * Fx(n+1) + Fy(n+1)，且一定有：b 为整数，Fy(n+1) < Fx(n+1)
4. Fy(n+1) = Fy(n)%Fx(n+1)，Fx(n+1) != 0

而 z 与 y 的关系必然有：
5. Fz(n) = c * Fy(n) + Fz(n+1)，且一定有：c 为整数，Fz(n+1) < Fy(n)
6. Fz(n+1) = Fz(n) % Fy(n)， Fy(n) != 0

如果用 x 和 y 能算出 z 来，结束条件必须是 Fz(n) 需要能收敛到 0。如果 Fy(n) 先于 Fz(n)收敛 到 0，则Fz(n) 是无法收敛到 0 的，因为 Fz(n) % 0 无意义。Fz(n) 先于 Fy(n) 收敛到 0 的条件是 Fy(n) 先达到 1，因为任何整数对 1 取模都是 0。

# 条件
如果 z 能用 x 和 y 算出来，必定满足 z <= x + y，加上前面的收敛条件，所以，迭代条件是：
1. z <= x + y
2. y != 0
3. z != 0

返回 true 的条件是：
1. z == 0 或者 z == x + y


# 代码
根据公式 2、4、6，写出递归版代码：
```go
func canMeasureWater(x int, y int, z int) bool {
	if z == 0 || z == x+y {   // 条件 1
		return true
	} else if z > x+y || y == 0 {  // 条件 2 和 3
		return false
	}

    // 迭代公式 2、 4、 6
	return canMeasureWater(y, x%y, z%y)
}
```

终极 for 循环版：
```go
func canMeasureWater(x int, y int, z int) bool {
	for ; z != 0 && y != 0 && z < x+y; x, y, z = y, x%y, z%y {
	}
	return z == 0 || z == x + y
}
```

# 效果
![image.png](https://pic.leetcode-cn.com/289ac643f101a7186de491f149a737e4fc6c3c66855731e2eb618d3dfdaaebbe-image.png)


# 总结
1. 用go来解题，5 行搞定，充分体现了 Go 语言的魅力。
2. 递归解法条理清晰
3. for 循环版代码最少