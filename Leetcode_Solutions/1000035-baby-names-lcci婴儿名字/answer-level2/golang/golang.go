### 解题思路
并查集
![image.png](https://pic.leetcode-cn.com/f782f2d1e5aba6fcd17fb51a3f0e187e4ecdd778fca89498eefa56189e77ac18-image.png)


### 代码

```golang
type BabyUnionFind struct {
	parent []int
	names  []string
	cnts   []int
}

func (b *BabyUnionFind) Init(names []string, cnts []int) {
	b.parent = make([]int, len(names))
	for i := 0; i < len(names); i++ {
		b.parent[i] = -1
	}
	b.names = names
	b.cnts = cnts
}

func (b *BabyUnionFind) Find(node int) int {
	if b.parent[node] < 0 {
		return node
	}
	tparent := b.Find(b.parent[node])
	b.parent[node] = tparent
	return tparent
}

func (b *BabyUnionFind) Union(first, second int) int {
	fp := b.Find(first)
	sp := b.Find(second)
	result := fp
	if fp == sp {
		return result
	}
	if b.names[fp] < b.names[sp] {
		b.parent[sp] = fp
		b.cnts[fp] += b.cnts[sp]
	} else {
		b.parent[fp] = sp
		b.cnts[sp] += b.cnts[fp]
		result = sp
	}
	return result
}

func trulyMostPopular(names []string, synonyms []string) []string {
	var onlyNames []string
	var indexs []int
	nameToIndex := make(map[string]int, len(names))
	var buf BabyUnionFind

	for i, name := range names {
		tstrs := strings.Split(name, "(")
		onlyNames = append(onlyNames, tstrs[0])
		tcnts := strings.Split(tstrs[1], ")")
		tcnt, _ := strconv.Atoi(tcnts[0])
		nameToIndex[tstrs[0]] = i
		indexs = append(indexs, tcnt)
	}
	buf.Init(onlyNames, indexs)

	for _, synony := range synonyms {
		synony = strings.TrimLeft(synony, "(")
		synony = strings.TrimRight(synony, ")")
		tstrs := strings.Split(synony, ",")
		first, _ := nameToIndex[tstrs[0]]
		second, _ := nameToIndex[tstrs[1]]
		buf.Union(first, second)
	}

	var result []string
	for i, v := range buf.parent {
		if v < 0 {
			tmp := buf.names[i] + "(" + strconv.Itoa(buf.cnts[i]) + ")"
			result = append(result, tmp)
		}
	}
	return result
}
```