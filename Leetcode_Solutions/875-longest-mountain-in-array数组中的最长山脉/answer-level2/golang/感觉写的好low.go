虽然写的low，还是记录一下吧，就是暴力遍历（我发现我每一次都是暴力遍历），用一个标记up位标记是升序还是降序，同时两个标记为标记降序前面是否有升序，是否有降序。同时标记一组数据的开始和结束（标记为是不是有点多），还有每一次数据的最大值，然后开始遍历。。。
```
func longestMountain(A []int) int {
    if len(A) < 3 {
		return 0
	} 
	offsetStart, offsetEnd := 0, 0
	hasUp := false
	hasDown := false
	up := true
    max := 0
	for i := 0; i < len(A)-1; i++ {
		if up {
			if A[i] < A[i+1] {
				hasUp = true
			}else if !hasUp {
				offsetStart = i+1
			}else {
				if A[i] > A[i+1] {
					up = false
					offsetEnd = i+1
					hasDown = true
				}else {
					up = true
					hasUp = false
					offsetStart = i+1
				}
			}
		} else {
			if A[i] > A[i+1] {
				up = false
				offsetEnd = i+1
				hasDown = true
			} else if !hasDown {
				up = true
				hasUp = false
				offsetStart = i
			} else {
	            if offsetEnd > offsetStart {
                    if offsetEnd - offsetStart + 1 > max{
                        max = offsetEnd - offsetStart + 1
                    }
	            }
				up = true
				if A[i] < A[i+1] {
					hasUp = true
					offsetStart = i
					offsetEnd = i
				}else {
					hasUp = false
					offsetStart = i+1
					offsetEnd = i + 1
				}
				hasDown = false
			}
		}
	}
    if offsetEnd > offsetStart {
        if offsetEnd - offsetStart + 1 > max{
            max = offsetEnd - offsetStart + 1
        }
    }
	return max
}
```
