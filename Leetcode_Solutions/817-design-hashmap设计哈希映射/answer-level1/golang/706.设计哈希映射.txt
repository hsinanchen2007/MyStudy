### 解题思路

用拉链法处理冲突，借用一下官方题解的图，不过我选的表长和取余的数跟官方不同：

![image.png](https://pic.leetcode-cn.com/bb6f30f2b69e1c8b711487200b16ee0725099db6fc8487195be6c2d4c95e86ea-image.png)

### 代码

```golang
type MyHashMap struct {
	hash [1002]List
}
type List struct {
	list []Node
}
type Node struct {
	key int
	value int
}

/** Initialize your data structure here. */
func Constructor() MyHashMap {
	return MyHashMap{
		hash : [1002]List{},
	}
}

/** value will always be non-negative. */
func (this *MyHashMap) Put(key int, value int)  {
	lindex := key % 1001
	for i := 0;i < len(this.hash[lindex].list);i++ {
		if this.hash[lindex].list[i].key == key {
			this.hash[lindex].list[i].value = value
			return
		}
	}
	this.hash[lindex].list = append(this.hash[lindex].list,Node{key : key,value : value,})
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (this *MyHashMap) Get(key int) int {
	lindex := key % 1001
	for i := 0;i < len(this.hash[lindex].list);i++ {
		if this.hash[lindex].list[i].key == key {
			return this.hash[lindex].list[i].value
		}
	}
	return -1
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (this *MyHashMap) Remove(key int)  {
	lindex := key % 1001
	for i := 0;i < len(this.hash[lindex].list);i++ {
		if this.hash[lindex].list[i].key == key {
			this.hash[lindex].list = append(this.hash[lindex].list[:i],this.hash[lindex].list[i + 1:]...)
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