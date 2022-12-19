### 解题思路
此处撰写解题思路

### 代码

```golang
func game(guess []int, answer []int) int {
    if len(guess) != len(answer) {
		return 0
	}
	count := 0
	for key,value := range guess{
		answerValue := answer[key]
		if answerValue == value{
			count++
		}
	}
	return count
}
```