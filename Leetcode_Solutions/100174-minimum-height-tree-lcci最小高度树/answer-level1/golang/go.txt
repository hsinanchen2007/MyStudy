```
func buildTree(nums []int,start,end int) *TreeNode  {
	if start>end{
		return nil
	}else{
		var mid = (start+end+1)/2
		var root = new(TreeNode)
		root.Val,root.Left,root.Right = nums[mid],nil,nil  //默认也会有nil
		root.Left = buildTree(nums,start,mid-1)
		root.Right = buildTree(nums,mid+1,end)
		return root
	}
}

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0{
		return nil
	}else{
		return buildTree(nums,0,len(nums)-1)
	}
}
```
