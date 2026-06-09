### 解题思路
滑窗 + hashmap

### 代码

```golang
func lengthOfLongestSubstringTwoDistinct(s string) int {
	sb := []byte(s)
	length := len(sb)
	if length <= 2 {
		return length
	}

	m := make(map[byte][]int)

	first := sb[0]
	second := sb[1]
	m[first] = []int{0}
	if second == first {
		m[first] = []int{0, 1}
	} else {
		m[second] = []int{1}
	}

	max := 2
	left := 0
	for i := 2; i < length; i++ {
		b := sb[i]
		preB := sb[i-1]
		if v, ok := m[b]; ok {
			m[b] = append(v, i)
		} else {
			m[b] = []int{i}
		}

		if len(m) > 2 {
			for k, v := range m {
				if k != b && k != preB {
					left = v[len(v)-1] + 1
					diff := i - left
					if max < diff {
						max = diff
					}
					delete(m, k)
				}
			}
		} else {
			diff := i - left + 1
			if max < diff {
				max = diff
			}

		}

	}

	return max
}

```