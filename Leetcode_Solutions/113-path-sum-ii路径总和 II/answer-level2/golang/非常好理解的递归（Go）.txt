此题的解法就是dfs二叉树，遍历到叶子节点的时候判断当前路径是否符合条件，如果符合条件需要将当前的路径加入到二维数组中。
__注意__：Go在加入的时候先复制一个切片在加入，直接操作原切片数据
会被后面的遍历修改。
```
func pathSum(root *TreeNode, sum int) [][]int {
    var ret [][]int
    var path []int
    
    return dfs(root,path,ret,sum)
}

func dfs(root *TreeNode,path []int,ret [][]int,sum int) [][]int{
        if root == nil {
            return ret
        }
        sum -= root.Val
        path = append(path,root.Val)
        
        if root.Left == nil && root.Right == nil {
            if sum == 0 {
                slice := make([]int,len(path))
	        copy(slice[0:],path[0:])
                ret = append(ret,slice)
            }
            return ret
        }
        
        if root.Left != nil {
            ret = dfs(root.Left,path,ret,sum)
        }

        if root.Right != nil {
            ret = dfs(root.Right,path,ret,sum)
        }

        return ret
 }
```