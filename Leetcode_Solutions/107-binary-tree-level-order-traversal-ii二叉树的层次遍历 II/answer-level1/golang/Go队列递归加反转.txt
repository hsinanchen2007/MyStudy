```
var res [][]int 
func binali(r *TreeNode,i int) {
    if(r == nil){
        return
    }
    if len(res) < i+1 {
        var row []int
        res = append (res,row)
    }
    res[i] = append(res[i],r.Val)
    binali(r.Left,i + 1)
    binali(r.Right,i+1)
    
    
}
func levelOrderBottom(root *TreeNode) [][]int {
    res = [][]int{}
    binali(root,0)
    
    //
    l := len(res)
    var res2 [][]int
    for i:=l-1;i>=0;i-- {
        res2 = append(res2,res[i])
    }
 
 
    return res2
}
```
