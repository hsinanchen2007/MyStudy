### 解题思路
此处撰写解题思路

### 代码

```golang
type LFUCache struct {
key,val,freq int
}

var gminFreq, gcapatity int
var key_table map[int] *list.Element
var freq_table map[int] *list.List //*LFUCache
var synch chan int

func Constructor(capacity int) LFUCache {
	//初始化大小为0

	gminFreq = 0
	gcapatity = capacity
	key_table = make(map[int]*list.Element)
	freq_table = make(map[int]*list.List)
	synch = make(chan int ,1 )
	return LFUCache{}
}



func (this *LFUCache) Get(key int) int {
	if gcapatity <= 0{
		return -1
	}
	if f, ok := key_table[key];ok{
		//1. freq 增加
		stu :=f.Value.(LFUCache)
		val := stu.val
		freq := stu.freq

		synch <- 1
		//2. 频率表先删除再增加;
		if freq, ok := freq_table[freq];ok{
			freq.Remove(f)
		}

		//链表长度为 0 则要删除 && 更新 minFreq
		if freq_table[freq].Len() == 0 {
			delete(freq_table, freq)
			if gminFreq == freq{ //当前是最小的频次则更新最小频次; ???
				gminFreq += 1
			}
		}
		//3. 更新节点的freq频次
		newFreq := freq+1
		if freq_table[newFreq] == nil{
			freq_table[newFreq] = list.New()
		}
		freq_table[newFreq].PushFront(LFUCache{key:key, val:val, freq:newFreq})
		//指向新的节点的地址;
		key_table[key] = freq_table[newFreq].Front()
		<- synch

		return val

	}
	return -1
}


func (this *LFUCache) Put(key int, value int)  {
	if gcapatity <= 0{
		return
	}
	pnode := key_table[key]
	newfreq :=  -1
	synch <- 1
	if pnode == nil{
		//节点不存再，看是否已满
		if len(key_table) == gcapatity{
			//先删除key表，此时get不到了;

			if freq, ok := freq_table[gminFreq]; ok{
				del := freq.Back()
				delete(key_table, del.Value.(LFUCache).key)
				freq.Remove(del) //删除尾节点;
				if freq_table[gminFreq].Len() == 0{
					delete(freq_table, gminFreq)
				}
			}
		}
		newfreq = 1
		gminFreq = 1
	}else{
		//更新频次, 先删除 再添加节点
		freq := pnode.Value.(LFUCache).freq
		(freq_table[freq]).Remove(pnode)
		if freq_table[freq].Len() == 0{
			delete(freq_table, freq)
			if gminFreq == freq{ //当前是最小的频次则更新最小频次; ???
				gminFreq += 1
			}
		}
		newfreq = freq+1
	}

	newnode := LFUCache{key:key, val:value, freq:newfreq}
	if freq_table[newfreq] == nil{
		freq_table[newfreq] = list.New()
	}
	freq_table[newfreq].PushFront(newnode)
	key_table[key] = freq_table[newfreq].Front()	//指向新的节点的地址;
	<- synch
}



/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```