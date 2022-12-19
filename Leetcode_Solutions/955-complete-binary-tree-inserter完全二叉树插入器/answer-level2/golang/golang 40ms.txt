
![批注 2019-08-18 171937.png](https://pic.leetcode-cn.com/01ce3a2b0650ec7d88018e25e2329d51e29b7b350cd2b24f2bb226d9fff22540-%E6%89%B9%E6%B3%A8%202019-08-18%20171937.png)

各函数复杂度：O(n),O(1),O(1)
结构里存储二叉树最后一层和倒数第二层节点

```
type CBTInserter struct {
    root *TreeNode
    LastLastNodeList []*TreeNode
    LastNodeList []*TreeNode
}

func Constructor(root *TreeNode) CBTInserter {
    this:=CBTInserter{}
    this.root=root
    
    nodeList:=[]*TreeNode{root}
    for len(nodeList)>0{
        l:=len(nodeList)
        this.LastLastNodeList=this.LastNodeList
        this.LastNodeList=nodeList
        for i:=0;i<l;i++{
            nodeTmp:=nodeList[0]
            nodeList=nodeList[1:]
            
            if nodeTmp.Left!=nil{
                nodeList=append(nodeList,nodeTmp.Left)
            }
            if nodeTmp.Right!=nil{
                nodeList=append(nodeList,nodeTmp.Right)
            }          
        }
    }
    return this
}


func (this *CBTInserter) Insert(v int) int {
    if len(this.LastNodeList)>=len(this.LastLastNodeList)*2{
        this.LastLastNodeList=this.LastNodeList
        this.LastNodeList=[]*TreeNode{}
    }
    newNode:=&TreeNode{Val:v}
    l:=len(this.LastNodeList)
    if l%2==0{
        this.LastLastNodeList[l/2].Left=newNode
    }else{
        this.LastLastNodeList[l/2].Right=newNode
    }
    this.LastNodeList=append(this.LastNodeList,newNode)
    return this.LastLastNodeList[l/2].Val
}


func (this *CBTInserter) Get_root() *TreeNode {
    return this.root
}
```

