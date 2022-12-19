```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }
    queue := []*TreeNode{} // 没有{}
    queue = append(queue,root)
    val_slice := make([][]int, 0)
    val_slice = append(val_slice,[]int{root.Val}) // append root  int 类型 , 不能index取法
    for loc:=1;len(queue) > 0;loc++ {
        cur_slice := []int{}
        size := len(queue)
        for i:=0;i < size;i++ { //  暂存current size , 分号
            if queue[i].Left != nil {
                l := queue[i].Left
                queue = append(queue,l)
                cur_slice = append(cur_slice,l.Val)
            }
            if queue[i].Right != nil {  // 要判断是否为空
                r := queue[i].Right
                queue = append(queue,r)
                cur_slice = append(cur_slice, r.Val)
            }
        }
        // slice可以和slice append
        queue = queue[size:] //新的栈   
        if len(cur_slice) != 0 {  // 边界问题 
            val_slice = append(val_slice,cur_slice) 
        } 
        
    }
    return val_slice
}
![Screen Shot 2019-12-22 at 12.43.51 AM.png](https://pic.leetcode-cn.com/9d768d1cea920424a59c3423d1d8bd656b71c00aef9e7a2ad5eca676d710cf3f-Screen%20Shot%202019-12-22%20at%2012.43.51%20AM.png)
```
