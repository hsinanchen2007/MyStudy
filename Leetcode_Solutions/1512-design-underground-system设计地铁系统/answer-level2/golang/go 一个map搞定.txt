
```
type UndergroundSystem struct {
	station map[string]map[int]int
}

func Constructor() UndergroundSystem {
	obj := make(map[string]map[int]int)
	return UndergroundSystem{station:obj}
}


func (this *UndergroundSystem) CheckIn(id int, stationName string, t int)  {
	if this.station[stationName] == nil{
		this.station[stationName] = make(map[int]int)
	}
	this.station[stationName][id] = t
}


func (this *UndergroundSystem) CheckOut(id int, stationName string, t int)  {
	if this.station[stationName] == nil{
		this.station[stationName] = make(map[int]int)
	}
	this.station[stationName][id] = t
}


func (this *UndergroundSystem) GetAverageTime(startStation string, endStation string) float64 {
	sum := 0.0
	count := 0.0
	mpstart := this.station[startStation]
	mpend := this.station[endStation]
	for id,t := range mpstart{

		if mpend[id] != 0{
			count ++
			sum = sum - float64(t) + float64(mpend[id])
		}
	}
	

	return sum/count
}
```
