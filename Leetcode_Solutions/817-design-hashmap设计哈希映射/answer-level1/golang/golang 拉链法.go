
```
type LinkNode struct {
	value int
	key   int
	next  *LinkNode
}

// 706 
type MyHashMap struct {
	list [500]LinkNode
}

/** Initialize your data structure here. */
func Constructor() MyHashMap {
		o := MyHashMap{
		list: [500]LinkNode{},
	}
	for i:= 0; i < len(o.list); i++ {
		o.list[i].value = -1
	}
	return o
}

func (this *MyHashMap) hashKey(key int) int {
	M := 101
	return key % M
}

/** value will always be non-negative. */
func (this *MyHashMap) Put(key int, value int) {

	i := this.hashKey(key)
	node := &this.list[i]
	if node.value == -1  || node.key == key{
		node.value = value
		node.key = key
	} else {

		for node.next != nil {

			node = node.next
			if node.key == key {
				node.value = value
				goto NOT
			}
		}

		valNode := LinkNode{
			value: value,
			key:   key,
			next: nil,
		}

		for node.next != nil {
			node = node.next
		}
		node.next = &valNode
	}

	NOT:
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (this *MyHashMap) Get(key int) int {
i := this.hashKey(key)
	node := &this.list[i]

	for node.next != nil {

		if node.key == key {
			return node.value
		} else {
			node = node.next
		}
	}

	if node.key != key {
		return -1
	}

	return node.value
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (this *MyHashMap) Remove(key int) {
	i := this.hashKey(key)
	node := &this.list[i]

	if node.key == key  {

		if node.next == nil {
			*node = LinkNode{
                value: -1,
            }
		} else {
			*node = *node.next
		}

		} else {

		upNode := node

		for node.next != nil {
			upNode = node
			node = node.next
			if node.key == key {
				upNode.next = node.next
				break
			}

		}
	}
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */
```