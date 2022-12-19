
核心思想是利用两个非零计数器，两者相遇时说明移动完毕

```go
func moveZeroes(nums []int) {
	l := len(nums) //递减非零计数器
	i := 0 //递增非零计数器
	for {
		if i >= l {
			break
		}
		if nums[i] == 0 {
			l = l - 1                               //遇到一个0，减少1，最后与i比较作为结束条件
			nums = append(nums[0:i], nums[i+1:]...) //把0前后两部分合并
			nums = append(nums, 0)           //在末尾补回0
		} else {
			i = i + 1 //非0计数器自增
		}
	}
	return
}
```
![image.png](https://pic.leetcode-cn.com/2a09728440fc14935efdea182c12262aefe5c285ca118daf1c0fd6873c3d61cc-image.png)

![image.png](https://pic.leetcode-cn.com/8e5d17e94920be5e53d8c02d331a8ec7401e6da633d6aba5c15e4235355a4952-image.png)

