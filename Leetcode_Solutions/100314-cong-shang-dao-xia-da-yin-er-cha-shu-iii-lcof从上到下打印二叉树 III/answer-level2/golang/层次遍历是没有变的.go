### 解题思路
一开始 思路错了 其实就是层次遍历 队列的入队方式不变 而输出变了而已

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
func levelOrder(root *TreeNode) [][]int {
    ans:=[][]int{}
    if root == nil{ 
        return ans
    }
    queue:=make([]*TreeNode,0)
    queue = append(queue,root)

    going:=false
    for len(queue)!=0{
        newQueue:=[]*TreeNode{}
        item:=[]int{}
        
        //偶数层
        if !going {
            for i:=0;i<len(queue);i++{
                item =append(item,queue[i].Val)
            }
        }else{
            for i:=len(queue)-1;i>=0;i--{
              item =append(item,queue[i].Val)
            }
        }

        ans = append(ans,item)
        for i:=range queue {
            if queue[i].Left!=nil{
                newQueue = append(newQueue,queue[i].Left)    
            }

            if queue[i].Right!=nil{
                newQueue = append(newQueue,queue[i].Right)
            }
        }
        

        queue = newQueue
        //提取的这一批的父节点
        going=!going
    }
    return ans

    // 1 
    //2 3
}
```