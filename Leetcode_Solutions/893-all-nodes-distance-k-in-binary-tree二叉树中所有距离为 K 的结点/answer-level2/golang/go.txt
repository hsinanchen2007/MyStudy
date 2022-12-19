### 解题思路
此处撰写解题思路
暴力破解
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
type relation struct{
    Parent map[int]int
    Left map[int]int
    Right map[int]int
    Visited map[int]int
}
func distanceK(root *TreeNode, target *TreeNode, K int) []int {
    relation := relation{
        Parent:map[int]int{},
        Left: map[int]int{},
        Right: map[int]int{},
        Visited:map[int]int{}}
    getParent(root,&relation)
    relation.Visited[target.Val] = 1
    queue := []int{target.Val}
    for i:= 0;i<K;i++{
        tmp := []int{}
        for len(queue) != 0{
            relatives := relate(queue[0],relation)
            queue = queue[1:]
            tmp = append(tmp,relatives...)
        }
        queue = tmp
    }
    return queue
}

func relate(q int, r relation) []int{
    res := []int{}
    if v,ok := r.Parent[q]; ok &&r.Visited[v] == 0{
        r.Visited[v] = 1
        res = append(res,v)
    }
    if v,ok := r.Left[q]; ok &&r.Visited[v] == 0{
        r.Visited[v] = 1
        res = append(res,v)
    }
    if v,ok := r.Right[q]; ok &&r.Visited[v] == 0{
        r.Visited[v] = 1
        res = append(res,v)
    }
    return res
}

func getParent(root *TreeNode,r *relation){
    if root == nil{
        return
    }
    if root.Left != nil{
        r.Parent[root.Left.Val] = root.Val
        r.Left[root.Val] = root.Left.Val
        r.Visited[root.Left.Val] = 0
        getParent(root.Left,r)
    }
    if root.Right != nil{
        r.Parent[root.Right.Val] = root.Val
        r.Right[root.Val] = root.Right.Val
        r.Visited[root.Right.Val] = 0
        getParent(root.Right,r)
    }
}
```