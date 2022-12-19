思路：只利用一个[]int，行数下移即在尾部添加元素1，然后倒序计算当前行

```
func getRow(rowIndex int) []int {
	// 第0行
	nums := []int{1}
	for i := 1; i <= rowIndex; i++ {
		// 尾部追加1
		nums = append(nums, 1)
		// 倒序计算杨辉三角当前行
		for j:=i-1;j>0;j--{
			nums[j]+=nums[j-1]
		}
	}
	return nums
}
```

![image.png](https://pic.leetcode-cn.com/d1f7d86f1c57b5dc73425ae9c62fee24a81690657b3c9c6af3c2fc0e0ed75851-image.png)

