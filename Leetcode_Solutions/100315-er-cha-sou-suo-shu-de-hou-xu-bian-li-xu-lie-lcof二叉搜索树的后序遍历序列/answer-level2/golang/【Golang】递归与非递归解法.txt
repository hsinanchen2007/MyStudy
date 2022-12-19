# 解题思路
- **二叉搜索树**
 	- 左子树的元素是都小于根元素，右子树都大于根元素
 - **后序遍历**
  	- 首先遍历左子树，然后遍历右子树，最后访问根结点，所以数组最后一个元素是根元素。
 -  从前面开始遍历，小于的当前根元素的值是左子树的
 - 当找到第一个大于当前根元素的值，可以确定后半段的元素都应是在当前节点的右子树
 - 如果后半段（右子树）里面有小于根元素的值的元素，就说明这个不是二叉搜索树的后序遍历
 - 最后循环校验每个子树是否也满足二叉搜索树的后序遍历即可。


# 解法一：非递归
--执行用时：0 ms --内存消耗：2.1 MB
```go
func verifyPostorder(postorder []int) bool {
    if len(postorder) <= 2 {
        return true
    } 
    //在二叉搜索树中，左子树的元素是都小于根元素，右子树都大于根元素
    //在后序遍历中，最后一个元素是根元素
    head := len(postorder)-1
    for head != 0{
        //popinter 统计符合二叉搜索树的后序遍历的节点数
        popinter := 0
        //从前面开始遍历，小于的当前根元素的值是左子树的，当找到第一个大于当前根元素的值，可以确定后半段的元素都应是在当前节点的右子树
        for postorder[popinter] < postorder[head]{
            popinter++
        }
        //如果后半段里面有小于根元素的值的元素，就说明这个不是二叉搜索树的后序遍历，跳出循环
        for postorder[popinter]>postorder[head]{
            popinter++
        }
        //popinter != head 或 popinter < head 说明该数组不是某二叉搜索树的后序遍历结果
        if popinter != head{
            return false
        }
        //进入下一个节点继续验证
        head--
    }
    return true
}
```


# 解法二：递归
--执行用时：0 ms --内存消耗：2.1 MB
```go
func verifyPostorder(postorder []int) bool {
    if len(postorder) <= 2 {
        return true
    } 
    //在后序遍历中，最后一个元素是根元素
    return juage(postorder,0,len(postorder)-1)
}

func juage(postorder []int, strat, end int) bool {
    if strat>=end{
        return true
    }
    var i int
    //从前面开始遍历，小于的当前根元素的值是左子树的，当找到第一个大于当前根元素的值，可以确定后半段的元素都应是在当前节点的右子树
    for i = strat;i < end;i++{
        if postorder[i] > postorder[end]{
            break
        }
    } 
    //如果后半段（右子树）里面有小于根元素的值的元素，就说明这个不是二叉搜索树的后序遍历，return false
    for j := i ;j < end ;j++{
        if postorder[j] < postorder[end]{
            return false
        }
    }
    //递归检查左子树和右子树部分
    return juage(postorder,strat,i-1) && juage(postorder,i,end-1)
}
```

