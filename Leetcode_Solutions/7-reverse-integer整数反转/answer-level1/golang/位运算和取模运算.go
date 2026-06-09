### 解题思路
此处撰写解题思路

### 代码

```golang

func reverse(x int) int {
	rlt := 0

	for x != 0 {
		rlt = rlt*10 + x%10
        if !(rlt <= 1<<31 - 1 && rlt >= -(1<<31)) {
			return 0
		}
		x = x/10
	}
	return rlt
}
```