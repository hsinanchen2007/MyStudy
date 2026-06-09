### 解题思路

进站时，将用户相关信息存到 map 中，出站时，找到对应的用户，将 出站+进站名作为 key，时间差作为 value 存到第二个 map 中。

查询平均时间时，从第二个 map 中查找就可。


```
type StateIn struct {
	stationName string
	t           int
}
type UndergroundSystem struct {
	tIn  map[int]*StateIn
	tOut map[string][]int
}

func Constructor() UndergroundSystem {
	s := new(UndergroundSystem)
	s.tIn = map[int]*StateIn{}
	s.tOut = map[string][]int{}
	return *s
}

func (this *UndergroundSystem) CheckIn(id int, stationName string, t int) {
	v := &StateIn{stationName, t}
	this.tIn[id] = v
}

func (this *UndergroundSystem) CheckOut(id int, stationName string, t int) {
	stName := ""
	costTime := 0
	s := this.tIn[id]
	stName = s.stationName + stationName
	costTime = t - s.t
	arr := this.tOut[stName]
	arr = append(arr, costTime)
	this.tOut[stName] = arr

}

func (this *UndergroundSystem) GetAverageTime(startStation string, endStation string) float64 {
	stName := startStation + endStation
	arr := this.tOut[stName]
	sum := 0
	for _, v := range arr {
		sum = sum + v
	}
	res := float64(sum) / float64(len(arr))
	return res
}
```