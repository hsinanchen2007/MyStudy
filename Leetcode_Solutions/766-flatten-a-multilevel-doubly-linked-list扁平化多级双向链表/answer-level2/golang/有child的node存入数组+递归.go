### 解题思路

Go: 0ms(100%), 2.9MB(100%)

说说大致思路：遍历一次主链，将所有`Child`不为空的按序存入数组parents中；遍历数组parents，递归处理即可，详见代码。

### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Prev *Node
 *     Next *Node
 *     Child *Node
 * }
 */

func flatten(root *Node) *Node {
   if root == nil || (root.Next == nil && root.Child == nil ) {
       return root
   } 

   parents := make([]*Node, 0)
   for node := root; node != nil; node = node.Next {
       if node.Child != nil {
           parents = append(parents, node)
       }
   }

    for i := 0; i < len(parents); i++ {
        parent, right := parents[i], parents[i].Next
        parent.Next = nil
        if right != nil {
            right.Prev = nil
        }

        childRoot := flatten(parent.Child)
        parent.Child = nil
        parent.Next = childRoot
        childRoot.Prev = parent

        childTail := childRoot
        for childTail.Next != nil {
            childTail = childTail.Next
        }
        childTail.Next = right
        if right != nil {
            right.Prev = childTail
        }
    }

    return root
}
```