### 解题思路
相似题目:
105. 从前序与中序遍历序列构造二叉树
106. 从中序与后序遍历序列构造二叉树

其实原理思路都差不多，根据遍历的特点找到每一个小的根节点并区分左右子树。

对于本题来说，和上述两题有不一样的地方是:
前序遍历的根节点是数组首元素，而后序遍历的根节点是数组的最后一个元素，那么划分左右子树的关键在于后序遍历的倒数第二个元素。

如 ：
前序:[1,2,4,5,3,6,7]
后序:[4,5,2,6,7,3,1]
前序的第一个元素1，和后序的最后一个元素1 明显是整个二叉树的根节点，此时来划分左右子树；
而对于后序来说，遍历顺序是 左， 右 ， 根，所以1左边紧挨着的肯定是以1为根节点的右子树，且3肯定为这个右子树的根节点，即 :
                1
    (未确定)          3
再到前序遍历数组中找到3的位置，那么按照前序遍历的特点: 根， 左 ，右，[3,6,7]都在这个右子树上。
那么找到了根节点1，右子树[3,6,7]，剩下的就是左子树[2,4,5]

再循环上面的过程，我们可以得到这样一个二叉树:
        1
    2          3
4       5   6       7

注意，存在特殊情况:
前序:[1,2,4,5,3,6]
后序:[4,5,2,6,3,1]

按照上面思路，右子树是[3,6](按前序遍历的结果);
此时无法确定6为3的左节点还是右节点。
不过根据题目的说明，“每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。”
所以，这种情况下当作左右节点处理都可行。

代码思路:
1.递归处理。

2.终止条件:
遍历的数组为1时则返回这个节点；
遍历的数组为空时则返回一个nil；

3.区间划分：
设定一个哨兵索引，方便进行计算

4.递归进行：
左子树，右子树分开递归，递归结果分别返回为左子节点和右子节点。

代码如下：

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
func constructFromPrePost(pre []int, post []int) *TreeNode {
   root := Run(pre,post)
    return root
}

func Run(pre []int, post []int) *TreeNode {
    if len(post) == 0 {
        return nil
    }
    if len(post) == 1 {
        node := new(TreeNode)
        node.Val = post[0]
        return node
    }

    root := new(TreeNode)
    root.Val = pre[0]
    
    t := post[len(post)-2]

    rightIndex := 0

    for k,v := range pre {
        if v == t {
            rightIndex = k
            break
        }
    }

    rigthLength := len(pre)-rightIndex
    leftLength := len(post)-1-rigthLength

    preLeft := pre[1:leftLength+1]
    postLeft := post[:leftLength]

    preRight := pre[rightIndex:]
    postRight := post[leftLength:len(post)-1]

    root.Left = Run(preLeft,postLeft)
    root.Right = Run(preRight,postRight)
    
    return root
}
```