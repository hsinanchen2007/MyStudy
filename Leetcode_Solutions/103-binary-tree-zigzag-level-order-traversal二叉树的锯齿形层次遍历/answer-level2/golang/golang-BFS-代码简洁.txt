![WX20200218-212114.png](https://pic.leetcode-cn.com/528b27eb1e4edbaae04c890bac3b6d8fd35bb886dd4780d35a0a542212597b52-WX20200218-212114.png)
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
    ans := [][]int{}
    if root == nil {
        return ans
    }
    //控制数组反转Order
    isReverse := false
    qqq := []*TreeNode{root}
    for count := 1;count>0;count= len(qqq){
        list := []int{}
        for i:=count;i>0;i--{
            //模拟 queue pop
            node := qqq[0]
            qqq = qqq[1:]

            //判断是否反转
            if isReverse {
                list = append([]int{node.Val},list...)
            }else{
                list = append(list,node.Val)
            }
            //queue push 准备下一层树遍历
            if node.Left != nil{
                qqq = append(qqq,node.Left)
            }
            if node.Right != nil{
                qqq = append(qqq,node.Right)
            }
        }
        //二叉树这一层遍历完成
        isReverse = !isReverse  //反转order
        ans = append(ans,list)
    }
    return ans
}
```