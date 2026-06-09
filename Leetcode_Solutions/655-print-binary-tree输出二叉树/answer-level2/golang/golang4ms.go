```
func printTree(root *TreeNode) [][]string {
    if root==nil{
        return nil
    }
    row:=height(root)
   // 每一行的长度是2^0+2^1+...+2^(二叉树的深度-1）= 2^(二叉树的深度）-1 
    cow:=int(math.Pow(float64(2),float64(row)))-1
    result:=[][]string{}
    for i:=0;i<row;i++{
        cur:=make([]string,cow)
        result=append(result,cur)
    }    
    jiange:=int(math.Pow(float64(2),float64(row)-2))
    dfs(root,result,0,len(result[0])/2,jiange)
    return result
}
func dfs(root *TreeNode,res [][]string,h,cor int,jiange int){
    if root==nil{
        return
    }
    jg:=jiange/2
   // 下一层的间隔是上一层间隔的一半
    p:=fmt.Sprintf("%v",root.Val)
    res[h][cor]=p
    if root.Left!=nil{
        dfs(root.Left,res,h+1,cor-jiange,jg)
    }
    if root.Right!=nil{
        dfs(root.Right,res,h+1,cor+jiange,jg)
    }
    
}
func height(root *TreeNode)int{
    if root==nil{
        return 0
    }
    return max(height(root.Left),height(root.Right))+1
}
func max(a,b int)int{
    if a>b{
        return a
    }
    return b
}
```