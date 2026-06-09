### 解题思路
解题思路很一般，没啥好说的。
重点是利用map。
然后在go中没有null值，在一个只初始化没有赋值的map中，去获取一个没有的key，返回的也是0！！！！
坑爹啊！
所以取巧了，在index 处 都加上1 ，所以就不存在 0 位，故，如果从map中取出的值为0，就可以确定当前值在map中不存在。

还是被困扰了一会。

### 代码

```golang
func twoSum(nums []int, target int) []int{
	numMap := make(map[int]int)

	result := make([]int , 2, 2)
	// o(N) 时间复杂度
	for index, value := range nums {
		temp_value := target - value
		temp_index := numMap[temp_value]
		if temp_index != 0 {
			result[0] = index
			result[1] = temp_index -1
			break
		}
		numMap[value] = index + 1
	}

	return result
}
```