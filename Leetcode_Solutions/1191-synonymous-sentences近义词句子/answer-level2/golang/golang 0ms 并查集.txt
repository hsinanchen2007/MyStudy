1. 构造并查集
2. 构造新字符串
最近写的代码都超长超烂。。。
```
func generateSentences(synonyms [][]string, text string) []string {
	var (
		m      = map[string]int{}
		idx    int
		sz, id = make([]int, 0), make([]int, 0)
	)
	for _, s := range synonyms {
		if _, ok := m[s[0]]; !ok {
			m[s[0]] = idx
			sz = append(sz, 1)
			id = append(id, idx)
			idx++
		}
		if _, ok := m[s[1]]; !ok {
			m[s[1]] = idx
			sz = append(sz, 1)
			id = append(id, idx)
			idx++
		}
	}
	for _, s := range synonyms {
		union(m[s[0]], m[s[1]], sz, id)
	}
	same := map[int][]string{}
	for k, v := range m {
		same[id[v]] = append(same[id[v]], k)
	}
	ret := ctrc(strings.Split(text, " "), m, id, same)
	sort.Strings(ret)
	return ret
}

func ctrc(texts []string, m map[string]int, id []int, same map[int][]string) []string {
	if len(texts) == 0 {
		return []string{}
	}
	add := []string{}
	sub := ctrc(texts[1:], m, id, same)
	if v, ok := m[texts[0]]; !ok {
		add = []string{texts[0]}
	} else {
		add = same[find(v, id)]
	}
	if len(sub) == 0 {
		return add
	}
	ret := []string{}
	for _, a := range add {
		for _, s := range sub {
			ret = append(ret, a+" "+s)
		}
	}
	return ret
}

func union(i, j int, sz, id []int) {
	x := find(i, id)
	y := find(j, id)
	if x == y {
		return
	}
	if sz[x] < sz[y] {
		id[x] = y
		sz[y] += sz[x]
	} else {
		id[y] = x
		sz[x] += sz[y]
	}
}

func find(x int, id []int) int {
	for x != id[x] {
		id[x] = id[id[x]]
		x = id[x]
	}
	return id[x]
}

```
