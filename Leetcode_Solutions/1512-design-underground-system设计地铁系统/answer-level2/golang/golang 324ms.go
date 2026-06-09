### 解题思路
![image.png](https://pic.leetcode-cn.com/9e3a66d676fd6ad61f73a5f63fa1cb1b55ccbfe8b562691a98becedd0bd7288e-image.png)
1. 通过byID记录每个乘客的所有进出站记录；
2. 通过byName记录每个车站的所有进出记录；
3. 遍历所有起始站的进站乘客，并且校验该乘客是否在结束站出站；

### 代码

```golang
type UndergroundSystem struct {
    byID map[int][]record
    byName map[string]map[int]uint
}

type record struct {
    name string
    t int
    flag uint
}

func Constructor() UndergroundSystem {
    return UndergroundSystem {
        byID: make(map[int][]record, 2),
        byName: make(map[string]map[int]uint, 2),
    }
}

func (this *UndergroundSystem) checkHelp(id int, stationName string, t int, flag uint) {
    r := record {stationName, t, flag}
    items, ok := this.byID[id]
    if !ok {
        items = []record { r }
    } else {
        items = append(items, r)
    }
    this.byID[id] = items
    names, ok := this.byName[stationName]
    if !ok {
        names = make(map[int]uint, 1)
        names[id] = flag
    } else {
        tflag, ok := names[id]
        if ok {
            names[id] = tflag | flag
        } else {
            names[id] = flag
        }
    }
    this.byName[stationName] = names
}

func (this *UndergroundSystem) CheckIn(id int, stationName string, t int)  {
    this.checkHelp(id, stationName, t, 1)
}


func (this *UndergroundSystem) CheckOut(id int, stationName string, t int)  {
    this.checkHelp(id, stationName, t, 2)
}


func (this *UndergroundSystem) GetAverageTime(startStation string, endStation string) float64 {
    var total float64
    cnt := 0
    starts, ok := this.byName[startStation]
    if !ok {
        return 0.0
    }
    ends, ok := this.byName[endStation]
    if !ok {
        return 0.0
    }
    for sk, sv := range starts {
        if sv & 1 == 0 {
            continue
        }
        tflag, found := ends[sk]
        if !found || (tflag & 2) == 0 {
            continue
        }

        records, ok := this.byID[sk]
        if !ok {
            continue
        }
        for i := 0; i < len(records) - 1; i++ {
            if records[i].name == startStation && (records[i].flag & 1 != 0) {
                if records[i+1].name == endStation && (records[i+1].flag & 2 != 0) {
                    cnt++
                    total += float64(records[i+1].t - records[i].t)
                }
            }
        }
    }
    //fmt.Printf("%v\n%v\n", this.byID, this.byName)
    if cnt == 0 {
        return 0.0
    }
    return total / float64(cnt)
}


/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * obj := Constructor();
 * obj.CheckIn(id,stationName,t);
 * obj.CheckOut(id,stationName,t);
 * param_3 := obj.GetAverageTime(startStation,endStation);
 */
```