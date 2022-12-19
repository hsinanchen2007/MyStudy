### 解题思路

这个题与第26题 删除排序数组中的重复项 思路一样, 对 `nums` 进行**倒序遍历**, 遇到与 `val` 相同的数值进行删除即可.

#### Python实现

```
def removeElement(nums, val):
    for i in range(len(nums)-1, -1, -1):
        if nums[i] == val:
            nums.pop(i)
    return len(nums)
```
执行用时: `44ms`
内存消耗: `13.9MB`

#### Go实现

```
func removeElement(nums []int, val int) int {
	for i := len(nums)-1; i>-1; i-- {
		if nums[i] == val {
			nums = append(nums[:i], nums[i+1:]...)
		}
	}
	return len(nums)
}
```
执行用时: `0ms`
内存消耗: `2.4MB`

> 用Go实现的应该都能达到 0ms 吧.

### 欢迎关注我的博客

[李培冠博客](https://lpgit.com/)

记录生活, 分享技术.
