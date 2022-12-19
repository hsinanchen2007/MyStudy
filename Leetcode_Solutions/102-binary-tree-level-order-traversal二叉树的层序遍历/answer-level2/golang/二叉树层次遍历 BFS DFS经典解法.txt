### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/26a8aaabb739818b2b2bb46da92282545f61b249eda397b1c7951d0db3179d20-image.png)
图来自《算法⾯面试通关40讲》
1 维护queue
2 循环queue 取出queue元素
3 处理，生成新元素加到queue
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
func levelOrder(root *TreeNode) [][]int {
    result := make([][]int, 0)
    if root == nil {
		return result
	}
    //visited := make(map[string]string)
    // Create a queue.
	queue := make([]*TreeNode, 0)
	// Enqueue the root note
	queue = append(queue, root)
    for len(queue) > 0 {
        level_size := len(queue)
        current_level := make([]int, 0)
        for level_size > 0 {
            node := queue[0]
            current_level=append(current_level,node.Val)
			queue = queue[1:]
            if node.Left != nil{
                queue= append(queue,node.Left)
            }
            if node.Right != nil{
                queue=append(queue,node.Right)
            }
            level_size--
        }
        result=append(result,current_level) 
    }
    return result
}
```
DFS
```
func levelOrder(root *TreeNode) [][]int {
    result := make([][]int, 0)
    var _dfs func(root *TreeNode, level int)
    _dfs = func(root *TreeNode, level int) {
        if root == nil {
            return
        }
        if len(result) == level{
            result = append(result,[]int{})
        }
        result[level] = append(result[level],root.Val)
        _dfs(root.Left,level + 1)
        _dfs(root.Right,level + 1)
    }
    _dfs(root,0)
    return result
}
```