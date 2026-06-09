### 解题思路
从某一点开始,连接另一个点,将圆分割成两部分,这两部分分别是两个子问题,使用递归求解

### 代码

```golang
var valueRecord = map[int]int{}
var modNum = int(math.Pow(10, 9) + 0.5 + 7)

func numberOfWays(numPeople int) int {
	if numPeople == 0 || numPeople == 2 {
		return 1

	} else if res, ok := valueRecord[numPeople]; ok {
		return res
	} else {
		peopleR := numPeople - 2
		peopleL := 0
		sum := 0
		for peopleR >= 0 {
			sum = sum + (numberOfWays(peopleR)*numberOfWays(peopleL))%modNum
			sum = sum % modNum
			peopleL += 2
			peopleR -= 2
		}
		valueRecord[numPeople] = sum
		return sum
	}
}
```