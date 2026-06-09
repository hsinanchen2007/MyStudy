# 第一种map
```
func threeSum(nums []int) [][]int {
	res := [][]int{}
	counter := map[int]int{}
	for _, value := range nums {
		counter[value]++
	}

	uniqNums := []int{}
	for key := range counter {
		uniqNums = append(uniqNums, key)
	}
	sort.Ints(uniqNums)
	for i := 0; i < len(uniqNums); i++ {
		if uniqNums[i]*3 == 0 && counter[uniqNums[i]] >= 3 {
			res = append(res, []int{uniqNums[i], uniqNums[i], uniqNums[i]})
		}
		for j := i + 1; j < len(uniqNums); j++ {
			if uniqNums[i]*2+uniqNums[j] == 0 && counter[uniqNums[i]] > 1 {
				res = append(res, []int{uniqNums[i], uniqNums[i], uniqNums[j]})
			}
			if (uniqNums[j]*2+uniqNums[i] == 0) && counter[uniqNums[j]] > 1 {
				res = append(res, []int{uniqNums[i], uniqNums[j], uniqNums[j]})
			}
			c := 0 - nums[i] - nums[j]
			if c > uniqNums[j] && counter[c] > 0 {
				res = append(res, []int{uniqNums[i], uniqNums[j], c})
			}
		}
	}
	return res
}
```

# 第二种，双指针
```
func threeSum(nums []int) [][]int {
	if nums==nil||len(nums)<3{
		return nil
	}
	sort.Ints(nums)
	len:=len(nums)
	res:=[][]int{}
	for i:=0;i<len-2;i++{
		if i>0&&nums[i]==nums[i-1]{
			continue
		}
		l:=i+1
		r:=len-1
		for l<r{
			s:=nums[i]+nums[l]+nums[r]
			if s<0{
				l++
			}else if s>0{
				r--
			}else{
				res=append(res,[]int{nums[i],nums[l],nums[r]})
				for l<r&&nums[l]==nums[l+1]{
					l++
				}
				for l<r&&nums[r]==nums[r-1]{
					r--
				}
				l++
				r--
			}
		}

	}
	return res
}
```

