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
func isSymmetric(root *TreeNode) bool {
    if(root == nil) {
        return true
    }
    treeLeftStr := ""
    Traversal(root.Left,"m",&treeLeftStr,true);
    // fmt.Println(treeLeftStr)

    treeRightStr := ""
    Traversal(root.Right,"m",&treeRightStr,false);
    // fmt.Println(treeRightStr)

    return treeLeftStr == treeRightStr;
}

/**
    遍历获取字符串
 */
func Traversal(root *TreeNode,opsition string,upNode *string,isNormalTra bool){
    //tree遍历结束
    if(root == nil){
        return
    }
    if isNormalTra {
        *upNode += fmt.Sprintf("%d%s",root.Val,opsition)
        Traversal(root.Left,"l",upNode,isNormalTra)
        Traversal(root.Right,"r",upNode,isNormalTra)
    }else{
        *upNode += fmt.Sprintf("%d%s",root.Val,opsition)
        Traversal(root.Right,"l",upNode,isNormalTra)
        Traversal(root.Left,"r",upNode,isNormalTra)
    }
}
```