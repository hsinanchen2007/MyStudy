### 解题思路

创建map和一个数组n，遍历nums数组.

1.若当前数组元素j没以key的形式存在map中，则创建一个在map中创建一个键值对[j]i，j为元素值，i为元素下标.

2.若存在，则用当前元素下标减去上一个该值的元素下标，差存放在数组n中，然后更新map元素[j]i.

遍历结束后，若数组n长度为0，说明没有重复元素，返回false。若数组排序取最小值n[0]，若比k小，则返回true，否则返回false

### 代码

```golang
func containsNearbyDuplicate(nums []int, k int) bool {
	m := make(map[int]int)
	n := []int{}
	for i,j := range nums {
		if _,ok := m[j]; ok {
			n = append(n,i - m[j])
            m[j] = i
		}else {
			m[j] = i
		}
	}
	if len(n) == 0 {
		return false
	}else {
		sort.Ints(n)
		if n[0] <= k {
		 return true	
		}else {
			return false
		}
	}
}
```