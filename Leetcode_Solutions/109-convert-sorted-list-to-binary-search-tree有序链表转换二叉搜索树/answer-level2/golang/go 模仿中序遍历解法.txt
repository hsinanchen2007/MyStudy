### 解题思路
此处撰写解题思路
go 模仿中序遍历解法

### 代码

```golang

func sortedListToBST(head *ListNode) *TreeNode {

    var findLength  func(head *ListNode) int 
    var buildTree  func(l, r int) *TreeNode
    findLength = func(head *ListNode) int {
        count := 0
        for (head != nil){
            count++
            head = head.Next
        }
        return count
    }
    buildTree = func(l, r int) *TreeNode {

        if l > r {
            return nil
        }

        mid := (l+r)/2
        left := buildTree(l, mid-1)

        // 左侧创建之后轮到根节点
        node := &TreeNode{head.Val, nil, nil}
        node.Left = left
        // 第一次创建的为最左侧节点
        head = head.Next
        right := buildTree(mid+1, r)
        node.Right = right

        return node
    }

    cur := head
    c := findLength(cur)
    return buildTree(0, c-1)
}

