### 解题思路1

因为数组是排好序的, 很容易想到用二分查找来做.

当 `nums` 里的数比目标值大时: `nums`被表示为 `nums[: midIndex]`

当 `nums` 里的数比目标值小时: `nums` 被表示为 `nums[midIndex + 1: ]`

当然, 我也不知道为啥就想到要改变 `nums` 的大小, 这似乎看起来不合适.

正常的二分查找是初始化两个指针, 一个指向左边, 一个指向右边.

但是呢, 这种方法与我的方法在 `内存消耗` 上是一样的, 但是 `执行用时` 却比我的方法长.

#### Python实现

```python
def searchInsert(nums, target):
    nums_index = 0
    while len(nums) >= 1:
        nums_len = len(nums)
        mid_index = nums_len // 2
        if nums[mid_index] == target:
            nums_index += mid_index
            return nums_index
        elif nums[mid_index] > target:
            nums = nums[:mid_index]
            if len(nums) == 0:
                return nums_index
        else:
            nums_index += (len(nums[:mid_index + 1]))
            nums = nums[mid_index + 1:]
            if len(nums) == 0:
                return nums_index
```

执行用时: `60ms`

内存消耗: `14.1MB`

#### Go实现

```go
func searchInsert(nums []int, target int) int {
	nums_index := 0
	for ;len(nums)>=1;{
		nums_len := len(nums)
		midIndex := nums_len / 2
		if nums[midIndex] == target {
			nums_index += midIndex
			return nums_index
		}else if nums[midIndex] > target {
			nums = nums[: midIndex]
		}else {
			nums_index += len(nums[:midIndex+1])
			nums = nums[midIndex+1:]
		}
	}
	return nums_index
}
```

执行用时: `4ms`

内存消耗: `3.1MB`

### 解题思路2

另外, 直接遍历整个数组也是很简单粗暴的做法.

#### Python实现

既然都直接遍历整个数组了, 还是用的Python, 直接 `return` 得了.

```python
def searchInsert(nums, target):
    return len([num_index for num_index in range(len(nums)) if nums[num_index] < target])
```

执行用时: `72ms`

内存消耗: `14.3MB`

#### Go实现

```go
func searchInsert(nums []int, target int) int{
	index := 0
	for _, num := range(nums) {
		if num < target {
			index += 1
		}
	}
	return index
}
```

执行用时: `4ms`

内存消耗: `3.1MB`

和二分查找一样? 太失败了...

### 欢迎关注我的博客

[李培冠博客](https://lpgit.com/)

记录生活, 分享技术.