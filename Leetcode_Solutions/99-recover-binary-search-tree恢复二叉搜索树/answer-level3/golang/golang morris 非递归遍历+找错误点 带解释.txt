本题两个核心问题解决思路如下：

### 查找两个出错节点的思路如下（参考powcai）：
  若某二叉搜索树中序遍历顺序是 **4,2,3,1,**我们只要找到节点4和节点1交换顺序即可!
  这里我们有个规律发现这两个节点:
    1. 第一个节点,是第一个按照中序遍历时候前一个节点大于后一个节点,我们选取前一个节点,这里指节点4;
    2. 第二个节点,是在第一个节点找到之后, 后面出现前一个节点大于后一个节点,我们选择后一个节点,这里指节点1;



### morris 遍历
一句话总结：设当前节点为 cur，你首先需要遍历左子树，不使用额外栈，但是需要确保遍历过左子树之后可以回来，再遍历右子树。

  所以你想一下，**左子树最后一个被遍历的节点是谁**？是左子树中**最右的那个叶节点**。
  所以我们可以找到他，并设置他的右节点为 cur，以便于遍历到他可以回来。
  那么我们遍历左子树就有了两种情况，
    1. 该左子树的右节点原本为空，我设置了 cur，那么说明我是第一次遍历到该子树，那么我就把 cur 设置为 cur.Left 要进行遍历。
    2. 该左子树的右节点已经是 cur，那么说明我已经遍历过左子树了，那么就把设置的右节点重新设置为 nil，接着我们打印下 cur(因为中序遍历顺序是左.根.右)，然后把 cur 设置为 cur.Right 即可
  所以你就也能很快得出代码终止遍历的条件是 cur == nil 



```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */



func recoverTree(root *TreeNode)  {
    cur := root
    var firstNode, secondNode, preNode *TreeNode
    // 定义三个节点，分别对应，第一个出错节点，第二个出错节点，当前节点的前置节点
    firstNode, secondNode, preNode = nil, nil, new(TreeNode)
    preNode.Val = math.MinInt64
    for cur != nil {
        if cur.Left == nil {
            // 本处是 morris 遍历要打印的地方，所以我们增加处理第一，二个出错节点的代码
            if firstNode == nil && cur.Val < preNode.Val {
                firstNode = preNode
            }
            if firstNode != nil && cur.Val < preNode.Val {
                secondNode = cur
            }
            preNode = cur
            cur = cur.Right
        } else {
            flag := findPrecursorNode(cur.Left, cur)
            if flag == 0 {
                // 本处是 morris 遍历要打印的地方，所以我们增加处理第一，二个出错节点的代码
                if firstNode == nil && cur.Val < preNode.Val {
                    firstNode = preNode
                }
                if firstNode != nil && cur.Val < preNode.Val {
                    secondNode = cur
                }
                preNode = cur
                cur = cur.Right
            } else {
                cur = cur.Left
            }
        }
    }
    firstNode.Val, secondNode.Val = secondNode.Val, firstNode.Val
}

func findPrecursorNode(node *TreeNode, cur *TreeNode) int {
    for {
        if node.Right == cur {
            node.Right = nil
            return 0
        } else if node.Right == nil {
            node.Right = cur
            return 1
        }
        node = node.Right
    }
}

```
