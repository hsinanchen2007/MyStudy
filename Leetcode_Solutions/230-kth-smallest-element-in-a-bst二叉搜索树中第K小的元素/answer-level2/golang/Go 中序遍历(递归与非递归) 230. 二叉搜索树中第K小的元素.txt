**解题思路：**
对二叉搜索树进行中序遍历，就能得到从小到大进行排序的有序数组arr，第k小的元素即为arr[k-1]
问题简化为对二叉树进行中序遍历
中序遍历可以使用递归和非递归两种方式。

对于中序遍历，递归方法逻辑清晰比较简单，但是必须要遍历整个二叉树，时间复杂度O(n),空间复杂度O(n)；
迭代算法逻辑复杂些，需要使用到栈stack，Golang中可以用container/list来实现，但是能够遍历到第k小的元素后直接返回，时间复杂度和空间复杂度都是O(k), 如果 k << n, 迭代算法会有很大优势

二叉树中序遍历的迭代方案中，也有一种是使用数组数据结构来作为栈
```
type seqStack struct {
	data [100]*TreeNode
	top int // 数组下标
}
```
这种方式需要提前定义好数组大小，虽然能够通过测试，但是有一定局限性

**递归**
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTravel(root *TreeNode) (result []int) {
    if nil == root {
        return []int{}
    }
    
    left := inorderTravel(root.Left)
    right := inorderTravel(root.Right)
    result = append(result, left...)
    result = append(result, root.Val)
    result = append(result, right...)
    
    return result
}
func kthSmallest(root *TreeNode, k int) int {
    arr := inorderTravel(root)
    // fmt.Printf("arr:%v\n", arr)
    return arr[k-1]
}
```


**非递归/迭代-使用container/list包作为stack**

```
func kthSmallest(root *TreeNode, k int) int {
     // inorderTravelsal
	 stack := list.New()
	 stack.PushBack(root)
	 result := []int{}
	 for 0 < stack.Len() || nil != root {
		 if nil != root {
			 stack.PushBack(root)
			 root = root.Left
		 } else {
			 // stack top
			 v := stack.Back()
			 root = v.Value.(*TreeNode) 
			 stack.Remove(v)
			 
			 result = append(result, root.Val)
			 if len(result) > k {
				 return result[k-1]
			 }
			 root = root.Right
		 }
	 }
	 
	 return result[k-1] 
}
```

**二叉树中序遍历-非递归/迭代-使用辅助数组作为stack**
```
type seqStack struct {
	data [100]*TreeNode
	top int // 数组下标
}
func inorderTraversal(root *TreeNode) []int {
    var s seqStack
	s.top = -1 
	if root == nil {
        return []int{}
	}
    
    var result = []int{}
    for root != nil || s.top != -1 {
        if root != nil {
            //stack push 
            s.top++
            s.data[s.top] = root
            
            root = root.Left
        } else {
            //stack pop
            root = s.data[s.top]
            s.top--

            result = append(result, root.Val)
            root = root.Right    
        }
        
    }
	
	return result
}
```
