1、暴利求解方式：

```

func twoSum(nums []int, target int) []int {
	res := make([]int, 2)
	for key, value := range nums {
		res[0] = key
		v := target - value
		for i := key + 1; i < len(nums); i++ {
			if nums[i] == v {
				res[1] = i
				return res
			}
		}
	}

	return nil

}
```

2、map 方式：
```

func twoSum(nums []int, target int) []int {
	tmp := make(map[int]int)
	res := make([]int, 2)

	for k, v := range nums {
		tmp[v] = k
	}

	for k, v := range nums {
		res[0] = k
		value := target - v
		index, ok := tmp[value]
		if ok && index != k {
			res[1] = index
			break
		}
	}

	return res
}
```

