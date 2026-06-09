### 解题思路


### 代码

```golang
func minArray(numbers []int) int {
    // 1.如果数组长度为0
    if len(numbers) == 0 {
        return 0
    }
    for i:= 1;i<len(numbers);i++ {
        //2. 当前数字小于前一个数字
        if numbers[i] < numbers[i-1] {
            return numbers[i]
        }
    }

    return numbers[0]
}

```

```golang

 2 3 4 5 1 

func minArray2(numbers []int) int {
	if len(numbers) == 0 {
		return 0
	}
	left := 0
	right := len(numbers) - 1
	    // 左面的值大于右面的
	for numbers[left] >= numbers[right] && left < right {
		mid := (left + right) / 2
		// 1.左面的值小于中间值
		if numbers[left] < numbers[mid] {
			left = mid + 1
		// 2.左侧的值大于中间值
		} else if numbers[left] > numbers[mid] {
			right = mid
		}else if numbers[left] == numbers[mid]{
			left ++
		}
	}
	return numbers[left]
}
```