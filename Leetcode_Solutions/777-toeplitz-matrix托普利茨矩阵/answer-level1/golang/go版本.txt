### 解题思路
本题解来自公众号**算法和数据结构的峡谷**

辣鸡解法：直接遍历这个二维数组，然后判断只要不是最右侧和最下面的那一列一行数据，就可以使用 k k1 != k+1 k1+1
这个规则。

### 代码

```golang
// 只要 往下再往右跟自己一样就OK了（跟自己一样，或者是空）
func isToeplitzMatrix(matrix [][]int) bool {

	if len(matrix) == 0 {
		return false
	}

	for k, v:= range matrix {
			for k1 := range v {
				if k <len(matrix)-1 && k1 < len(v)-1 {
					if matrix[k][k1] != matrix[k+1][k1+1] {
						return false
					}
				}
			}
	}
	return true
}
```

目前没有想好进阶版本。主要是懒。