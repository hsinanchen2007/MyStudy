### 代码

```golang
func verifyPostorder(postorder []int) bool {
    if len(postorder)==0{
        return true
    }
    split:=len(postorder)-1
    for split>=0{
        if postorder[split]<postorder[len(postorder)-1]{
            break
        }
        split--
    }
    if split<0{
        return verifyPostorder(postorder[0:len(postorder)-1])
    }
    for i:=0;i<split;i++{
        if postorder[i]>postorder[len(postorder)-1]{
            return false
        }
    }
    return verifyPostorder(postorder[0:split+1])&&verifyPostorder(postorder[split+1:len(postorder)-1])
}
```