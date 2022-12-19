

```
func maxAncestorDiff(root *TreeNode) int {
    _,_,diffMax:=helper(root)
    return diffMax
}

func helper(root *TreeNode)(max,min,diffMax int){
    if root==nil{
        return 0,100000,0
    }
    maxLeft,minLeft,diffLeft:=helper(root.Left)
    maxRight,minRight,diffRight:=helper(root.Right)
    if maxLeft>maxRight{
        max=maxLeft
    }else{
        max=maxRight
    }
    if root.Val>max{
        max=root.Val
    }
    
    if minLeft<minRight{
        min=minLeft
    }else{
        min=minRight
    }
    if root.Val<min{
        min=root.Val
    }
    
    if diffLeft>diffRight{
        diffMax=diffLeft
    }else{
        diffMax=diffRight
    }
    
    tmp:=root.Val-max
    if tmp<0{
        tmp*=-1
    }
    if tmp>diffMax{
        diffMax=tmp
    }
    
    tmp=root.Val-min
    if tmp<0{
        tmp*=-1
    }
    if tmp>diffMax{
        diffMax=tmp
    }
    return
}
```
