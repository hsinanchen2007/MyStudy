### 解题思路
感觉没得什么算法可言，纯业务理解，相比其他的解题思路来说，非常好理解。
找出重复命中的，和未命中的，然后把重复命中的插入到相应的位置。
### 代码

```golang
func relativeSortArray(arr1 []int, arr2 []int) []int {
	notExists := []int{}
	exists := map[int]int{} // value int count
	for _, a1 := range arr1 {
		isHit := false
		for _, a2 := range arr2 {
			if a1 == a2 {
				isHit = true
				break
			}
		}
		if !isHit {
			// 找出没有命中的数字后面升序后append到结尾
			notExists = append(notExists, a1)
		} else {
			// 看存在的数字重复几次，然后进行插入
			n, ok := exists[a1]
			if ok {
				exists[a1] = n + 1
			} else {
				exists[a1] = 0
			}
		}
	}
	// 这句是和别的解题思路不一样的地方， 直接用 arr2 替换 arr1
	// 这样我arr1与arr2完全一样
	arr1 = arr2
	for k, n := range exists {
        // 在把之前命中了的存在多个的数，插入到命中数的后面
		if n == 0 {
			continue
		}
		for i, a1 := range arr1 {
			if k == a1 {
				insert := make([]int, n)
				for n > 0 {
					n--
					insert[n] = k
				}
				insert = append(insert, arr1[i:]...)
				arr1 = append(arr1[:i], insert...)
				break
			}
		}
	}
	// 追加未命中排序后的
    sort.Ints(notExists)
	arr1 = append(arr1, notExists...)
	return arr1
}
```