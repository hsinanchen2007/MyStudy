### 解题思路
map + 双向链表

golang原生支持map，标准库container中有双向链表list支持

### 代码

```golang
import "container/list"
type item struct {
    k int
    v int
}

type LRUCache struct {
    cap int
    mp map[int]*list.Element
    lst *list.List
}


func Constructor(capacity int) LRUCache {
    return LRUCache{
        cap: capacity,
        mp: make(map[int]*list.Element),
        lst: list.New(),
    }    
}


func (this *LRUCache) Get(key int) int {
    if _, ok := this.mp[key]; !ok {
        return -1
    }
    kv := this.lst.Remove(this.mp[key]).(item)
    this.mp[key] = this.lst.PushFront(kv)
    return kv.v    
}


func (this *LRUCache) Put(key int, value int)  {
    if _, ok := this.mp[key]; ok {
        this.lst.Remove(this.mp[key])
    } else if len(this.mp) == this.cap {
        back := this.lst.Back()
        backKV := back.Value.(item)
        this.lst.Remove(back)
        delete(this.mp, backKV.k)
    }
    this.mp[key] = this.lst.PushFront(item{k: key, v: value})
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```