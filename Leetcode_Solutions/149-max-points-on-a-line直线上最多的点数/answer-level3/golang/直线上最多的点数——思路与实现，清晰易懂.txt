# 解法一

碰到这种题，首先想暴力解法，然后一点点优化。本题思路也很直接，就是将每两个点连成一条直线，然后测试剩余的点是否在这条直线上。

先来回顾下直线的表示方式：两点式、斜截式、点斜式。使用点斜式又是另外一种思路（参考windliang大佬的[详细通俗的思路分析，多解法](https://leetcode-cn.com/problems/max-points-on-a-line/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--35/)）。

两点式公式： `(y-y1)/(x-x1) = (y2-y1)/(x2-x1)`，似乎是最适合本题的表达式，因为给出的都是点坐标嘛!但实际上不同的两点之间也很有可能组成同一条直线，使用两点式表示直线会让我们没办法去重。

斜截式公式：`y = kx + b`，对于每两点确定的直线，都可以计算出k,b两个参数(斜率与截距)，从而确保了直线的唯一性，有利于代码实现时的去重。

那么根据两点坐标`(x1,y1)`和`(x2,y2)`求`k`和`b`的公式为：

- `k = (y2 - y1) / (x2 - x1)`
- `b = y1 - kx1`

有了这个计算公式，我们就可以用`k`和`b`来表征一条唯一的直线，前面说过使用斜截式的目的是为了对遍历到的直线去重，那么就是说直线与直线之间需要进行比较，进一步讲，`k`和`b`需要比较。显然`k`和`b`很可能是小数甚至是无理数，对于计算机而言这只能通过浮点数存储，而且由于浮点数的精度问题，它们始终无法精确比较。

这就要求`k`和`b`不能使用小数表示，而使用分数表示似乎是个可行的方案：`k = k1/k2`和`b = b1/b2`。并且为了`k1、k2、b1、b2`的可比较性和其表征的直线的唯一表示性，`k1/k2`和`b1/b2`必须化到最简。这就引出了两整数化简的方法：求最大公约数。这里给出辗转相除的最大公约数实现：

```go
func gcd(a,b int) int {
	for b!=0 {
		a, b = b, a%b
	}
	return a
}
```

有了以上基础，我们可以定义一些结构体或者说类，来方便描述（尽管这并不是必须）：

```go
// 定义Point，便于理解和实现（直接用数组也行，但是容易疏忽写错）
type Point struct {
	x, y int
}


// 定义斜率K
type K struct {
	k1, k2 int	// k1分子,k2分母
}

// 定义截距B
type B struct {
	b1, b2 int	// b1分子,b2分母
}

// 定义Line，便于理解实现
type Line struct {
	K
	B
	c int	// c默认为0(非竖直线情况)，若为垂直线，方程为 x=c，k1=k2=b1=b2=0（其实只需要k2=0就足够了）
}
```

这里需要注意的是`Line`有一个字段`c`，这是因为斜截式无法表示斜率无穷大也就是垂直于x轴的直线。

我们还需要两个方法：一个用来根据两个`Point`生成`Line`，另一个则检查某个`Point`是否存在于`Line`上：

```go
func NewLine(p,q Point) Line {
	// k = (y2-y1)/(x2-x1); b = y1-k*x1

	// 特殊情况是垂直线，x=x2, (k=inf，b=inf)
	if p.x == q.x {
		return Line{c:p.x}
	}

	// 计算斜率
	k1, k2 := p.y - q.y, p.x - q.x
	g1 := gcd(k1, k2)
	k := K{k1/g1, k2/g1}

	// 计算截距
	b1, b2 := q.y * k.k2 - k.k1 * q.x, k.k2
	g2 := gcd(b1, b2)
	b := B{b1/g2, b2/g2}

	return Line{K:k,B:b}
}

// 判断线上是否有这么一点
// 判断某个点是否在直线上则是 y = k1/k2 * x + b1/b2  => y*k2*b2 ?= k1*b2*x + k2*b1
func (l Line) HasPoint(p Point) bool {
	if l.k2==0 {	// 竖直线
		return p.x == l.c
	}
	return p.y * l.k2 * l.b2 == l.k1 * l.b2 * p.x + l.k2 * l.b1
}
```

有了这些定义之后，就可以得出解法的总流程了：

```go
// 三层循环
max := 0
for i:=0; i<n; i++ {
	for j:=i+1; j<n; j++ {
		line = NewLine(两个点)
		if line出现过 {continue}
		count := 2
		for p := range 除这两点以外的所有点 {
			if line.HasPoint(p) {count++} 
		}
		if count > max {max = count}
	}
}
```

当然，为了记录`Line`的的出现与否，需要用一个哈希表去记录。

对了，在题目的测试样例中，认为所有点相同也算一条直线，并且应该返回n，所以需要在进入三层循环之前就需要处理掉:

```go
i := 0
for ; i<n-1; i++ {
	if points[i][0] != points[i+1][0] || points[i][1] != points[i+1][1] {break}
}
if i==n-1 {return n}
```

以下是完整代码实现，欢迎参考：


```go
package lt149

// 直线上最长的点

// 思考：
// 暴力搜索比较，每两个点作为一条直线，判断其他点是否在这条直线上

// 暴力直观的思路
// 直线的两点表示法： (y-y1)/(x-x1) = (y2-y1)/(x2-x1)
// 直线的斜率表示法： y = kx + b
// 这两个表示法中，两点表示方法方便直观地判断一个点是否在一条直线上
// 但由 y = kx + b 可以使用 k,b两参数确定一条直线，计算好k,b之后，
// 可以用其表示一条独一无二的直线，这可以有效的去重!!
// 由于浮点数不能直接比较，所以k,b都必须使用两个整数来表示分子与分母(并且要化到最简)
// 判断某个点是否在直线上则是 y = k1/k2 * x + b1/b2  => y*k2*b2 ?= k1*b2*x + k2*b1
func maxPoints(points [][]int) int {
	n := len(points)	// 每个point是个长度为2的数组，就不检查长度是否为2了
	if n < 3 {return n}	// 特殊情况

	// 特殊情况：测例认为所有点相同，也算是直线，并返回n
	i := 0
	for ; i<n-1; i++ {
		if points[i][0] != points[i+1][0] || points[i][1] != points[i+1][1] {break}
	}
	if i==n-1 {return n}

	// 用于记录直线的哈希表，值为直线所拥有的点数量
	lines := make(map[Line]int)

	// 遍历points，统计所有line包含的点数
	var line Line
	count := 0
	for i:=0; i<n; i++ {	// 这两层循环保证将所有两点的组合都取出
		for j:=i+1; j<n; j++ {
			// 避免两个点相同
			if points[i][0] == points[j][0] && points[i][1] == points[j][1] {continue}

			// 固定了一条直线，当前这轮中就需要检查所有点是否在直线上
			line = NewLine(Point{points[i][0], points[i][1]}, Point{points[j][0], points[j][1]})

			// 检查line是否前面生成过，由于前面的检查的点位更多，所以只要
			// 重复出现了line，那后面重复出现的都没必要去查看line上有几个点
			if lines[line] != 0 {continue}

			// line不曾出现过，则去遍历这条line有多少个点
			count = 2	// 线原本就有两点
			for a:=0; a<n; a++ {
				if a==i || a==j {continue}
				if line.HasPoint(Point{points[a][0], points[a][1]}) {count++}
			}

			// 记录line对应的点数
			lines[line] = count
			//fmt.Println(line, count)
		}
	}

	// 再遍历一遍lines哈希表，得到最大值
	max := 0
	for _, v := range lines {
		if v > max {max = v}
	}

	return max
}

// 由于测试时需要多次调用，所以在函数外定义较好

// 定义Point，便于理解和实现（直接用数组也行，但是容易疏忽写错）
type Point struct {
	x, y int
}


// 定义斜率K
type K struct {
	k1, k2 int	// k1分子,k2分母
}

// 定义截距B
type B struct {
	b1, b2 int	// b1分子,b2分母
}

// 定义Line，便于理解实现
type Line struct {
	K
	B
	c int	// c默认为0(非竖直线情况)，若为垂直线，方程为 x=c，k1=k2=b1=b2=0（其实只需要k2=0就足够了）
			// 以作判断(注意不能直接用c==0判断，因为可能有x=0的竖直线)
}

func NewLine(p,q Point) Line {
	// k = (y2-y1)/(x2-x1); b = y1-k*x1

	// 特殊情况是垂直线，x=x2, (k=inf，b=inf)
	if p.x == q.x {
		return Line{c:p.x}
	}

	// 计算斜率
	k1, k2 := p.y - q.y, p.x - q.x
	g1 := gcd(k1, k2)
	k := K{k1/g1, k2/g1}

	// 计算截距
	b1, b2 := q.y * k.k2 - k.k1 * q.x, k.k2
	g2 := gcd(b1, b2)
	b := B{b1/g2, b2/g2}

	return Line{K:k,B:b}
}

// 判断线上是否有这么一点
// 判断某个点是否在直线上则是 y = k1/k2 * x + b1/b2  => y*k2*b2 ?= k1*b2*x + k2*b1
func (l Line) HasPoint(p Point) bool {
	if l.k2==0 {	// 竖直线
		return p.x == l.c
	}
	return p.y * l.k2 * l.b2 == l.k1 * l.b2 * p.x + l.k2 * l.b1
}

// 辗转相除， 计算公约数
func gcd(a,b int) int {
	for b!=0 {
		a, b = b, a%b
	}
	return a
}

```
