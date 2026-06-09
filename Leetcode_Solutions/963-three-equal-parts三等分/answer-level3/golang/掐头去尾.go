要想数量三等分数值一样，首先每一份中1的数量得相等，找到两个位置x,y，分割三个1相等的数组，遍历判断最后一份 末尾0的个数zeroCount，然后判断，前面两份从x,y位置开始，向后数zeroCount位，遇到1，则说明不等，都没有1的话，则把x，y向后移zeroCount位，此时x，y正好将数组分成三份，先将三个数组前面的0去掉，然后判断三个数组的每一位值是否相等，全相等，则返回x，y，否则返回-1，-1
```
func threeEqualParts(A []int) []int {
c := oneCount(A)
	if c == 0 {
		return []int{0,len(A)-1}
	}

	if c%3 != 0 {
		return []int{-1, -1}
	}

	n := c/3
	i := 0
	x, y := -1,-1
	one, two, three := []int{},[]int{},[]int{}
	for idx, v := range A {
		if v == 1{
			i++
			if i == n {
				x = idx
			}else if i == 2*n {
				y = idx
				a := A[idx+1:]
				zeroCount := 0
				for j := len(a)-1; j >= 0; j--  {
					if a[j] == 0 {
						zeroCount++
					}else {
						break
					}
				}
				one = A[x+1: x+1+zeroCount]
				if hasOne(one) {
					return []int{-1, -1}
				}
				x = x+zeroCount
				two = A[y+1:y+1+zeroCount]
				if hasOne(two) {
					return []int{-1, -1}
				}
				y = y+zeroCount
				three = A[y+1:]
				break
			}
		}
	}
	one = cutHead(A[:x+1])
	two = cutHead(A[x+1:y+1])
	three = cutHead(A[y+1:])
	if len(one) != len(two) || len(one) != len(three) || len(two) != len(three) {
		return []int{-1,-1}
	}
	if el(one, two, three) {
		return []int{x,y+1}
	}
	return  []int{-1, -1}
}

func oneCount (a []int) int {
    i := 0
    for _, v := range a {
        if v == 1{
            i++
        }
    }
    return i
}

func hasOne (a[]int) bool {
    for _, v := range a {
        if v == 1 {
            return true
        }
    }
    return false
}
func cutHead (a []int) []int {
	index := -1
	for idx, v := range a {
		if v != 0 {
			index = idx
			break
		}
	}
	if index == -1 {
		return []int{}
	}
	return a[index:]
}

func el(a, b, c[]int) bool {
	if len(a) != len(b) || len(a) != len(c) || len(b) != len(c) {
		return false
	}
	for idx, va := range a {
		if va != b[idx] || va != c[idx] || b[idx] != c[idx] {
			return false
		}
	}
	return true
}


```
