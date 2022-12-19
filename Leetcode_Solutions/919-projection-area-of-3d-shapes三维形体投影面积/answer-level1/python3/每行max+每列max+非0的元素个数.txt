思路:见标题
注意:本人菜鸡 主要的语句都添加了注释 以下代码仅供参考 还请大家做做指教
```python []
from itertools import chain
class Solution:
	def projectionArea(self,grid):
		return sum(max(i) for i in grid)+sum(max(i) for i in zip(*grid))+sum(1 for i in chain(*grid) if i)
		#xz平面 sum(max(i) for i in grid) grid每行的最大值
		#yz平面 sum(max(i) for i in zip(*grid)) grid每列的最大值
		#xy平面 sum(1 for i in chain(*grid) if i) 非0的元素个数 或者len(list(filter(bool,chain.from_iterable(grid))))
```
```golang []
func projectionArea(grid [][]int) (ans int) {
	for i:=0;i<len(grid);i++ { //行列可以一起整来着
		row,col:=0,0
		for j:=0;j<len(grid);j++ {
			if grid[i][j]!=0 { //有一个非零的元素
				ans++
			}
			if t:=grid[i][j];t>row { //更新行最大
				row=t
			}
			if t:=grid[j][i];t>col { //更新列最大
				col=t
			}
		}
		ans=ans+row+col
	}
	return
}
```
