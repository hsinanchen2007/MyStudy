### 解题思路1 

第一种解法很容易想到, 就是当在nums中遍历到一个数时, 从这个数之后的数中找到target与这个数的差值即可.
#### python3实现
```
def twoSum(nums, target):
    for i in range(len(nums)):
        num2 = target - nums[i]
        if num2 in nums[i+1:]:
            # if nums.count(num2) == 1 and num2 == nums[i]:
            #     continue
            num2_index = nums.index(num2, i+1)
            num1_index = i
            return [num1_index, num2_index]
    return []
```
执行用时: `848ms`
内存消耗：`14.7 MB`

比较慢了, 只是很容易想到.

#### go语言实现
```
func twoSum(nums []int, target int) []int {
	result := make([]int, 0)
	for num1_index, num1 := range nums {
		num2 := target - num1
		for num2_index, numTemp := range nums[num1_index+1: ] {
			if num2 == numTemp {
				result = append(result, num1_index)
				result = append(result, num2_index + num1_index + 1)
				goto stop
			}
		}
	}
	stop:
		return result
}
```
执行用时: `28ms`
内存消耗： `3 MB`

### 解题思路2
第二种解法参考一些大神的解法, 在遍历nums的同时, 去字典中找这个数的差值
#### python3实现
```
def twoSum(nums, target):
    dic = {}
    for index, num in enumerate(nums):
        if dic.get(target - num) is not None:
            return [dic[target - num], index]
        dic[num] = index
```
执行用时: `64ms`
内存消耗：`15 MB`

比上一个方法要快很多

#### Go语言实现
```
func twoSum(nums []int, target int) []int {
	maps := make(map[int]int)
	result := make([]int, 0)
	for index, num := range nums {
		_, isTrue := maps[target - num]
		if isTrue {
			result = append(result, maps[target - num])
			result = append(result, index)
			break
		}
		maps[num] = index
	}
	return result
}
```
执行用时: `4ms`
内存消耗：`3.7 MB`


### 欢迎关注我的博客

[李培冠博客](https://lpgit.com/)

记录生活, 分享技术.