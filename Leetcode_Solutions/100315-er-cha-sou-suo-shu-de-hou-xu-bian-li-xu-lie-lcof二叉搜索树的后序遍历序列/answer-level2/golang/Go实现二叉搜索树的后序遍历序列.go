

```golang
func verifyPostorder(postorder []int) bool {
    if len(postorder) <2 {
        return true
    }
    root := postorder[len(postorder)-1]
    i := 0
    for ;i<len(postorder)-1;i++{
        if postorder[i]>root{
            break
        }
    }
    for j := i;j<len(postorder)-1;j++{
        if postorder[j]<root{
            return false
        }
    }
    left :=verifyPostorder(postorder[:i])
    right := verifyPostorder(postorder[i:len(postorder)-1])
   return left && right
}
```