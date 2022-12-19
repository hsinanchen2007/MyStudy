暴力遍历，首先要保证每个子数组里面都要有一个数在结果里，那就把每一个子数组里面的每一个元素每次放一个到临时数组中去形成一个结果。声明一个nums大小的数组，里面记录每一个子数组的下标，都从0开始，遍历一次，找到一组数据中的最小值，和最大值，和最小值所在的位置，并把它数组下标加1，如果有任何一个子数组加到最后同时他又是一组数据中最小值的时候，停止遍历。因为可能是每个子数组下标交替后移，最大的遍历次数就是所有子数组数量之和。最后拿到所有组数据，遍历用最大值-最小值，取最小的一组数据返回。一开始我存的每一组数据里面包含了每一个子数组当前下标的数据，然后再遍历这组数据去取最小值的位置，结果内存超出，尴尬，后面就只存了最大值和最小值，同时几率最小值的位置。因为数据元素在10^-5 到 10^5之间所以我这边最大值最小值就用的100001和-100001

```
func smallestRange(nums [][]int) []int {
	r := [][]int{}
	totalCount := 0
	for _, v := range nums {
		totalCount += len(v)
	}
	c := make([]int, len(nums))
	for i:=0;i<totalCount;i++ {
        a := make([]int, 2)
        a[0] = 100001
        minIdx := 0
		for idx, v := range nums {
            if v[c[idx]] <  a[0]{
                a[0] = v[c[idx]]
                minIdx = idx
            }
            if v[c[idx]] > a[1] {
                a[1] = v[c[idx]]
            }
		}
		r = append(r, a)
		if c[minIdx] < len(nums[minIdx]) - 1 {
			c[minIdx]++
		}else {
			break
		}
	}

	s := [][]int{}
	for _, v := range r {
		max, min := -100001, 100001
		for _, num := range v {
			if max < num {
				max = num
			}
			if min > num {
				min = num
			}
		}
		a := []int{min, max}
		s = append(s, a)
	}

	result := []int{}
	for _, v := range s {
		if len(result) == 0 {
			result = v
		}else {
			if v[1] - v[0] < result[1] - result[0] {
				result = v
			}
		}
	}
	return result
}
```
