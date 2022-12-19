# 最简单的方法是中序遍历一次然后排序再按照原来结构中序把数填回去

```go

    //方法一：直接中序
    func inorderAppend(root *TreeNode,array *[]int){
        if root==nil{
            return
        }
        inorderAppend(root.Left,array)
        *array = append(*array, root.Val)
        inorderAppend(root.Right,array)
    }

    func inorderFill(root *TreeNode, array []int, current *int){
        if root==nil{
            return
        }
        inorderFill(root.Left,array, current)
        root.Val = array[*current]
        *current++
        inorderFill(root.Right,array,current)
    }

    func recoverTree(root *TreeNode)  {
        array := []int{}
        inorderAppend(root,&array)
        sort.Ints(array)
        iterator := 0
        inorderFill(root,array,&iterator)
    }
```
# 可以优化到O(1)的空间复杂度，使用Morris方法中序遍历二叉树，找到前后顺序出现问题的地方，进行交换即可

Morris遍历方法：

1. 根节点初始化为`current`
2. 如果`current`的左节点为空，输出该节点，同时`current = current.Right`
3. 如果`current`的左节点不为空，那么先去找到这个节点左子树的最右边节点`leftRight`
    - 首先`leftRight = current.Left`如果`leftRight`的右节点不为空且不为`current`，则循环`leftRight = leftRight.Right`
        - 如果`leftRight`的右节点为空（也就是没有指向current），则`leftRight.Right = current  current = current.Left`（`leftRight`右节点指向当前`current`，`current`进入左子树）
        - 如果pre的右节点为`current`，意味着这个`current`的左子树是完全遍历过了,那么恢复这个右节点`leftRight.Right = nil`，输出当前节点，`current`进入右子树，`current = current.right`

4. 重复2、3直到current为`nil`

这里在遍历的时候可以加入一个prevent变量来记录上一个current，这样就能揪出中序遍历中那对错误的节点

```go
//方法二：Morris方法中序遍历+冒泡
func recoverTree(root *TreeNode) {
    current := root
    var prevent *TreeNode
    var firstNode *TreeNode
    var secondNode *TreeNode
    for current != nil {
        //如果左子树为空那么说明这个节点是某个子树最左边的节点，可以遍历这个节点
        if current.Left == nil {
            //fmt.Println(prevent,current.Val)
            if prevent != nil && prevent.Val > current.Val {
                if firstNode == nil {
                    firstNode = prevent
                }
                secondNode = current
            }
            prevent = current
            //同时进入它的右子树
            current = current.Right
        } else {
            //不为空说明还可以向左进行，首先找到current左子树最右边的节点leftRight的右子树接到current上
            leftRight := current.Left
            for leftRight.Right != nil && leftRight.Right != current {
                leftRight = leftRight.Right
            }
            //如果左子树没有被遍历过,就把pre的右节点指向current,并把current向左迈一步
            if leftRight.Right != current {
                leftRight.Right = current
                current = current.Left
            } else {
                //如果遍历过，就把这个pre的指向去掉，恢复原来树结构，并让current进入右子树
                leftRight.Right = nil
                //fmt.Println(prevent,current.Val)
                if prevent != nil && prevent.Val > current.Val {
                    if firstNode == nil {
                        firstNode = prevent
                    }
                    secondNode = current
                }
                prevent = current
                current = current.Right
            }
        }
    }
    firstNode.Val, secondNode.Val = secondNode.Val, firstNode.Val
}
```