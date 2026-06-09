```

func buildTree(preorder []int, inorder []int) *TreeNode {
    m:=len(preorder)

    if(m==0){
        return nil
    }
    head:=&TreeNode{preorder[0],nil,nil}
    if(m==1){
        return head
    }
    mid_posi:=-1
    for i:=0;i<m;i++{
        if(inorder[i]==preorder[0]){
            mid_posi=i;
            break;
        }
    }
    if(mid_posi!=0){
        head.Left=buildTree(preorder[1:(mid_posi+1)],inorder[0:mid_posi])
    }

    if(mid_posi!=m-1){
        head.Right=buildTree(preorder[(mid_posi+1):m],inorder[(mid_posi+1):n])
    }
    return head
}
```
