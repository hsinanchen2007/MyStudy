### 解题思路
1. 采用双向链表，标准库container/list提供了双向链表
2. 利用map对链表节点进行索引
3. 记录缓存大小

#### 添加key, value到缓存中
1. 检查map中是否存在key，若存在，则从map中取出该key在链表中对应的item，移动该item到链表队首
2. 若不存在，则将该元素插入链表中，并将对应的链表item写入map中
3. 检查当前链表长度是否超过缓存大小，若超过，则移出链表中队尾元素item，并从map中删除item对应的key

#### 从缓存中读取key对应的value
1. 检查map是否存在该key，如果存在，则将该key对应的链表元素item移到队首，并返回该值

### 代码

```golang
import "container/list"

type LRUCache struct {
    maxentries int
    ll *list.List
    cache map[int]*list.Element
}

type entry struct{
    key int
    value int
}

func Constructor(capacity int) LRUCache {
    return LRUCache{
        maxentries: capacity,
        ll: list.New(),
        cache: make(map[int]*list.Element),
    }
}


func (this *LRUCache) Get(key int) int {
    if this.cache == nil {
        return -1
    }

    if ee, ok := this.cache[key]; ok {
        this.ll.MoveToFront(ee)
        return ee.Value.(*entry).value
    }
    return -1
}


func (this *LRUCache) Put(key int, value int)  {
    if this.cache == nil || this.ll == nil {
        this.cache = make(map[int]*list.Element)
        this.ll = list.New()
    }
    if ee, ok := this.cache[key]; ok {
        ee.Value = &entry{key:key, value: value}
        this.ll.MoveToFront(ee)
        return
    }
    newe := this.ll.PushFront(&entry{key:key, value:value})
    this.cache[key] = newe
    if this.maxentries > 0 && this.ll.Len() > this.maxentries {
        this.removeOldest()
    }
}

func (this *LRUCache) removeOldest() {
    if this.cache == nil {
        return
    }

    ee := this.ll.Back()
    if ee == nil {
        return
    }
    delete(this.cache, ee.Value.(*entry).key)
    this.ll.Remove(ee)
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```