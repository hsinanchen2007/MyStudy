### 解题思路
此处撰写解题思路

### 代码

```golang

func groupStrings(strings []string) [][]string {
	if len(strings) == 0 {
		return [][]string{}
	}
	m := make(map[int][]string)
	r := make([][]string, 0)
	for _, s := range strings {
		if v, ok := m[len(s)]; ok {
			m[len(s)] = append(v, s)
		} else {
			m[len(s)] = []string{s}
		}
	}
	deleK := make([]int, 0)
	for k, v := range m {
		if k == 1 || len(v) == 1 {
			r = append(r, v)
			deleK = append(deleK, k)
		}
	}

	for _, v := range deleK {
		delete(m, v)
	}

	for _, v := range m {
		tr := getSeq(v)
		if len(tr) != 0 {
			r = append(r, tr...)
		}
	}

	return r
}

func getSeq(strLst []string) [][]string {
	sort.Strings(strLst)
	r := make([][]string, 0)
	l1 := []string{strLst[0]}
	other := []string{}
	s1 := []byte(strLst[0])
	for i := 1; i < len(strLst); i++ {
		s2 := []byte(strLst[i])
		if possible(s1, s2, len(s1)) {
			l1 = append(l1, string(s2))
		} else {
			other = append(other, string(s2))
		}
	}
	r = append(r, l1)

	if len(other) == 0 {
		return r
	}

	if len(other) == 1 {
		r = append(r, other)
		return r
	}

	rs := getSeq(other)
	if len(rs) > 0 {
		r = append(r, rs...)
	}
	return r
}

func possible(s1, s2 []byte, n int) bool {
	diff := s2[0] - s1[0]

	for i := 1; i < n; i++ {
		exp := s1[i]+diff
		if exp > 'z' {
			exp = 'a' + exp - 'z' - 1
		}
		if exp != s2[i] {
			return false
		}

	}
	return true
}

```