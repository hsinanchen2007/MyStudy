**思路:**
解释一下标题的第一部分 这边以题目描述中给定的例子为例
```
 原先:
     [3, 3, 1, 1]
     [2, 2, 1, 2]
     [1, 1, 1, 2]
 变换后:
     [0, 0, 3, 3, 1, 1]
     [0, 2, 2, 1, 2, 0]
     [1, 1, 1, 2, 0, 0]
```
显然这样子每一列就是从左下角到右上角的每一条对角线上相应的数字们了(把0去掉)
排序的话直接使用sorted/sort就可以了
最后放回我实在是语死早 不太好说明 如果可以的话麻烦大家照着代码的思路简单地模拟一下(本人菜鸡/(ㄒoㄒ)/~~)
**注意:**
第一步会产生不少的无用数字(上面以0为例) 但写起来还算是比较简单 算是个大家提供一个想法8 还请大家多多指教
```python []
#代码中用的是None而不是0 主要是懒得再写fillvalue=0了
from itertools import zip_longest
class Solution:
	def diagonalSort(self,mat):
		ans,legt=[],len(mat)
		for i in zip_longest(*([None]*i+j for i,j in zip(range(legt-1,-1,-1),mat))): #zip_longest实现了取列
			if len(ans)!=legt:
				ans.insert(0,[]) #因为最后ans的len是和legt一样子的
			for	i,j in enumerate(sorted(filter(bool,i))): #filter去掉了本来没有的0 sorted实现了排序
				ans[i].append(j) #之后按照正对角线的顺序依次添加一个数字 这就是放回了
		return ans
```
```golang []
import "sort"
func diagonalSort(mat [][]int) [][]int {
	len_row,len_col:=len(mat),len(mat[0]) //行数 列数
	ans:=make([][]int,len_row) //表示结果的二维slice
	le,ri:=len_row-1,0 //左边补充的0的数目 右边补充的0的数目 -> 模拟出右移的状态
	for i,j:=range mat {
		mat[i]=append(make([]int,le),append(j,make([]int,ri)...)...) //补充0
		le,ri=le-1,ri+1
	}
	cols:=make([][]int,len_col+len_row-1) //每列的数字们
	for i:=0;i<len(cols);i++ { //取列的同时去零
		col:=make([]int,0,len_row)
		for j:=0;j<len_row;j++ {
			if v:=mat[j][i];v!=0 {
				col=append(col,v)
			}
		}
		cols[i]=col
	}
	row_idx:=len_row
	for _,i:=range cols { //放回
		if row_idx>=1 { //相当于py的insert(0,[]) 也就是添加一个[]int 这样子才能实现对角线放回 但是添加的[]int有个数限制
			row_idx--
			ans[row_idx]=make([]int,0)
		}
		sort.Ints(i) //就地排序
		for x,y:=range i { //依次放回
			ans[row_idx+x]=append(ans[row_idx+x],y)
		}
	}
	return ans
}
```



