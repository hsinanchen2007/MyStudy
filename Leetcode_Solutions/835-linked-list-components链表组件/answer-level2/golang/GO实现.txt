

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func numComponents(head *ListNode, G []int) int {
    set := NewSet(G)
	iterator := head
	compentCount := 0
	for iterator != nil {
		if set.Contain(iterator.Val) && (iterator.Next == nil || !set.Contain(iterator.Next.Val) ) {
			compentCount++
		}
		iterator = iterator.Next
	}
	return compentCount
}

type Set struct {
	elements map[int]bool
}

func NewSet(nums []int) (*Set){
	set := &Set{
		elements: make(map[int]bool, len(nums)),
	}
	for _, v := range nums {
		set.elements[v] = true
	}
	return set
}

func (this *Set) Add(val int) {
	this.elements[val] = true
}

func (this *Set) Contain(val int) bool {
	_, ok := this.elements[val]
	return ok
}
```

### 执行结果
![image.png](https://pic.leetcode-cn.com/58b0e798542ad2e890828a19fa04e72c54823ec2315d206f89760c9e007d9d62-image.png)
