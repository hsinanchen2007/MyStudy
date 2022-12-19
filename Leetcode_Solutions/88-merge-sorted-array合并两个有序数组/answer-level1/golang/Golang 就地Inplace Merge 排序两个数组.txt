### 解题思路

这道题不需要使用额外空间来进行`merge`。
因为nums1已经有足够的空间。
我们从两个数组的后端（也就是最大值开始）比较。

```
[1,2,3,0,0,0] vs [2,5,6]
first 指向第一个数组的最大元素。
second 指向第二个数组的最大元素。

i指向num1的最后一位 m + n -1。

如代码所示。我们只需要交替比较和替换就能够进行就地merge。

```
### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
	first := m - 1
	second := n - 1

	for i := m + n -1; i >= 0 ; i-- {
		// nums2 has already been merged.
		if second < 0 {
			break
		}
		if first >=0 && nums1[first] > nums2[second] {
			nums1[i] = nums1[first]
			first--
		} else {
			nums1[i] = nums2[second]
			second--
		}
	}
}
```