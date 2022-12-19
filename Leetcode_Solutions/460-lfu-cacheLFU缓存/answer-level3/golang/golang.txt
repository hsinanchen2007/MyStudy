```
package main

import "fmt"

// Node struct
type Node struct {
	key, value int
	num        int   // 调用次数
	prev, next *Node // 前序，后继指针，为双重链表做准备
}

// DoubleList prepare for freeList
type DoubleList struct {
	head, tail *Node
}

// ConstructorDB init
func ConstructorDB() *DoubleList {
	head, tail := &Node{}, &Node{}
	head.next, tail.prev = tail, head
	return &DoubleList{
		head: head,
		tail: tail,
	}
}

// LFUCache struct
type LFUCache struct {
	capacity int
	rest     int // 剩余容量
	minFreq  int // 当前最少num
	cache    map[int]*Node
	freqList map[int]*DoubleList // key是调用的num，每个建对应的值是一个链表,越靠近头结点调用的越近
}

// Constructor init
func Constructor(capacity int) LFUCache {
	return LFUCache{
		capacity: capacity,
		rest:     capacity,
		cache:    make(map[int]*Node),
		freqList: make(map[int]*DoubleList),
		minFreq:  0,
	}
}

// Remove node from DoubleList
func (p *DoubleList) Remove(node *Node) {
	node.prev.next = node.next
	node.next.prev = node.prev
	node.next = nil
	node.prev = nil
}

// IsEmpty -> Judge if DoubleList is empty
func (p *DoubleList) IsEmpty() bool {
	return p.head.next == p.tail
}

// AddNode -> add node to doubleList
func (p *DoubleList) AddNode(node *Node) {
	node.next = p.head.next
	node.prev = p.head
	p.head.next.prev = node
	p.head.next = node
}

// UpdateFre freeList
func (p *LFUCache) UpdateFre(node *Node) {
	freq := node.num
	p.freqList[freq].Remove(node)
	// Judge if its num is min
	if p.minFreq == freq && p.freqList[freq].IsEmpty() {
		p.minFreq++
		delete(p.freqList, freq)
	}
	node.num++
	if p.freqList[node.num] == nil {
		p.freqList[node.num] = ConstructorDB()
	}
	p.freqList[node.num].AddNode(node)
}

// Get output
func (p *LFUCache) Get(key int) int {
	node, ok := p.cache[key]
	if ok {
		p.UpdateFre(node)
		return node.value
	}
	return -1
}

// RemoveLast -> remove last node
func (p *DoubleList) RemoveLast() *Node {
	if p.IsEmpty() {
		return nil
	}
	last := p.tail.prev
	p.Remove(last)
	return last
}

// Put input
func (p *LFUCache) Put(key int, value int) {
	if p.capacity == 0 {
		return
	}
	node, ok := p.cache[key]
	if ok {
		node.value = value
		p.UpdateFre(node)
	} else {
		if p.rest == 0 {
			node := p.freqList[p.minFreq].RemoveLast()
			delete(p.cache, node.key)
			p.rest++
		}
		temp := &Node{key: key, value: value, num: 1}
		p.cache[key] = temp
		if p.freqList[1] == nil {
			p.freqList[1] = ConstructorDB()
		}
		p.freqList[1].AddNode(temp)
		p.minFreq = 1
		p.rest--
	}
}

func main() {
	cache := Constructor(2)
	cache.Put(1, 1)
	cache.Put(2, 2)
	fmt.Println(cache.Get(1)) // 返回 1
	cache.Put(3, 3)           // 去除 key 2
	fmt.Println(cache.Get(2)) // 返回 -1 (未找到key 2)
	fmt.Println(cache.Get(3)) // 返回 3
	cache.Put(4, 4)           // 去除 key 1
	fmt.Println(cache.Get(1)) // 返回 -1 (未找到 key 1)
	fmt.Println(cache.Get(3)) // 返回 3
	fmt.Println(cache.Get(4)) // 返回 4
}

```
