### 解题思路
![image.png](https://pic.leetcode-cn.com/63635ae61141629d099fcd612b049a65b154c69e10d6cd4058c83cc69f25c0e2-image.png)

1. 并查集合并包含共同邮件地址的账号的数组下标；
2. emailToID记录邮件地址第一次出现的账号下标；
3. 依次遍历所有账号的邮件地址；
4. 通过查找emailToID，判断是否有可合并的账号；
5. 遍历emailToID，通过并查集获取邮件所属的集合ID；
6. 组织返回结果。

### 代码

```golang
type UnionFind struct {
	count int
	parent []int
}

func (u *UnionFind) Init(count int) {
	u.count = count
	u.parent = make([]int, count)
	for i, _ := range u.parent {
		u.parent[i] = -1
	}
}

func (u *UnionFind) Find(node int) int {
	if u.parent[node] < 0 {
		return node
	}
	result := u.Find(u.parent[node])
	u.parent[node] = result
	return result
}

func (u *UnionFind) Union(node1 int, node2 int) (int, bool) {
	root1 := u.Find(node1)
	root2 := u.Find(node2)
	if root1 == root2 {
		return root2, false
	}
	u.parent[root1] = root2
	u.count--
	return root2, true
}

func accountsMerge(accounts [][]string) [][]string {
	var uf UnionFind
	uf.Init(len(accounts))
	emailToID := make(map[string]int, len(accounts))

	for i, account := range accounts {
		for _, val := range account[1:] {
			findIdx, ok := emailToID[val]
			if !ok {
				emailToID[val] = i
				continue
			}
			uf.Union(i, findIdx)
		}
	}

	tmpWork := make([][]string, len(accounts))
	for k, v := range emailToID {
		p := uf.Find(v)
		if tmpWork[p] == nil {
			tmpWork[p] = []string{k}
			continue
		}
		tmpWork[p] = append(tmpWork[p], k)
	}
	var result [][]string
	for i, r := range tmpWork {
		if r == nil {
			continue
		}
		sort.StringSlice(r).Sort()
		result = append(result, append([]string{accounts[i][0]}, r...))
	}

	return result
}
```