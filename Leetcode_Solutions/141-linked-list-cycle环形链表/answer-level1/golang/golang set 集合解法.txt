Golang 原生并不支持集合结构，所以我们需要自己实现集合。

解题思路：
遍历所有节点，并将没有走过的节点放入集合。如果放入过程中发现元素已经存在，那说明已经走过这个节点，即找到了环。

时间复杂度：O(n)，对于含有 n 个元素的链表，我们访问每个元素最多一次。添加一个结点到哈希表中只需要花费 O(1) 的时间。
空间复杂度：O(n)，空间取决于添加到哈希表中的元素数目，最多可以添加 n 个元素。
```go []
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    s := NewHashSet()
	for head != nil {
		if s.Contains(head){
			return true
		}
		s.Add(head)
		head = head.Next
	}
	return false
}

type HashSet struct {
	m map[interface{}]bool
}

func NewHashSet() *HashSet {
	return &HashSet{m: make(map[interface{}]bool)}
}

//添加    true 添加成功 false 添加失败
func (set *HashSet) Add(e interface{}) (b bool) {
	if !set.m[e] {
		set.m[e] = true
		return true
	}
	return false
}

//是否包含
func (set *HashSet) Contains(e interface{}) bool {
	return set.m[e]
}
```
