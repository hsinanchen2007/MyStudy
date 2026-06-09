### 解题思路
此处撰写解题思路

### 代码

```golang
func findMedianSortedArrays(a []int, b []int) float64 {
   if len(a) == 0 && len(b) == 0 {
		return 0
	}
	if ln := len(a) + len(b); ln%2 == 0 {
		return float64(findMiddle(a, b, ln/2-1)+findMiddle(a, b, ln/2)) / 2
	} else {
		return float64(findMiddle(a, b, ln/2))
	}
	return 0
}

func findMiddle(a, b []int, i int) int {
	n := 0
	la := 0
	lb := 0
	cur := 0
	lena := len(a)
	lenb := len(b)
	for {
		if n > i {
			break
		}
		if lena > la && lenb > lb {
			if a[la] >= b[lb] {
				cur = b[lb]
				lb++
			} else {
				cur = a[la]
				la++
			}
		} else if lena > la {
			cur = a[la]
			la++
		} else if lenb > lb {
			cur = b[lb]
			lb++
		}
		n++
	}
	return cur
}
```