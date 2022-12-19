### 解题思路
此处撰写解题思路

### 代码

```golang
type LFUCache struct {
	keyMap map[int]LFUNode
	cap int
    last int
    count int
}

type LFUNode struct{
    value int
    count int
    timer time.Time
}

func Constructor(capacity int) LFUCache {
	keyMap := make(map[int]LFUNode)
    cap:=0
    if capacity > 0{
	    cap = capacity
    }
    lfuCache := LFUCache{keyMap:keyMap,cap:cap,last:-1,count:0}
	return lfuCache
}


func (this *LFUCache) Get(key int) int {
	if this.cap <= 0{
        return -1
    }
    if _,ok := this.keyMap[key];!ok{
		return -1
	}
	lguNode := this.keyMap[key]
    lguNode.count = lguNode.count+1
    lguNode.timer = time.Now()
    this.keyMap[key] = lguNode
	return lguNode.value
}

func (this *LFUCache) Put(key int, value int)  {
    if this.cap <= 0{
        return
    }
	if _,ok := this.keyMap[key];!ok{
		if this.count < this.cap{
			lguNode := LFUNode{}
            lguNode.count = 1
            lguNode.value = value
            lguNode.timer = time.Now()
            this.keyMap[key] = lguNode
            this.count = this.count+1
		}else{
            this.ComputeLast()
            delete(this.keyMap,this.last)
            lguNode := LFUNode{}
            lguNode.count = 1
            lguNode.value = value
            lguNode.timer = time.Now()
            this.keyMap[key] = lguNode
		}
	}else{
        lguNode := this.keyMap[key]
        lguNode.value = value
        lguNode.count = lguNode.count+1
        lguNode.timer = time.Now()
		this.keyMap[key] = lguNode
	}
}

func (this *LFUCache) ComputeLast(){
    min := 999999
    minList := make([]int,0)
    for key,tmp:=range this.keyMap{
        if tmp.count <= min{
            minList = append(minList,key)
            min = tmp.count
        }
    }
    minTime:=time.Now()
    for i:=0;i<len(minList);i++{
        if min == this.keyMap[minList[i]].count && this.keyMap[minList[i]].timer.Nanosecond() < minTime.Nanosecond(){
            minTime = this.keyMap[minList[i]].timer
            this.last = minList[i]
        }
    }
}
```