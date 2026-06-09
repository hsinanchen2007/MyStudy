### 解题思路

排序完把对应的分数和名次建立哈希表，把哈希表按原数组的键取出值加入结果数组。

### 代码

```golang
func findRelativeRanks(nums []int) []string {
	hash := make(map[int]string)
	res := []string{}
    tmp := []int{}
	tmp = append(tmp,nums...)
	tmp = sort(tmp)
	for i,j := range tmp {
		if i == 0 {
			hash[j] = "Gold Medal"
		} else if i == 1 {
			hash[j] = "Silver Medal"
		} else if i == 2 {
			hash[j] = "Bronze Medal"
		}else {
			hash[j] = strconv.Itoa(i + 1)
		}
	}

	for _,i := range nums {
		res = append(res,hash[i])
	}
	return res
}
func sort(a []int) []int {
	for i := 0;i < len(a);i++ {
		for j := i+1;j < len(a);j++ {
			if a[i] < a[j] {
				a[i],a[j] = a[j],a[i]
			}
		}
	}
	return a
}
```