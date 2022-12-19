**思路**:见标题
**注意**:构造另外两点时需要判断一个已有边的斜率 一种情况是斜率>0 另一种情况是斜率<=0/不存在 这两种情况下两点的构造是有一些区别的 但不管怎样 都能通过一条边得到两条可能的边 且一左一右 可以画个简单的图理解一下 最后 本人菜鸡 以下代码仅供参考 还请大家多多指教
```python []
class Solution:
	def validSquare(self,p1,p2,p3,p4):
		def helper(p1,p2,p3,p4):
			if p1==p2: #出现了相同的两个点直接就是False
				return False
			_x,_y=p1[0]-p2[0],p1[1]-p2[1] #为下面求解slope(斜率)+x_offset+y_offset做准备
			slope=True if not _y or _x*_y<=0 else False #斜率>0是False 否则(<=0/不存在)是True
			x_offset=abs(_x) if slope else -abs(_x) #斜率<0时取负数
			y_offset=abs(_y)
			ans_1=set((x-y_offset,y-x_offset) for x,y in [p1,p2]) #生成器推导+set 用set是因为方便比较 x,y用了tuple形式是因为tuple是hashable的
			ans_2=set((x+y_offset,y+x_offset) for x,y in [p1,p2])
			real=set([tuple(p3),tuple(p4)]) #给定的另外两个点组成的set
			return ans_1==real or ans_2==real
		return helper(p1,p2,p3,p4) or helper(p1,p3,p2,p4) #有可能p1,p2组成的线段正好是给定正方形的对角线 那么上面的函数就没有意义了 所以需要第二个helper调用
```
```golang []
func validSquare(p1 []int, p2 []int, p3 []int, p4 []int) bool {
	helper:=func(p1,p2,p3,p4 []int) bool { //虽然go不能够命名函数的嵌套定义 但是这种将一个匿名函数赋值给一个函数变量 还是可以的
		_x,_y:=p1[0]-p2[0],p1[1]-p2[1]
		if _x==0 && _y==0 { //出现了相同的点直接就是false
			return false
		}
		var slope bool
		if _y==0 || _x*_y<=0 { //两个点组成的线段的斜率 这会影响到下面的x_offset/y_offset 进而影响到可能点的x,y的值
			slope=true
		}
		x_offset:=int(math.Abs(float64(_x)))
		y_offset:=int(math.Abs(float64(_y)))
		if !slope { //斜率大于0的情况 x_offset取反
			x_offset*=-1
		}
		p_3,p_4:=[2]int{p3[0],p3[1]},[2]int{p4[0],p4[1]} //将给定的[]int类型的点改成[2]int类型 方便直接比较
		ans_1:=[2][2]int{{p1[0]-y_offset,p1[1]-x_offset},{p2[0]-y_offset,p2[1]-x_offset}} //左部的两个点
		if (p_3==ans_1[0] && p_4==ans_1[1]) || (p_3==ans_1[1] && p_4==ans_1[0]) {
			return true
		}
		ans_2:=[2][2]int{{p1[0]+y_offset,p1[1]+x_offset},{p2[0]+y_offset,p2[1]+x_offset}} //右部的两个点
		if (p_3==ans_2[0] && p_4==ans_2[1]) || (p_3==ans_2[1] && p_4==ans_2[0]) {
			return true
		}
		return false //没有匹配的就是false了
	}
	return helper(p1,p2,p3,p4) || helper(p1,p3,p2,p4) //有可能p1,p2是正方形任一对角线上的两点 这时上述函数没有什么意义 所以还需要后面一个
}
```
