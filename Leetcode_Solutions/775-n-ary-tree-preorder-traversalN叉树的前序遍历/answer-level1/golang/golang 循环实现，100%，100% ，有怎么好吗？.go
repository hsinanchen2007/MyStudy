### 解题思路
自己维护栈，尽然结果如此好

![WX20200329-122527@2x.png](https://pic.leetcode-cn.com/3808825964f68df071c3fe811d4650e819e44be696c762621b32a8d605798579-WX20200329-122527@2x.png)


### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

type Stack struct {
    Val *Node
    Next *Stack
}

func preorder(root *Node) []int {

    r := make([]int, 0, 10)

    if root == nil {
        return r
    }

    stack := &Stack{
        Val : root,
    }

    for v := stack; v != nil; v = v.Next {
        r = append(r, v.Val.Val)
        t := v.Next

        c := v
        for _, vv := range v.Val.Children {
            c.Next = &Stack{
                Val : vv,
            }
            c = c.Next
        }
        c.Next = t
    }

    return r
}
```