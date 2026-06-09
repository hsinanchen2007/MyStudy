1：先判断某点需要几步：m = x + y
2：判断m步中有多少个R和U,如果R的数量等于x并且,U的数量等于y，则该点在路径上；否则不在路径上

```
func robot(command string, obstacles [][]int, x int, y int) bool {
	// 如果目标点不在路径上，返回失败
	if !isOnThePath(command, x, y) {
		return false
	}
	for _, o := range obstacles {
		// 判断有效的故障点是否在路径上（故障的步数大于等于目标的点，视为无效故障）
		if (x+y > o[0]+o[1]) && isOnThePath(command, o[0], o[1]) {
			return false
		}
	}
	return true
}

func isOnThePath(command string, x int, y int) bool {
	uNum := strings.Count(command, "U")*((x+y)/len(command)) + strings.Count(command[0:(x+y)%len(command)], "U")
	rNum := strings.Count(command, "R")*((x+y)/len(command)) + strings.Count(command[0:(x+y)%len(command)], "R")
	if uNum == y && rNum == x {
		return true
	}
	return false
}
```
运行结果：
![image.png](https://pic.leetcode-cn.com/19b72055b0855dd6f6ce5d4e27b562dabf02ce0dcbf9b6b785c09f45f6808fad-image.png)
