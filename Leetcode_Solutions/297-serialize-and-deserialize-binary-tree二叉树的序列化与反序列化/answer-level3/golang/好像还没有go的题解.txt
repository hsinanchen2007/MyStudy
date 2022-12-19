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

type Codec struct {
    
}

func Constructor() Codec {
    return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
        res:=""
        dfs1(root,&res)
        return res
}
func dfs1(root *TreeNode,res *string){
    if root==nil{
        *res+="null "
        return 
    }
   sum:=strconv.Itoa(root.Val)
   *res=*res+sum+" "
   dfs1(root.Left,res)
   dfs1(root.Right,res)

}
// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {    
    u:=0
    return dfs2(data,&u)
}
func dfs2(data string,u *int) *TreeNode{
    if *u==len(data){
        return nil
    }
    k:=*u+1
    for data[k]!=' '{
        k++
    }
    if data[*u]=='n'{
       *u=k+1
        return nil
    }
    val:=0
    if data[*u]=='-'{
        for i:=*u+1;i<k;i++{
            val=val*10+int(data[i]-'0')

        }
        val=-val
    }else{
        for i:=*u;i<k;i++{
            val=val*10+int(data[i]-'0')

        }
    }
    *u=k+1
    root:=&TreeNode{Val:val}
    root.Left=dfs2(data,u)
    root.Right=dfs2(data,u)
    return root
}


/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * data := obj.serialize(root);
 * ans := obj.deserialize(data);
 */
```