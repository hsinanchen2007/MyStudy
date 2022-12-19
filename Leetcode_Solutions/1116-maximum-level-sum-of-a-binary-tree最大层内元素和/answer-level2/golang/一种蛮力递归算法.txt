

### 解题思路
这里蛮力算法的目的，只是为了展示编写递归的技巧与方法，不是为了追求效率。若要追求效率，可以使用双队列的方法等。
其实为了追求一些技巧，还可以将需要多个步骤完成的事情，放一个函数完成。但这里就硬生生演示一下效果。
时间和空间复杂度如图所示，也是通过的。

![image.png](https://pic.leetcode-cn.com/3bae70850a81db0d4183425b4b44a52e1fc9ec9a5d712484a0739251b54eb606-image.png)

蛮力算法思路就是超级简单：

1、计算树有多少层。
2、计算每一层的和
3、从树的根到叶，一层层求最大值
4、输出最大值

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

func myMax(x, y int) int{
    if x>y {
        return x
    }
    return y
}

func maxLevelSum(root *TreeNode) int {
    if root==nil {
        return 0
    }
    sum := 0
    maxDepth := getMaxDepth(root)
    res := 0
    for i:=0; i<maxDepth; i++ {
        curlevelSum := getLevelSum(root, i)
        if curlevelSum > sum {
            sum = curlevelSum
            res = i
        }
    }
    return res+1
}

func getMaxDepth(root *TreeNode) int {
    if root==nil {
        return 0
    }
    return myMax(getMaxDepth(root.Left)+1, getMaxDepth(root.Right)+1)
}

func getLevelSum(root *TreeNode, level int) int {
    if root==nil || level<0 {
        return 0
    }
    if level==0 {
        return root.Val
    }
    return getLevelSum(root.Left, level-1) + getLevelSum(root.Right, level-1)
}
```