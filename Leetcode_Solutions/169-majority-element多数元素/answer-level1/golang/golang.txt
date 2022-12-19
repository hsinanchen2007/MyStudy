golang 摩尔投票算法

gitbub: https://github.com/Crownt/leetcode

```
// Boyer-Moore投票算法，如果我们把 "majorityElement" 记为+1，把其他数记为-1，
// 将它们全部加起来，显然和大于0，从结果本身我们可以看出 "majorityElement" 比其他数多
// 时间复杂度：O(n)  空间复杂度：O(1)

func majorityElement(nums []int) int {
	majority := nums[0]
	cnt := 0
	for _, num := range nums {
		if num == majority {
			cnt++
		}else {
			cnt--;
			if cnt==0 {
				majority = num
				cnt = 1
			}
		}
	}

	return majority
}
```
