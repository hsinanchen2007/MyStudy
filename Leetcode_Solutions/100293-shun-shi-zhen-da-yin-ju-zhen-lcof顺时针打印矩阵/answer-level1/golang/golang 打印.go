### 解题思路
顺时针打印矩阵，考虑打印其最外圈，需要进行下面 5 步(约定 cs,rs 分别为列首和行首，ce,re 分别为列尾和行尾)：  
1. 从左到右依此打印第一行，即 matrix[rs][cs] 到 matrix[rs][ce]，此后将第一行从矩阵删除，即 rs+1
2. 从上到下依此打印最后一列，即 matrix[rs][ce] 到 matrix[re][ce]，此后将最后一列从矩阵删除，即 ce-1
3. 从右到左依此打印最后一行，即 matrix[re][ce] 到 matrix[re][cs]，此后将最后一行从矩阵删除，即 re-1
4. 从下到上依此打印第一列，即 matrix[re][cs] 到 matrix[rs][cs]，此后将第一列从矩阵删除，即 cs+1
5. 重复以上步骤，直到矩阵所有元素都打印完成


上面的思路就是将实际中我们顺时针打印一个矩阵抽象而来。 

![image.png](https://pic.leetcode-cn.com/8d4e63a24adffa6516d5605298f844115bc000dab6b60643c95d4785bd8700f6-image.png)  

这个结果不算好，也不算很坏，执行有点慢，证明程序还有待优化。  

### 代码

```golang
func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 {
		return nil
	}
	var ans = make([]int,0)
	cs,ce := 0, len(matrix[0])-1
	rs,re := 0, len(matrix)-1
	ansLen := (ce+1)*(re+1)
	for i := 0; i <= len(matrix)/2; i++ {
		for e := cs; e <= ce&&len(ans)<ansLen; e++ {
			ans = append(ans, matrix[rs][e])
		}
		rs++
		for e := rs; e <= re&&len(ans)<ansLen; e++ {
			ans = append(ans,matrix[e][ce])
		}
		ce--
		for e := ce; e >= cs&&len(ans)<ansLen; e-- {
			ans = append(ans,matrix[re][e])
		}
		re--
		for e := re; e >= rs&&len(ans)<ansLen; e-- {
			ans = append(ans,matrix[e][cs])
		}
		cs++
	}
	return ans
}
```