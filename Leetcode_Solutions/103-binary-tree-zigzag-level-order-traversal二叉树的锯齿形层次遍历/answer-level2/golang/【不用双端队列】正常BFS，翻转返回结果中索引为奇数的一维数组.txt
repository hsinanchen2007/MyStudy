### 解题思路

![image.png](https://pic.leetcode-cn.com/333acf0f1129bb513b99d43ca7c890a2bf148abdf366ebb5a1b17a807d93fdf1-image.png)

该题的解法跟102大体相同，不同之处在于相同对最后返回的结果进行相应的反转即可：
```golang
for i := 0; i < len(lists); i++ {
    if i % 2 == 1 {
        reverseList(lists[i])
    }
}
```

该题的解法思路不在赘述，感兴趣的可以看我[102的题解](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/fei-di-gui-bfsbian-liang-kong-zhi-shuang-100-by-ji/)


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
func zigzagLevelOrder(root *TreeNode) [][]int {
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
            queue = append(queue, nil)
            lists = append(lists, make([]int, 0))
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
    if len(lists[len(lists) - 1]) == 0 {
        lists = lists[: len(lists) - 1]
    }

    for i := 0; i < len(lists); i++ {
        if i % 2 == 1 {
            reverseList(lists[i])
        }
    }

    return lists
}

func reverseList(nums []int) {
    if len(nums) <= 1 {
        return
    }
    for left, right := 0, len(nums) - 1; left < right; left, right = left + 1, right - 1 {
        nums[left], nums[right] = nums[right], nums[left]
    }
}
```