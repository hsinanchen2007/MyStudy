### 解题思路

两个哈希表，一个存放去重后的数组元素，并添加到tmp数组中（已去重），另一个存放重复元素，然后遍历tmp数组，若当前元素加上K存在于第一个hash表中，则存在一个数对，res++，最后返回res。

当K为0时为特殊情况，只需要统计数组中有几个数字重复出现即可。

### 代码

```golang
func findPairs(nums []int, k int) int {
    if k < 0 {
        return 0
    }
	hash := make(map[int]int)
	same := make(map[int]int)
	tmp := []int{}
	res1 := 0
	res2 := 0
	for _,i := range nums {
		if _,ok := hash[i]; !ok {
			hash[i] = 1
			tmp = append(tmp,i)
		}else if _,ok := same[i]; !ok {
			same[i] = 1
			res1++
		}
	}
	for _,j := range tmp {
		if _,ok := hash[j + k];ok {
			res2++
		}
	}
	if k == 0 {
		return res1
	}else {
		return res2
	}
}
```