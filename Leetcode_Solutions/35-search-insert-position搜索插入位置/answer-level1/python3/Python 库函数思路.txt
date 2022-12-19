## 思路1：

1、因为有大前提，给定的数组是排序的，所以，直接遍历数组

2、当当前位置的元素不小于 `target` 时，即表示：
  * 要么，当前位置元素 == `target`，返回下标
  * 要么，当前位置元素 > `target`，因为数组是有序的，所以，前一个元素一定小于 `target`，所以，要在此位置插入 `target`，返回下标

3、有一种特殊情况，就是遍历完了仍没有找到不小于 `target` 的元素，那表示该元素要插在最末的位置，特殊处理一下，返回最末位置，即 `i+1`，又即 `len(nums)`

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for i in range(len(nums)):
            if nums[i] >= target:
                return i
        # return len(nums)
        return i + 1
```

## 思路2：

主要是使用库函数，自己写代码的话，这个思路代码量会比较大

1、将 `target` 插入到数组中，同时，做一下排序

2、这样，得到一个一定包含 `target` 的有序的新数组

3、`target` 目前所在的位置，即是 `target` 对应元素的 `原始位置` 或者 `插入位置`

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        nums.append(target)
        nums.sort()
        return nums.index(target)
```