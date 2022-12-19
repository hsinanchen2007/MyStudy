### 解题思路
此处撰写解题思路

### 代码

```golang
func minDistance(word1 string, word2 string) int {
    mem := make(map[string]int)
	return helper(word1, word2,&mem)
}

func helper(word1, word2 string,mem *map[string]int) int {
    if (*mem)[word1] != 0 {
        return (*mem)[word1]
    }
	if word1 == word2 {
		return 0
	}
	var (
		pos = 0
	)
	for pos < len(word1) && pos < len(word2) && word1[pos] == word2[pos] {
		pos++
	}
	if pos >= len(word1) {
		return len(word2) - pos
	}
	if pos >= len(word2) {
		return len(word1) - pos
	}
	resIn := helper(word1[:pos]+string(word2[pos])+word1[pos:], word2,mem) + 1
	resDel := helper(word1[:pos]+word1[pos+1:], word2,mem) + 1
	resRep := helper(word1[:pos]+string(word2[pos])+word1[pos+1:], word2,mem) + 1
    res := getMin(resIn, resDel, resRep)
    (*mem)[word1] = res
	return res
}

func getMin(nums ...int) int {
	min := math.MaxInt32
	for _, val := range nums {
		if val < min {
			min = val
		}
	}
	return min
}
```