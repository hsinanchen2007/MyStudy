### 解题思路
判断是否为相同的树，需要判断两个条件：
1.结构是否相同，即某一节点的左右子节点的情况一定相同；
2.结构相同的前提下，保证每个节点的值相同。

想法：
遍历每个节点，并判断其左右子树的关系。
为了便于观察和及时返回值，采用自定义栈的形式进行二叉树遍历；
由于是查看每个节点的左右子节点的情况，所以采用一种类似于前序遍历的方法；
说明：前序遍历自定义栈的实现的压栈顺序是：根，右，左，我的是：根，左，右；
实际效果一样，这说明理解原理后具体的实现是可以不同的。

每个二叉树往同一个栈中分别同时压入根，左，右
如下：
二叉树:p,q
p根q根，p左q左，p右q右。

情况有两种：
1.节点不符合压栈情况，未压栈：
即 
1）可能是结构不同，已经直接返回false；
2）可能是结构相同但值不同，已经直接返回false；
3）结构相同但都为null,此时也不压栈，但不返回false，而是进行下面的操作。

2.节点在栈中，此时两个节点的结构和值必相同。

此外，对于头节点的一些边界情况也需要特殊对待，具体看代码注释。
（不单独在for循环外面进行边界判断是因为觉得这个稍微简洁一些，且对时间复杂度的影响不是很大）

时间复杂度: 
p，q树中比较短的一个，因为不相同直接返回false，假设某一个节点不符合要求，且深度为m，则时间复杂度为 :
O(m),都相同的时候为二叉树的深度O(n)

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
type Stack struct {
     tail int
     list []*TreeNode
}

func NewStack() *Stack {
    s := new(Stack)
    t := make([]*TreeNode,0)
    s.list = t 
    s.tail = 0
    return s
}

func (s *Stack) Push(t *TreeNode) {
    if t != nil {
        s.list = append(s.list,t)
        s.tail++
    }
}

func (s *Stack) Pop() *TreeNode {
    t := new(TreeNode)
    if s.tail > 0 {
        t = s.list[len(s.list)-1]
        s.list = s.list[:len(s.list)-1]
        s.tail--
    } else {
        t = nil
    }
    return t
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
    s := NewStack()
    //栈初始化，分别压入两个二叉树的头节点
    s.Push(p)
    s.Push(q)
    for s.tail != 0 {
        //因为是两个二叉树一起压栈，所以只要栈不为空，必有偶数个节点在栈中
        //主要是对头节点这种边界情况进行判断
        if s.tail % 2 != 0 {
            return false
        }
        //对头节点进行判断
        if s.list[s.tail-2].Val != s.list[s.tail-1].Val {
            return false
        }
        tq := s.Pop()
        tp := s.Pop()
        //节点的结构不同
        if (tp.Left == nil || tq.Left == nil) && tp.Left != tq.Left {
            return false
        }
         if (tp.Right == nil || tq.Right == nil) && tp.Right != tq.Right {
            return false
        }
        //结构相同值不同
        if (tp.Left != nil && tq.Left != nil && tp.Right != nil && tq.Right != nil) && (tp.Left.Val != tq.Left.Val || tp.Right.Val != tq.Right.Val) {
            return false
        }
        //结构相同值相同
        if tp.Left != nil && tq.Left != nil {
            s.Push(tp.Left)
            s.Push(tq.Left)
        } 
        if tp.Right != nil && tq.Right != nil {
            s.Push(tp.Right)
            s.Push(tq.Right)
        }  
    }
    return true
}
```