### 解题思路

![image.png](https://pic.leetcode-cn.com/c24635fefbf56a08dbd13e93ecfed9428e5d0781f10aa87899e3cf3fe0b1fbf2-image.png)

**思路**：简单说就是对层次遍历所用的queue中的不同层的节点使用nil空指针分隔开来，这样我们就知道了queue中哪些节点是同一层的，哪些是不同层的，这里还需要一个变量控制循环的结束，原因看下方技巧分析：

1. **使用nil分隔queue中的不同层的节点**：queue中的初始状态设计为[nil, root]，这样做的目的是在开始遍历第0层节点前，由于出队的节点为nil，我们就知道将要遍历新的一层的节点了。因此我们会在queue中添加一个nil用以分隔即将遍历的层的节点与下一层的节点，按照这样的方式不断的出队入队即可。往队中添加节点的方式与BFS相同。
2. **变量控制**：我们使用nil分隔queue中不同层的节点会带来一个问题，那就是每当出队的节点为nil时，我们会往queue中添加一个nil，这就会使得在我们即将遍历最后一层节点时，同样会往queue中添加一个nil，因此我们的queue的末尾是一个nil。而由于我们的规则是遇到nil则往queue中添加nil，因此在遍历完最后一层后会有无限个nil不断入队。所以，我们需要设置一个变量来标识是否需要继续从队中取节点。

详细过程请看代码

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
    if root == nil {
        return nil
    } else if root.Left == nil && root.Right == nil {
        return [][]int{{root.Val, }, }
    }
    // 二维数组，存放每层的节点值
    lists := make([][]int, 0)
    // isBreak用于控制是否结束循环
    isBreak := false
    // 队列，存放树节点，使用nil空指针分隔每层的节点
    queue := make([]*TreeNode, 0)
    // 首先添加一个nil空指针，再添加root节点
    // 对于出队节点，若为nil则表示接下来是新的一层，需要往队列中再添加一个nil指针，因此我们的初始队列需要首先添加一个nil
    queue = append(queue, nil, root)
    for len(queue) != 0 {
        node := queue[0]
        queue = queue[1:]
        // 出队节点为nil，则表示队列中余下的节点全是新的一层的节点，因此新的一层的节点在出队前要往队列中添加一个nil用于分割
        // 同时需要在lists中新建一个一维数组用于存放新的一层的节点
        if node == nil {
            // isBreak为true时表示已经遍历完所有的层的节点
            // 什么时候会出现isBreak总是为true的情况？
            // 当queue中出队的节点总是nil时，isBreak就总是nil，这也说明层次遍历完所有节点了
            if isBreak {
                break
            // isBreak为false表示刚刚遍历完一层的节点，将其改为true，（重点）并且往queue中添加一个nil指针
            } else {
                isBreak = true
            }
            lists = append(lists, make([]int, 0))
            queue = append(queue, nil)
        // 出队节点非空，则往lists的最后一个数组中添加节点值
        } else {
            nums := lists[len(lists) - 1]
            nums = append(nums, node.Val)
            lists[len(lists) - 1] = nums
            if node.Left != nil {
                queue = append(queue, node.Left)
            }
            if node.Right != nil {
                queue = append(queue, node.Right)
            }
            isBreak = false
        }
    }
    // 在退出循环前，我们又创建了一个一维数组放到list中，因此我们需要删除它
    if len(lists[len(lists) - 1]) == 0 {
        lists = lists[: len(lists) - 1]
    }

    return lists
}
```