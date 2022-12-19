# 官方给出的解答为T=O(n),S=O(n)
## 采用Morris遍历方式，实现T=O(n),S=O(1)的复杂度，应该算是此题的最优解

```
//morris遍历
//代码中，用//*******包起来的是本题的逻辑
//其余为Morris遍历的模板
func isValidBST(root *TreeNode) bool {
    if root == nil{
        return true
    }
    tmp:=make([]int,2)//保存前一个和后一个数值（为了比较）
    tmp[0]=math.MinInt64//题目里最小值为32位，这里采取64位，防止出错
    cur:=root//当前节点
    var pre *TreeNode//前一个节点
    for cur!=nil{
        if cur.Left==nil{
            //执行操作
            //*****************
            tmp[1]=cur.Val
            if tmp[0]>=tmp[1]{
                return false
            }
            tmp[0]=tmp[1]
            //*****************
            cur=cur.Right
        }else{
            pre=cur.Left
            for pre.Right!=nil && pre.Right!=cur{
                pre=pre.Right
            }
            if pre.Right==nil{
                pre.Right=cur
                cur=cur.Left
            }
            //成环
            if pre.Right==cur{
                pre.Right=nil
                //执行操作
                //*****************
                tmp[1]=cur.Val
                if tmp[0]>=tmp[1]{
                    return false
                }
                tmp[0]=tmp[1]
                //*****************
                cur=cur.Right
            }
        }
    }
    return true
}
```
