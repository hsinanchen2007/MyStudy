```golang
func merge(nums1 []int, m int, nums2 []int, n int) {

	// nums1的当前索引
	n1Index := 0

	// 遍历nums2中的每一个数
	for _, n2 := range nums2 {
		posFound := false

		// 为n2找到在nums1中的位置
		for ; n1Index <= len(nums1)-1; n1Index++ {
			if n2 < nums1[n1Index] { // 找到第一个比n2大的值x
				for i := m; i > n1Index; i-- { // 把x以及x之后的值都往后移一位，空出当前的位置
					nums1[i] = nums1[i-1]
				}
				posFound = true
			} else if n1Index >= m { // 如果已经超过了nums1有效元素的末尾，则当前位置可以直接放入n2
				posFound = true
			}
			if posFound { // 找到位置了，就把n2放入当前位置
				nums1[n1Index] = n2
				m++ // nums1中的有效元素个数增加
				break // 为下一个nums2中的数字找位置
			}
		}
	}
}

```
