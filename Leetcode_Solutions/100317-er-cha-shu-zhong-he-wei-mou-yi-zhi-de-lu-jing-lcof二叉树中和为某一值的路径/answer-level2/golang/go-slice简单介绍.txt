**思路**
```

slice 引用传递
所以： =只是改变了原来的指向
      只有cap超限，才会产生新的指向


核心：copy(tar []type,src  []type)
     值复制，
     复制的内容长度 受到len(tar),len(src)限制。 



```


**代码**

```
func dfs(root *TreeNode,sum int,temp []int ,result *[][]int)  {
	if root == nil{
		return
	}else{
		sum = sum - root.Val
		var tempSlice = make([]int,len(temp))
        copy(tempSlice,temp)
		tempSlice = append(tempSlice, root.Val)
		if root.Left == nil && root.Right == nil{
			if sum == 0{
				*result = append(*result, tempSlice)
			}
		}else{
			dfs(root.Left,sum,tempSlice,result)
			dfs(root.Right,sum,tempSlice,result)
		}
	}
}


func pathSum(root *TreeNode, sum int) [][]int {
	var result = make([][]int,0)
	dfs(root,sum,[]int{},&result)
	return result
}
```
