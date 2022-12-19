**思路**

```
1. 获取树的高度--->构造[][]string
    1. 树高 = 数组row数
    2. 2^树高-1 = 数组row数
2. 二分搜索递归
    1. 每次将root.val分装到数组当前行中间
    2. 左右递归树&数组下移一行
```

**代码**

```

func getHeight(root *TreeNode) int {
	if root == nil{
		return 0
	}else{
		var left = getHeight(root.Left)+1
		var right = getHeight(root.Right)+1
		if left>right{
			return left
		}else{
			return right
		}
	}
}
var result [][]string
func helper(root *TreeNode,curLevel int,start,end int)  {
	if root == nil{
		return
	}else{
		var index int
		index = (end+start)/2
		result[curLevel][index] = strconv.Itoa(root.Val)
		fmt.Println(root.Val,"  ")
		helper(root.Right,curLevel+1,index+1,end)
		helper(root.Left,curLevel+1,start,index-1)
	}
}

func printTree(root *TreeNode) [][]string {
	var height = getHeight(root)
	var width = int(math.Pow(2,float64(height))-1)
	result = make([][]string,0,height)
	for i:=0;i<height ;i++  {
		var temp  = make([]string,width)
		result = append(result, temp)
	}
	helper(root,0,0,width-1)
	return result
}
```
