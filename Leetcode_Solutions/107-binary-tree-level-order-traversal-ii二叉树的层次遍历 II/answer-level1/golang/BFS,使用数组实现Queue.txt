### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 type Queue struct {
	Data []interface{}
}

func (self *Queue) PushBack(val interface{}) {
	self.Data = append(self.Data, val)
}

func (self *Queue) PopFront() interface{} {
	if len(self.Data) == 0 {
		return nil
	}
	tmp := self.Data[0]
	self.Data = self.Data[1:]
	return tmp
}

func (self *Queue) Size() int {
	return len(self.Data)
}

func (self *Queue) Empty() bool {
	return len(self.Data) == 0
}


func levelOrderBottom(root *TreeNode) [][]int {
	res := make([][]int, 0)
    if root ==nil {
        return res 
    }
	q := Queue{Data: make([]interface{}, 0)}
	q.PushBack(root)

	for !q.Empty() {
		levelRes := make([]int, 0)
        size := q.Size()
		for i := 0; i < size; i++ {
			cur := q.PopFront().(*TreeNode)
			levelRes = append(levelRes, cur.Val)

			if cur.Left != nil {
				q.PushBack(cur.Left)
			}
			if cur.Right != nil {
				q.PushBack(cur.Right)
			}
		}
        res = append(res, levelRes)
	}

	left := 0
	right := len(res) - 1

	for right > left {
		res[right], res[left] = res[left], res[right]
		right--
		left++
	}

	return res

}
```