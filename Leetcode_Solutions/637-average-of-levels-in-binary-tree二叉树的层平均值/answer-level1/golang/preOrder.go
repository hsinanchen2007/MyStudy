### 解题思路
此处撰写解题思路

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
func averageOfLevels(root *TreeNode) []float64 {
    m := map[int][]int{}
    preOrder(root,0,&m)
    ans := []float64{}
    for i:=0;i<len(m);i++{
        li := m[i]
        res := float64(li[0])/ float64(li[1])
        ans = append(ans,res)
    }
    return ans
}

func preOrder(root *TreeNode,lv int,m *map[int][]int){
    if root == nil{
        return
    }
    if list ,ok := (*m)[lv];ok{
        sum := list[0]+root.Val
        cnt := list[1]+1
        (*m)[lv] = []int{sum,cnt}
    }else{
        (*m)[lv] = []int{root.Val,1}
    }
    preOrder(root.Left,lv+1,m)
    preOrder(root.Right,lv+1,m)

}
```