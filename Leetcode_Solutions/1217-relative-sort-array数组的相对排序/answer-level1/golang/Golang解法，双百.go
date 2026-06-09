![image.png](https://pic.leetcode-cn.com/623c7a3a01346585892bba0127c4f9552633507663bd847f9645c4a94cb80d67-image.png)


```
func relativeSortArray(arr1 []int, arr2 []int) []int {
	lastIdx := 0
	for i := 0; i < len(arr2); i++ {
		for j := lastIdx; j < len(arr1); j++ {
			if arr1[j] == arr2[i] {
				arr1[lastIdx], arr1[j] = arr1[j], arr1[lastIdx]
				lastIdx++
			}
		}
	}
	sort.Ints(arr1[lastIdx:])
	return arr1
}
```
