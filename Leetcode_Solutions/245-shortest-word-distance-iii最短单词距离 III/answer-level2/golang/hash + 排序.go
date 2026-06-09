### 解题思路
此处撰写解题思路

### 代码

```golang

func shortestWordDistance(words []string, word1 string, word2 string) int {
	if len(words) < 2 {
		return -1
	}

	m := make(map[string][]int)
	for i := 0; i < len(words); i++ {
		if v, ok := m[words[i]]; ok {
			m[words[i]] = append(v, i)
		} else {
			m[words[i]] = []int{i}
		}
	}

	p1 := m[word1]
	p2 := m[word2]

	if word1 != word2 {
		min := math.MaxInt32
		for i := 0; i < len(p1); i++ {
			for j := 0; j < len(p2); j++ {
				diff := int(math.Abs(float64(p1[i] - p2[j])))
				if min > diff {
					min = diff
				}
			}
		}
		return min

	} else {
		sort.Ints(p1)
		min := math.MaxInt32
		for i := 0; i < len(p1)-1; i++ {
			diff := p1[i+1] - p1[i]
			if min > diff {
				min = diff
			}
		}
		return min
	}

}
```