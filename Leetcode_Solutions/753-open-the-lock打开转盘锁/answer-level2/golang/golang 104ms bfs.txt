解这道题用广度优先遍历需要注意的点：

- 构造一个 map 用于存储`deadends`和`旋转过的字符串`，map 的 value 为旋转的步数
- 初始状态`"0000"`如果在`deadends`中，直接返回-1
- `target`在`deadends`中，直接返回-1
- 初始化一个队列用于存储滚动一次转轮对应的字符串的可能结果（在 map 中的，即**忽略**在`deadends`和`旋转过的字符串`的结果）
- 更新可能结果的步数
- 循环判断队列长度，直到为空

```golang
func openLock(deadends []string, target string) int {
	dMap := make(map[string]int)
	for _, v := range deadends {
        if "0000" == v {
            return -1
        }
		dMap[v] = 0
	}

	if _, ok := dMap[target]; ok {
		return -1
	}

	directs := [2]int{-1, 1}
	queue := []string{"0000"}
	dMap["0000"] = 0
	for len(queue) != 0 {
		wheelStr := queue[0]
		queue = queue[1:]
		step := dMap[wheelStr]

		// 四轮轮流滚动
		for i := 0; i < 4; i++ {
			// 前后滚动
			for _, direct := range directs {
				// 前缀 + 滚动盘 + 后缀
				newWheelStr := wheelStr[0:i] + string((int(wheelStr[i]-'0')+10+direct)%10+'0') + wheelStr[i+1:]
				if _, ok := dMap[newWheelStr]; ok {
					continue
				}

				queue = append(queue, newWheelStr)
				dMap[newWheelStr] = step + 1
				if newWheelStr == target {
					return dMap[newWheelStr]
				}
			}
		}
	}

	return -1
}

```
