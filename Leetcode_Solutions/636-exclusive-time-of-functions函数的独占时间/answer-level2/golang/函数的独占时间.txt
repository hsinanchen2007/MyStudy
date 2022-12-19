### 解题思路
维护每个调用栈的额外时间

### 代码

```golang
type CallStack struct {
	funcId    int
	startTime int
	extraTime int
}

func exclusiveTime(n int, logs []string) []int {
	result := make([]int, n)
	stack := make([]CallStack, 0, len(logs)/2)

	for _, log := range logs {
		split := strings.Split(log, ":")
		if split[1] == "start" {
			id, _ := strconv.Atoi(split[0])
			st, _ := strconv.Atoi(split[2])
			stack = append(stack, CallStack{
				funcId:    id,
				startTime: st,
				extraTime: 0,
			})
		} else {
			et, _ := strconv.Atoi(split[2])
			cs := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			runtime := et - cs.startTime + 1 - cs.extraTime
			result[cs.funcId] += runtime
			if len(stack) > 0 {
				stack[len(stack)-1].extraTime += et - cs.startTime + 1
			}
		}
	}
	return result
}

```