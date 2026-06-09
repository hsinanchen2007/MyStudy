### 解题思路
1. 考察了二搜索叉树的后序遍历知识，对于一棵二叉搜素树的后序遍历，它的最后一个是根结点，如果存在左右子树，前面一定有一段数小于它，一段数大于它。
2. 假设检查left到right这段序列是不是二叉搜索树，则right作为根节点，left开始找到第一个大于根节点的数，极左middle。
3. 检查middle到right-1是不是都是大于right的，如果不是返回fasle；如果是返回true。

### 代码

```golang
func verifyPostorder(postorder []int) bool {

    return verifyPostorderBy(postorder, 0, len(postorder)-1)
}

func verifyPostorderBy(postorder []int, left, right int) bool {

    if left < 0 || right >= len(postorder) {
        return false
    }
    if left >= right {
        return true
    }
    middle := left 
    for postorder[middle] < postorder[right] {
        middle++
    }
    ret := true
    index := middle
    for index < right {
        if postorder[index] < postorder[right] {
            ret = false
        }
        index++
    }
    return ret && verifyPostorderBy(postorder, left, middle-1) && verifyPostorderBy(postorder, middle, right-1)
}
```