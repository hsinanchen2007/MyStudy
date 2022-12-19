执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户内存消耗:2.2 MB, 在所有 Go 提交中击败了100.00%的用户
其实大家的方法都很多，比如先左右翻转，然后再对角线翻转。还有一些算法的时间是 kn （n是总共的元素数量）,虽然时间复杂度都是O(n).萌新于是就老老实实的用了八个指针，严格的 n 的时间。
```
func rotate(matrix [][]int)  {
	if len(matrix) < 2 {return}
	hei, wid := len(matrix), len(matrix[0])
	// 8个指针就可以了, x --> hei, y --> wid
	var ax, ay, bx, by, cx, cy, dx, dy int
	layer := 0 // 层数从外向内递增，从 0 开始
	for 2 * layer + 2 <= hei{
		ax, ay, bx, by, cx, cy, dx, dy =
			layer, layer, layer, wid-1-layer,
			hei-1-layer, wid-1-layer, hei-1-layer, layer
		matrix[ax][ay], matrix[bx][by],
			matrix[cx][cy], matrix[dx][dy] =
			matrix[dx][dy], matrix[ax][ay],
			matrix[bx][by], matrix[cx][cy]
		ay ++;bx++;cy--;dx--
		for i := 0; i < hei - 2 * layer - 2; i ++{
		matrix[ax][ay], matrix[bx][by],
				matrix[cx][cy], matrix[dx][dy] =
				matrix[dx][dy], matrix[ax][ay],
				matrix[bx][by], matrix[cx][cy]
				ay ++;bx++;cy--;dx--
		}
		layer ++
	}
}

```
思路很简单，虽然代码量比较大。。。。