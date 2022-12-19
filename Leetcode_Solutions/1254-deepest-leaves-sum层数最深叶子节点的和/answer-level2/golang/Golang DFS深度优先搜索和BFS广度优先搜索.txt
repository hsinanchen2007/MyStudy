### 解题思路
Golang DFS和BFS实现方法

### 代码

```golang
func deepestLeavesSum(root *TreeNode) int {
    // 定义两个变量 - 最深层数和结果
    var (
        maxDep = -1
        result = 0
    )
    // 调用方法
    bfs(root, 0, &maxDep, &result)
    return result
}

func dfs(root *TreeNode, dep int, maxDep, result *int){
    // 深度优先搜索
    // 递归要设置跳出条件
    if root == nil{
        return
    }
    // 判断深度 - 大于最大深度则重置结果值，等于则相加
    if dep > *maxDep {
        *maxDep, *result = dep, root.Val
    } else if dep == *maxDep {
       *result = *result + root.Val
    }
    // 递归
    dfs(root.Left, dep + 1, maxDep, result)
    dfs(root.Right, dep + 1, maxDep, result)
}

func bfs(root *TreeNode, dep int, maxDep, result *int){
    // 广度优先搜索 - 先定义入栈的Item
    type item struct {
		node *TreeNode
		dep int
	} 
	var stack []item
	stack = append(stack, item{
		node: root,
		dep:  dep,
	})
    for len(stack) > 0 {
        // 通过简单的数组操作实现栈
        i := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        dep, node := i.dep, i.node
        // 判断深度 - 大于最大深度则重置结果值，等于则相加，过程和dfs一样
        if dep > *maxDep {
            *maxDep, *result = dep, node.Val
        } else if dep == *maxDep {
            *result = *result + node.Val
        }
        // 添加子节点
        if node.Left != nil{
            stack = append(stack, item{
                node: node.Left,
                dep:  dep + 1,
            })
        }
        if node.Right != nil{
            stack = append(stack, item{
                node: node.Right,
                dep:  dep + 1,
            })
        }
    }
}
```

### 运行结果

1. DFS
![image.png](https://pic.leetcode-cn.com/3881b2120b5787c946a877573006d76624f640d3658d87d92ddd778040e972dc-image.png)

2. BFS
![image.png](https://pic.leetcode-cn.com/45570aa7ff78f58339fc6d88e42d194b4a488addbb30b88b5f6ec4c1330e8161-image.png)
