### 解题思路
此处撰写解题思路

### 代码

```golang
type AndCheck struct {
	Parent []int // 每个并查集元素都有一个parent数组指向它自己
	Rank   []int // 维护每个元素在并查集树中的排名
}
// 初始化
func (this *AndCheck) Init(n int) {
	this.Parent = make([]int, n)
	this.Rank = make([]int, n)
	for i := 0; i < n; i++ {
		this.Parent[i] = i
		this.Rank[i] = 1
	}
}

// 查询find的根节点
/*
	不断查找ele的parent,直到parent[ele] = ele
*/
func (this *AndCheck) Find(ele int) int {
	return this.find(ele)
}
func (this *AndCheck) find(ele int) int {
	for ele != this.Parent[ele]  {
		this.Parent[ele] = this.Parent[this.Parent[ele]]
		ele = this.Parent[ele]
	}
	return ele
}

// 合并
// 首先分别找到p, q的领头节点、如果相同则直接返回
// 否则将基本一个的parent置为另一个
// 最后将并查集中独立集合数量减1
func (this *AndCheck) Union(p, q int) {
	pRoot := this.find(p)
	qRoot := this.find(q)
	if pRoot == qRoot {
		return
	}
	if this.Rank[pRoot] > this.Rank[qRoot] {
		this.Parent[qRoot] = pRoot
	} else if this.Rank[pRoot] < this.Rank[qRoot]{
		this.Parent[pRoot] = qRoot
	} else {
		this.Parent[pRoot] = qRoot
		this.Rank[qRoot]++
	}
}

//leetcode submit region begin(Prohibit modification and deletion)
/*
	思路1:并查集
	有N个朋友、将每个朋友当成一个独立的集合
	然后遍历好友矩阵、对于M[i][j] = 1的i和j的集合进行合并
	最后查看有多少个独立的不重复的集合、就是对应的朋友圈数量
	首先需要实现一个并查集
*/
func findCircleNum(M [][]int) int {
	m := len(M)
	n := len(M[0])
	ac := &AndCheck{}
	ac.Init(n)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if M[i][j] == 1 {
				ac.Union(i, j)
			}
		}
	}
	m_nodes := make(map[int]bool)
	// 遍历所有朋友、查看此时并查集中有多少个不同的独立集合
	for i := 0; i < n; i++ {
		m_nodes[ac.find(i)] = true
	}
	return len(m_nodes)
}
```