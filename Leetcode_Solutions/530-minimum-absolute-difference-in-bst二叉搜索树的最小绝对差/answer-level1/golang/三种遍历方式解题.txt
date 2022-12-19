# 递归实现

```
//递归实现
func getMinimumDifference(root *TreeNode) int {
    if root==nil{
        return 0
    }
    minsub:=math.MaxInt32//最小绝对值差
    var pre *TreeNode//前置节点
    inorder(root,&minsub,&pre)
    return minsub
}
func inorder(root *TreeNode,minsub *int,pre **TreeNode){
    if root==nil{
        return 
    }
    inorder(root.Left,minsub,pre)
    //************************************************************************************
    if (*pre)!=nil{
        (*minsub)=int(math.Min(float64((*minsub)),math.Abs(float64((*pre).Val-root.Val))))
    }
    (*pre)=root
    //************************************************************************************
    inorder(root.Right,minsub,pre)
}

}

```
# 迭代（栈）实现
```

//栈实现
func getMinimumDifference(root *TreeNode) int {
    if root==nil{
        return 0
    }
    minsub:=math.MaxInt32
    var pre *TreeNode
    stack:=construct()
    for root!=nil || !stack.empty(){
        for root!=nil{
            stack.push(root)
            root=root.Left
        }
        root=stack.pop()
        //************************************************************************************
        if pre!=nil{
            minsub=int(math.Min(float64(minsub),math.Abs(float64(pre.Val-root.Val))))
        }
        pre=root
        //************************************************************************************
        root=root.Right
    }
    return minsub
}

//用链表实现栈
type Node struct{
    Tree  *TreeNode
    Next *Node
}

type stack struct{
    dummy *Node
}

func construct()*stack{
    return &stack{&Node{}}
}

func (s *stack)push(x *TreeNode){
    node:=&Node{x,nil}
    node.Next=s.dummy.Next
    s.dummy.Next=node
}

func (s *stack)pop()*TreeNode{
    v:=s.dummy.Next.Tree
    s.dummy.Next=s.dummy.Next.Next
    return v
}

func (s *stack)peek()*TreeNode{
    return s.dummy.Next.Tree
}

func (s *stack)empty()bool{
    return s.dummy.Next==nil
}


```

# Morris遍历实现

```
//morris遍历
func getMinimumDifference(root *TreeNode) int {
    if root==nil{
        return 0
    }
    minsub:=math.MaxInt32
    var pre *TreeNode
    var prem *TreeNode
    for root!=nil{
        if root.Left==nil{
            //***********************************************************************
            if pre!=nil{
                minsub=int(math.Min(float64(minsub),math.Abs(float64(pre.Val-root.Val))))
            }
            pre=root
            //***********************************************************************
            root=root.Right
        }else{
            prem=root.Left
            for prem.Right!=nil && prem.Right!=root{
                prem=prem.Right
            }
            if prem.Right==nil{
                prem.Right=root
                root=root.Left
            }
            if prem.Right==root{
                prem.Right=nil
                //***********************************************************************
                if pre!=nil{
                    minsub=int(math.Min(float64(minsub),math.Abs(float64(pre.Val-root.Val))))
                }
                pre=root
                //***********************************************************************
                root=root.Right
            }
        }
    }
    return minsub
}
```

### 从上述三种解法可以看出来，题目的核心代码就是*包起来的那块，直接套用遍历的模板就行
### 本质上，三种方式，morris最佳，但是结果差距不大，估计树的节点并不多

