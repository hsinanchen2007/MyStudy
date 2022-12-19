# 思考

第一思路 - 走过的坑：

1. 因为给出的行程计划表是**无序**的要排序

```go
// 按照上车的站台顺序排序
	for i := 0; i < len(trips); i++ {
		sort.Slice(trips, func(i, j int) bool {
			return trips[i][1] <= trips[j][1]
		})
	}
```

2. 使用map映射记录有多少乘客在哪些站台需要下车，定义为：

`car := make(map[int]int, capacity)` 

3. 需要一个赋值变量记录车上总人数，如果总人数大于车子的座位数，则不能顺利完成接送所用乘客的任务。

`if total > capacity { 	return false }` 

4. 单次行程的上下车安排
  - 首先判断该站台(以及之前站台是否有人需要下车)

```go
		// 在某一站stations乘客people先下车
		for stations, people := range car {
			if stations <= trips[i][1] {
				total -= people
				delete(car, stations)
			}
		}
```

  - 先下车之后，该站台的乘客上车，此时车上所有人的总数`total += trips[i][0]` 
  - 判断总人数是否大于车子的座位数 `if total > capacity { 	return false}` 
  - 记录该站台上车的乘客需要在哪个站台下车， `car[trips[i][2]] += trips[i][0]` 

# Go实现

## 第一思路
```go
func carPooling(trips [][]int, capacity int) bool {
	// 按照上车的站台顺序排序
	for i := 0; i < len(trips); i++ {
		sort.Slice(trips, func(i, j int) bool {
			return trips[i][1] <= trips[j][1]
		})
	}
	car := make(map[int]int, capacity)
	total := 0 // 车上所有的人
	// 单次行程安排
	for i := 0; i < len(trips); i++ {
		if trips[i][0] > capacity {
			return false
		}
		// 在某一站stations乘客people先下车
		for stations, people := range car {
			if stations <= trips[i][1] {
				total -= people
				delete(car, stations)
			}
		}
		total += trips[i][0] // 在某一站stations乘客people上车之后的总人数
		if total > capacity {
			return false
		}
		car[trips[i][2]] += trips[i][0] // 需要在某一站下车的人数
	}
	return true
}
```

# 学习大佬[@caigogo](/u/caigogo)

```go
func carPooling(trips [][]int, capacity int) bool {
	m := make(map[int]int)
	for _, trip := range trips {
		m[trip[1]] += trip[0] // 记录每一站台上车的乘客
		m[trip[2]] -= trip[0] // 记录每一站台下车的乘客
	}
	for i := 0; i <= 1000; i++ {
		capacity -= m[i] // 每一站台车子的空余座位数
		if capacity < 0 {
			return false
		}
	}
	return true
}
```