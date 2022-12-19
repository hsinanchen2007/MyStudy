这道题很简单，新建can数组，元素初始值为1.
从左向右遍历，如果ratings[i] > ratings[i-1]且can[i] <= can[i-1]即当前评分比左侧高且糖果不高于左侧，则将can[i] = can[i-1] + 1.
从右向左遍历，同理，只和右侧对比，并更新当前的糖果.
左右两个方向遍历更新后，即可保证了i和左右两侧的都满足条件。

```

// 左右两个方向更新一次即可
func candy(ratings []int) int {
	can := make([]int, len(ratings))
	for i := 0; i < len(ratings); i++ {
		can[i] = 1
		if i == 0 {
			continue
		}
		if ratings[i] > ratings[i-1] && can[i] <= can[i-1] {
			can[i] = can[i-1] + 1
		}
	}
	for i := len(ratings) -2; i >=0; i-- {

		if ratings[i] > ratings[i+1] && can[i] <= can[i+1] {
			can[i] = can[i+1] + 1
		}

	}
	sum := 0
	for i := 0; i < len(can); i++ {
		sum += can[i]
	}
	return sum
}


```