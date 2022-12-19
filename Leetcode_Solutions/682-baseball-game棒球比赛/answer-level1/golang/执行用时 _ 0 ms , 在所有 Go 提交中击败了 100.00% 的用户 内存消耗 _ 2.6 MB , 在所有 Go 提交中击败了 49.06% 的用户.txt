### 解题思路

把得分和有效数据放入一个栈中，最后对栈求和

利用工具去做的推算
https://www.cs.usfca.edu/~galles/visualization/StackArray.html

### 代码

```golang
func calPoints(ops []string) int {
var stack []int
	for i := 0; i < len(ops); i++ {
		switch ops[i] {
		case "+":
			//2. "+"（一轮的得分）：表示本轮获得的得分是前两轮有效 回合得分的总和。
			if len(stack) == 0 {
				continue
			}
			top1 := stack[len(stack)-1]
			top2 := stack[len(stack)-2]
			score := top1 + top2
			stack = append(stack, score)
		case "D":
			//3. "D"（一轮的得分）：表示本轮获得的得分是前一轮有效 回合得分的两倍。
			if len(stack) == 0 {
				continue
			}
			score := stack[len(stack)-1] * 2
			stack = append(stack, score)
		case "C":
			//4. "C"（一个操作，这不是一个回合的分数）：表示您获得的最后一个有效 回合的分数是无效的，应该被移除。
			//无效操作，移除栈顶
			if len(stack) == 0 {
				continue
			}
			stack = stack[:len(stack)-1]
		default:
			tmp, _ := strconv.Atoi(ops[i])
			stack = append(stack, tmp)
		}
	}

	totalScore := 0
	for j := 0; j < len(stack); j++ {
		totalScore += stack[j]
	}

	return totalScore
}
```