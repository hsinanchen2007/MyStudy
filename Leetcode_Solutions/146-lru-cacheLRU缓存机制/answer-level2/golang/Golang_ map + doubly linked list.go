本来是用两个map来解决的，但是效率不是很高，参考了最佳答案，改为map + doubly linked list

```golang
import "container/list"

type Node struct {
    Key int
    Val int
}

type LRUCache struct {
    capacity int
    cache map[int]*list.Element
    lru *list.List
}

func Constructor(capacity int) LRUCache {
    
    return LRUCache{
        capacity: capacity,
        cache: make(map[int]*list.Element, capacity),
        lru: list.New(),
    }
    
}

func (this *LRUCache) Get(key int) int {
    if ele, ok := this.cache[key]; ok {
        this.lru.MoveToBack(ele)
        // java有泛型，而go只能interface满天飞
        return ele.Value.(Node).Val
    }
    return -1
}

func (this *LRUCache) Put(key int, value int)  {

    if ele, ok := this.cache[key]; ok {
        this.lru.Remove(ele)
    } else if len(this.cache) >= this.capacity {
        front := this.lru.Front()
        this.lru.Remove(front)
        delete(this.cache, front.Value.(Node).Key)
    }
    
    node := Node{Key: key, Val: value}
    // 这里需要注意的是，先把节点写入链表，拿到返回的指针
    // 再把指针写入hash map，因为后续的Remove，MoveToBack操作都需要节点的指针
    ele := this.lru.PushBack(node)
    
    this.cache[key] = ele
}
```
