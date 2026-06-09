### 解题思路
1. 创建map映射，用于存放目标数组的相关信息；
2. 遍历目标数组，并获取目标值（target）与数组元素（nums[i]）的差值；
3. 将差值当作map的key，目标数组的角标当作value；
4. 判断map中是否包含，如果包含，则返回map的key为差值的value与i；
5. 如果map中不包含，放入map中。

### 代码

```golang
func twoSum(nums []int, target int) []int {
	v := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		dif := target - nums[i]
		c, ok := v[dif]
		if ok != false {
			return []int{c, i}
		}
		v[nums[i]] = i
	}
	return []int{-1,-1}
}
```