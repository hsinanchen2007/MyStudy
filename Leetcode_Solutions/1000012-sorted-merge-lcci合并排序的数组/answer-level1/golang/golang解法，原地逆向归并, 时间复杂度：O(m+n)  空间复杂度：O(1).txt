golang解法，逆向归并

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```go
// 归并思路，逆向归并到数组A中，可避免另外开辟空间
// 时间复杂度：O(m+n)  空间复杂度：O(1)

func merge(A []int, m int, B []int, n int)  {

	a := m-1  // 数组A的当前被操作元素的索引,初始为最末元素
	b := n-1  // 数组B的当前被操作元素的索引,初始为最末元素

	for i:=m+n-1; i>=0; i-- {
		if a>=0 && b>=0 {
			if A[a]>B[b] {
				A[i] = A[a]
				a--
			}else {
				A[i] = B[b]
				b--
			}
		}else if a<0 {
			A[i] = B[b]
			b--
		}else {
			A[i] = A[a]
			a--
		}
	}
}
```
