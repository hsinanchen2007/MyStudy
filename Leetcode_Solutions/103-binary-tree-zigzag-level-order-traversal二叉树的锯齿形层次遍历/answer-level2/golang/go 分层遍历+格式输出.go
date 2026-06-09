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
func zigzagLevelOrder(root *TreeNode) [][]int {

    d := getDeep(root)
    p:=make([][]int,d)
    var pos int
    dfs(root,pos,p)
   // fmt.Printf("p:%v\n",p)
   r :=make([][]int,d)
   var cnt bool
   for i:=0;i<d;i++{
       if cnt == false{
           r[i]=make([]int,len(p[i]))
          copy(r[i],p[i])
           cnt = true
       }else{
           for j:=len(p[i])-1;j>=0;j--{
               r[i]=append(r[i],p[i][j])
           }
           cnt = false
       }
   }
   return   r
}

func dfs(root *TreeNode, pos int,p [][]int){
    if root == nil{
        return
    }

    p[pos]=append(p[pos],root.Val)
    dfs(root.Left,pos+1,p)
    dfs(root.Right,pos+1,p)
 
}

func getDeep(root *TreeNode )int{
    if root == nil{
        return 0
    }

    return 1+ max(getDeep(root.Left),getDeep(root.Right))
}

func max(a int, b int)int{
    if a>b{
        return a
    }
    return b
}
```