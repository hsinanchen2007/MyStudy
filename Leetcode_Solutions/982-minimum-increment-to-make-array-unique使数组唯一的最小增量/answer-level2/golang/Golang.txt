### 解题思路
1. record数组容量初始化为80000（如果A数组含40000个数值为40000的数，扩展后最大值为80000）
2. A数组数据散列到record数组，并计数
3. 从头遍历record数组，如果数值大于1，用结构体记录当前数组位置状态（坐标和数字个数），继续从当前下一个位置寻找空位置，过程中需要记录result结果偏移量的累加和

### 代码

```golang
func minIncrementForUnique(A []int) int {
    if len(A) == 0 {
        return 0
    }
	var record [80000]int
	for j := 0; j < len(A); j++ {
		record[A[j]] += 1
	}
	type curNum struct {
		atRecord int
		count int
	}
	result := 0
	for i := 0; i < 80000; i++ {
		if record[i] > 1 {
			curState := curNum{i, record[i]}
			for j := i+1; j < 80000; j++ {
				if curState.count == 1 {
					break
				}
				if record[j] == 0 {
					curState.count -= 1
					record[j] = 1
					result += j - i
				}
			}
		}
	}
	return result
}
```