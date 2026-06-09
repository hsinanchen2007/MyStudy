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

func buildTree(preorder []int, inorder []int) *TreeNode {
    
    preL := 0
    preR := len(preorder)-1
    inL := 0
    inR := len(inorder) - 1
    return buildRootTree(preorder, inorder, preL, preR, inL, inR)
}

func buildRootTree(preorder, inorder []int, preL, preR, inL, inR int) *TreeNode{

    if inL > inR {
        return nil
    }
    newTreeNode := &TreeNode{preorder[preL], nil, nil}
    pivot := searchIndex(inorder, preorder[preL])
    newTreeNode.Left = buildRootTree(preorder, inorder, preL+1, preL+(pivot)-inL, inL, pivot-1)
    newTreeNode.Right = buildRootTree(preorder, inorder, preL+(pivot)-inL+1, preR, pivot+1, inR)
    return newTreeNode
}

func searchIndex(arr []int, num int) int{

    // 默认数组不重复的情况下找某个数的下标
    for i:=0; i<len(arr); i++ {
        if arr[i] == num {
            return i
        }
    }
    return -1
}
```