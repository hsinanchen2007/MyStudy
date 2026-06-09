### 解题思路

以题目所给例子为例：
初始状态, M = 
![image.png](https://pic.leetcode-cn.com/c8f79e2a90e6147d2ce2955a296f67b111980d9fcdb818aa69380290d9c94786-image.png)
执行操作[2,2]，相当于2×2矩形内元素+1
![image.png](https://pic.leetcode-cn.com/a470c0cbbe6f00ef5e8002071e2fcd3d17f38efaf5ccdf64ee3087efe17d9eb2-image.png)
执行操作[3,3]，相当于3×3矩形内元素加+1
![image.png](https://pic.leetcode-cn.com/31ac019b5bb71b2f66ab4a5ff3de369fe81b9a5b1825d6081a161d21633cbf9c-image.png)
结果为：
![image.png](https://pic.leetcode-cn.com/1425dc540012b4e47378b0c48c875d7f3c1799a51132c20fe58627b9224f4166-image.png)

**可以发现，只要求出所有矩形的公共重叠面积，即为最大元素的个数。**

即算出行和列的操作的最小值，相乘即可。若不做操作（即ops数组为空）则整个数组元素一样大，都为0，返回整个数组元素数m*n

### 代码

```golang
func maxCount(m int, n int, ops [][]int) int {
	if len(ops) == 0 {
		return m * n
	}
	rmin,cmin := math.MaxInt64,math.MaxInt64
	for i := 0;i < len(ops);i++ {
		if ops[i][0] < rmin {
			rmin = ops[i][0]
		}
		if ops[i][1] < cmin {
			cmin = ops[i][1]
		}
	}
	return cmin * rmin
}
```