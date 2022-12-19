### 解题思路
贪心算法：每次选最多的2，次多的1，拼接。

### 代码

```golang
type Node struct {
	ch byte
	num int
}

type NodeList []*Node

func (n NodeList) Len() int {
	return len(n)
}

func (n NodeList) Less(i, j int) bool {
	return n[i].num > n[j].num
}

func (n NodeList) Swap(i, j int) {
	n[i], n[j] = n[j], n[i]
}

// 每次选最多的2，次多的1，拼接
func longestDiverseString(a int, b int, c int) string {
	res := []byte{}
	nl := NodeList{}
	na := Node{'a', a}
	nb := Node{'b', b}
	nc := Node{'c', c}
	nl = append(nl, &na)
	nl = append(nl, &nb)
	nl = append(nl, &nc)
	sort.Sort(nl)
	for nl[0].num > 0 {
		tmp := []byte{}
		if nl[1].num > 0 {
			for i:=0; i<2; i++ {
				if nl[0].num > 0 {
					tmp = append(tmp, nl[0].ch)
					nl[0].num--
				}
			}
			tmp = append(tmp, nl[1].ch)
			nl[1].num--

			if len(res) > 0 {
				if res[len(res)-1] == tmp[0] {
					reverse(tmp)
				}
			}

			res = append(res, tmp...)
		} else {
			lastChNum := 0
			ch := byte('d')
			if len(res) > 2 && res[len(res)-2] == res[len(res)-1] {
				lastChNum = 2
				ch = res[len(res)-1]
			} else if len(res) == 1 {
				ch = res[len(res)-1]
			}

			if ch == nl[0].ch {
				for i:=0; i<2-lastChNum; i++ {
					if nl[0].num > 0 {
						res = append(res, nl[0].ch)
						nl[0].num--
					}
				}
			} else {
				for i:=0; i<2; i++ {
					if nl[0].num > 0 {
						res = append(res, nl[0].ch)
						nl[0].num--
					}
				}
			}
			break
		}
		sort.Sort(nl)
	}
	return string(res)
}

func reverse(s []byte) {
	for i:=0; i<len(s)/2; i++ {
		s[i], s[len(s)-1-i] = s[len(s)-1-i], s[i]
	}
}

```