无限循环
如果盒子不能打开，下次循环继续
如果盒子打开，把有钥匙的盒子置为1，把得到的盒子加入循环中，当前盒子 status 置为 2， 下次不再打开

如果本次循环没有盒子被打开，退出循环
```
func maxCandies(status []int, candies []int, keys [][]int, containedBoxes [][]int, initialBoxes []int) int {
	totalCandies := 0
	boxes := make(map[int]bool)
	for _, b := range initialBoxes {
		boxes[b] = true
	}
	flag := true
	for flag {
		flag = false
		tmpOpen := map[int]bool{}
		for b := range boxes {
			switch status[b] {
			case 0:
				tmpOpen[b] = true
			case 1:
				flag = true
				totalCandies += candies[b]
				for _, k := range keys[b] {
					status[k] = 1
				}
				for _, cb := range containedBoxes[b] {
					tmpOpen[cb] = true
				}
				status[b] = 2
			}
		}
		boxes = tmpOpen
	}
	return totalCandies
}

```
