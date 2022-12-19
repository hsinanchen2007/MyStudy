### 解题思路
没啥好说的，根据题意设置好对应关系计算就行

### 代码

```golang
type UndergroundSystem struct {
    
    idTime map[int]float64
    idIn map[int]string
//     idOut map[int]m
    count map[string]map[string]int
    aveTime map[string]map[string]float64
}


func Constructor() UndergroundSystem {
    t := new(UndergroundSystem)
    t.idTime = make(map[int]float64)
    t.idIn = make(map[int]string)
    t.aveTime = make(map[string]map[string]float64)
    t.count = make(map[string]map[string]int)
    return *t
}


func (this *UndergroundSystem) CheckIn(id int, stationName string, t int)  {
    this.idTime[id] = float64(t)
    this.idIn[id] = stationName
}


func (this *UndergroundSystem) CheckOut(id int, stationName string, t int)  {
    start := this.idTime[id]
    source := this.idIn[id]
    sum := float64(t) - start
    if _,ok := this.count[source]; !ok {
        m := make(map[string]int)
        this.count[source] = m
        m[stationName]++
    } else if ok {
        this.count[source][stationName]++
    }
    if _,ok := this.aveTime[source]; !ok {
        m := make(map[string]float64)
        this.aveTime[source] = m
        m[stationName] += sum
    } else if ok {
        this.aveTime[source][stationName] += sum 
    }
}


func (this *UndergroundSystem) GetAverageTime(startStation string, endStation string) float64 {
    res := float64(this.aveTime[startStation][endStation] / float64(this.count[startStation][endStation]))
    return res
}


/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * obj := Constructor();
 * obj.CheckIn(id,stationName,t);
 * obj.CheckOut(id,stationName,t);
 * param_3 := obj.GetAverageTime(startStation,endStation);
 */
```