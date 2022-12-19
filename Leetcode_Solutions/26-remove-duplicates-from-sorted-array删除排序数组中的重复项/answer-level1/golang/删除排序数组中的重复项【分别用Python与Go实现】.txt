### 解题思路
看了一些大佬的解题思路, 大多数都是考虑使用双指针从头到尾遍历.
这样用for循环就会衍生出一个问题: 在遍历列表/数组/切片等的过程中, 此时该列表/数组/切片等的长度会发生变化.
然后有很多大佬直接改用while循环进行解答.

其实, 我们可以换位思考一下: 正向遍历有影响, 我可以反向遍历啊. 想到这个, 题目就很好解了.

1. 从nums的最后一个开始遍历, 然后与前一个进行对比.
2. 如果相等, 则删除该位置的数.
3. 不等, 则继续往前遍历.

#### Python实现
```
def removeDuplicates(nums):
    for num_index in range(len(nums)-1, 0, -1):
        if nums[num_index] == nums[num_index-1]:
            nums.pop(num_index)
    return len(nums)
```
执行用时: `120ms`
内存消耗: `15.6MB`


#### Go实现
```
func removeDuplicates(nums []int) int {
	for i:=len(nums)-1; i>0; i-- {
		if nums[i] == nums[i-1] {
			nums = append(nums[:i], nums[i+1:]...)
		}
	}
	return len(nums)
}
```
执行用时: `64ms`
内存消耗: `7.6MB`

### 欢迎关注我的博客

[李培冠博客](https://lpgit.com/)

记录生活, 分享技术.
