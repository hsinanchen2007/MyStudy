首先我们看一下不能成为朋友的3个条件
```
1.age[B] <= 0.5 * age[A] + 7
2.age[B] > age[A]
3.age[B] > 100 && age[A] < 100
```
把3个条件全部反过来就是可以成为朋友的要求（条件2包含条件3，所以条件3忽略），即：

`0.5 * age[A] + 7 < age[B] <= age[A]`

因为年龄只有1-120，所以我们只要统计各年龄人数，然后计算满足条件的人数即可
```
for i := 0; i < len(ages); i++ {
	ageCount[ages[i]]++ // 计算各年龄人数
}
for i := 1; i < 121; i++ {
	ageCount[i] += ageCount[i-1] // 优化：计算出年龄段的最大和最小值，直接 头 -（尾-1）得到区间内的总人数
}
```

完整代码
```
func numFriendRequests(ages []int) int {
	ageCount := [121]int{}
	for i := 0; i < len(ages); i++ {
		ageCount[ages[i]]++
	}
	for i := 1; i < 121; i++ {
		ageCount[i] += ageCount[i-1]
	}
	ret := 0
	for i := 0; i < len(ages); i++ {
		low, high := int(0.5 * float64(ages[i])) + 7, ages[i] // 计算条件内的最大最小值
		if low >= high {
			continue
		}
		if ages[i] > low && ages[i] <= high { // 需要减去自身
			ret--
		}
		ret += ageCount[high] - ageCount[low] // 计算区间内的人数
	}
	return ret
}
```
