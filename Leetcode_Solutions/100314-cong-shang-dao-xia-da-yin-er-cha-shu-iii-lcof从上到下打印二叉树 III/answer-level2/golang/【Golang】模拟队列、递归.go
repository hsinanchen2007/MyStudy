# 解题思路
- 本题是[面试题32 - I-从上到下打印二叉树 ](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/solution/go-mo-ni-dui-lie-di-gui-by-sakura-151/) 的变化
- 有题目可知在奇偶层数打印顺序相反
- 所以在上一题代码的基础上，加上判断层数是奇或偶，从而确定节点数值是从左往右还是从右往左打印即可。
---
# 解法一：模拟队列
--执行用时：0 ms --内存消耗：3.3 MB
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func levelOrder(root *TreeNode) [][]int {
    if root==nil{
        return nil
    }
    var ret [][]int
    queue := []*TreeNode{root}
    //树顶视为第0层,从0开始
    level:=0
    for len(queue)!=0{
        temp := []*TreeNode{}
        ret = append(ret,make([]int,0))
        for _,v := range queue{
            if level & 1 ==0{
                //偶数层从左向右打印，数值追加至切片尾部
                ret[level]=append(ret[level],v.Val)
            }else{
                //奇数层从右向左打印，数值追加至切片头部
                s := []int{v.Val}
                ret[level]=append(s,ret[level]...)
            }
            //子树从左到右入队
            if v.Left!=nil{
                temp = append(temp,v.Left)
            }
            if v.Right!=nil{
                temp = append(temp,v.Right)
            }
        }
        //下一层
        queue = temp
        level++
    }
    return ret
}
```

---
# 解法二：递归
--执行用时：0 ms --内存消耗：3.3 MB
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ret [][]int

func levelOrder(root *TreeNode) [][]int {
    ret=nil
    //树顶视为第0层,从0开始
    build(root,0)
    return ret
}

func build(root *TreeNode,level int){
    if root==nil{
        return
    }

    if level > len(ret)-1{
        ret=append(ret,make([]int,0))
    }

    if level & 1 == 0 {
        //偶数层从左向右打印，数值追加至切片尾部
        ret[level]=append(ret[level],root.Val)
    }else{
        //奇数层从右向左打印，数值追加至切片头部
        s:=[]int{root.Val}
        ret[level]=append(s,ret[level]...)
    }

    //下一层，从左到右递归子树
    level++
    build(root.Left,level)
    build(root.Right,level)
}
```
