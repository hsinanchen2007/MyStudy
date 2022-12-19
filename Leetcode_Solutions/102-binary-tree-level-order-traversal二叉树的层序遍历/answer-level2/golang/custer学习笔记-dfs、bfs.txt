# 思考

1. BFS，判断level层是否结束，Batch process，时间复杂度O(N)
1. DFS，二维数组，是每层的子数组

# Go代码BFS

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    return bfsLevelOrder(root)
}
func bfsLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}

	queue := make([]*TreeNode, 0) // 申请一个队列
	queue = append(queue, root)   // 头部插入
	levels := make([][]int, 0)

	for len(queue) > 0 { // level记录当前层次所有节点
		n, level := len(queue), make([]int, 0)
		for i := 0; i < n; i++ {
			root = queue[0]   // 取队首元素
			queue = queue[1:] // 删除队首元素

			level = append(level, root.Val) // 将当前层的所有节点加入结果数组中
			if root.Left != nil {           // 将当前节点子节点加入队列
				queue = append(queue, root.Left)
			}
			if root.Right != nil {
				queue = append(queue, root.Right)
			}
		}

		levels = append(levels, level) // 添加当前层次的节点
	}
	return levels
}
```

# Go实现BFS-使用list实现queue

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	return bfsLevelOrder(root)
}
func bfsLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}

	queue := list.New()   // 申请一个队列
	queue.PushFront(root) // 头部插入
	levels := make([][]int, 0)

	for queue.Len() > 0 { // level记录当前层次所有节点
		n, level := queue.Len(), make([]int, 0)
		for i := 0; i < n; i++ {
			root = queue.Remove(queue.Back()).(*TreeNode) // 取队首元素并删除队首元素

			level = append(level, root.Val) // 将当前层的所有节点加入结果数组中
			if root.Left != nil {           // 将当前节点子节点加入队列
				queue.PushFront(root.Left)
			}
			if root.Right != nil {
				queue.PushFront(root.Right)

			}
		}
		levels = append(levels, level) // 添加当前层次的节点
	}
	return levels
}
```

# Go实现DFS

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 * Val int
 * Left *TreeNode
 * Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    return dfsLevelOrder(root)
}
func dfsLevelOrder(root *TreeNode) [][]int {
	level := 0
	vals := make([][]int, 0)
	dfs(root, level, &vals)
	return vals
}

func dfs(root *TreeNode, level int, vals *[][]int) {
	if root == nil {
		return
	}
	if len(*vals) <= level {
		*vals = append(*vals, []int{root.Val})
	} else {
		(*vals)[level] = append((*vals)[level], root.Val)
	}

	dfs(root.Left, level+1, vals)
	dfs(root.Right, level+1, vals)
}
```

# Go实现带访问记录的BFS - 超出时间限制

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	var result [][]int
	if root == nil {
		return result
	}

	visited := make(map[int]int)

	queue := list.New()
	queue.PushBack(root)

	for queue.Len() > 0 {
		var curLevel []int
		count := queue.Len()
		for count > 0 {
			element := queue.Front()
			node := element.Value.(*TreeNode)

			if _, exist := visited[node.Val]; exist {
				continue
			}
			visited[node.Val]++

			curLevel = append(curLevel, node.Val)
			if node.Left != nil {
				queue.PushBack(node.Left)
			}
			if node.Right != nil {
				queue.PushBack(node.Right)
			}
			queue.Remove(element)
			count--
		}
		result = append(result, curLevel)
	}
	return result
}
```

# Python代码BFS

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root: return [] 
        
        result = []
        queue = collections.deque() # 双端队列
        queue.append(root)
        
        # visited = set(root) 记录已经访问过的节点
        
        while queue: # 只要queue不为空
            level_size = len(queue) # 取总长度
            current_level =  []
            
            for _ in range(level_size):
                node = queue.popleft() # 取出queue头元素
                current_level.append(node.val) # 加入当层结点
                if node.left: queue.append(node.left) # 加入新的一层
                if node.right: queue.append(node.right)
            
            result.append(current_level)
        
        return result
```

# Python代码DFS

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root: return []
        self.result = []
        self._dfs(root, 0)
        return self.result
    
    def _dfs(self, node, level):
        if not node: return
        
        if len(self.result) < level + 1:
            self.result.append([]) # 当前行没有任何结果，加入空行
            
        self.result[level].append(node.val) # 当前层加入，每一层的节点值
        
        self._dfs(node.left, level+1)
        self._dfs(node.right, level+1)
```