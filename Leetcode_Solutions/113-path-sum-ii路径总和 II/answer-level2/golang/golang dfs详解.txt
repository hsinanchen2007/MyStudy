### 解题思路
分享几个重点：
1. 如何判断一个完整路径结束：
   这个很简单，到叶子节点了，也就是左右子树都为nil的节点，一个完整路径就结束了
2. 如何保存完整路径：
   这个就有点巧妙了。直接传入apppend(tmp, root.Val), 避免了显式写回溯（其实也没必要回溯，想想为什么）。并且在找到完整路径后加入到结果中
3. 为什么二位切片传的时指针：
   我们知道，golang函数传递参数对于slice是传的引用。解决这个题目时为什么我们传递引用后结果却是空的呢？为什么传递切片的指针结果就对了？这是因为直接传切片后，你在函数内部重新给切片重新赋值了（append时，如果原始切片cap不足，会重新创建一个底层数组），导致了切片的地址发生了变化，但是golang函数传递传的地址在函数执行前后是不会变化的！所以原来的地址上指向的数据还是空的切片。也就是这里：
```golang
   
	tmp = append(tmp, root.Val)
	res = append(res, tmp) //就是这里
```
	
  如果只改变切片中的某个值，这是没问题的，比如res[0] = []int{3,1}
4. 保存结果为什么不能用 下面的代码片段
```golang

	tmp = append(tmp, root.Val)
	res = append(res, tmp)
```
 
   如果这么写，会有几个用例过不了。这是因为append实现的一个坑，append一个切片时，就像普通函数一样，传入的时slice的引用，当你的slice中的值修改后，append的结果也被修改了！看下下面程序片段打印的结果吧
```golang

	tmp := []int{3, 1, 4}
	res := make([][]int, 0)

	res = append(res, tmp)
	_ = append(res, []int{5})

	tmp[2] = 0
	fmt.Println(res)  // 1

	tmp2 := []int{3, 1, 4}
	res = append(res, tmp2)
	tmp2[1] = 5

	fmt.Println(res) // 2
```

注释1处会打印[[3 1 0]], 注释2会打印[[3 1 0] [3 5 4]]

### 代码

```golang

func pathSum(root *TreeNode, sum int) [][]int {
	res := make([][]int, 0)
	dfs(root, &res, []int{}, sum)

	return res
}

func dfs(root *TreeNode, res *[][]int, tmp []int, sum int) {
	if root == nil {
		return
	}

	if root.Left == nil && root.Right == nil && sum == root.Val {
		var t []int
		t = append(t, tmp...)
		t = append(t, root.Val)
		*res = append(*res, t)
		return
	}

	dfs(root.Left, append(tmp, root.Val), tmp, sum-root.Val)
	dfs(root.Right, append(tmp, root.Val), tmp, sum-root.Val)
}

```