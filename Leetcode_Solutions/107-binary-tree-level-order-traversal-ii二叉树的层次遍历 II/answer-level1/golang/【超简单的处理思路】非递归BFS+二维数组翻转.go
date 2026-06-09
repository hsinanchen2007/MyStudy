### 解题思路

![image.png](https://pic.leetcode-cn.com/6df1764f487d9bc9e6fa56895c7f81a86be9b931bb5a53734ec73476ed1077f7-image.png)

解题思路与102（详见[102题解](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/fei-di-gui-bfsbian-liang-kong-zhi-shuang-100-by-ji/)）大致相同，不同之处在于对返回的二维数组的处理，本题将BFS所得的二维数组进行了翻转即为所需答案：

```golang
for left, right := 0, len(lists) - 1; left < right; left, right = left + 1, right - 1 {
    lists[left], lists[right] = lists[right], lists[left]
}
```

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
func levelOrderBottom(root *TreeNode) [][]int {
    if root == nil {
        return nil
    } else if root.Left == nil && root.Right == nil {
        return [][]int{{root.Val, }, }
    }
    lists := make([][]int, 0)
    isBreak := false
    queue := make([]*TreeNode, 0)
    queue = append(queue, nil, root)
    for len(queue) != 0 {
        node := queue[0]
        queue = queue[1:]
        if node == nil {
            if isBreak {
                break
            } else {
                isBreak = true
            }
            lists = append(lists, make([]int, 0))
            queue = append(queue, nil)
        } else {
            isBreak = false
            nums := lists[len(lists) - 1]
            nums = append(nums, node.Val)
            lists[len(lists) - 1] = nums
            if node.Left != nil {
                queue = append(queue, node.Left)
            }
            if node.Right != nil {
                queue = append(queue, node.Right)
            }
        }
    }

    lists = lists[: len(lists) - 1]
    for left, right := 0, len(lists) - 1; left < right; left, right = left + 1, right - 1 {
        lists[left], lists[right] = lists[right], lists[left]
    }

    return lists
}
```