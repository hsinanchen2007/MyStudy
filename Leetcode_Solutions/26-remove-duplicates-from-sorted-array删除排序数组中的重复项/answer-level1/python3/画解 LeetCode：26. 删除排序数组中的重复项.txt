
### 思路

- 标签：`双指针`、`快慢指针`
- 题目告知需要原地删除，且空间复杂度为 O(1)，代表不能使用新数组。又告知可以不考虑数组中超出新长度后面的元素，那么只有两种方式，要么交换，把重复元素交换到后面，要么覆盖，找到后面不重复元素，依次覆盖前面的元素。前者实现起来复杂，后着比较简单
- 使用覆盖的方式，不真正删除元素，找到后面不重复元素，依次覆盖前面的元素。因为是排序数组，所以找到不重复元素的条件就是当前元素和上一个元素不相等。
- 转换为代码：快指针循环遍历，当前元素不等于前面元素时，覆盖慢指针指向元素，慢指针往后移动一位
- 时间复杂度：O(n)，需要遍历完数组
- 空间复杂度：O(1)，未使用额外的空间


```
上为快指针 i       ↓
            0    0    1    1    2    2    3    4 
下为慢指针 newLen  ↑
                      ↓
            0    0->1 1    1    2    2    3    4    因为 1 不等于 0
                 ↑
                           ↓
            0    1    1    1    2    2    3    4    因为 1 等于 1，所以不覆盖
                      ↑
                                ↓
            0    1    1->2 1    2    2    3    4    因为 2 不等于 1
                      ↑
                                     ↓
            0    1    2    1    2    2    3    4    因为 2 等于 2，所以不覆盖
                           ↑
                                          ↓
            0    1    2    1->3 2    2    3    4    因为 3 不等于 2
                           ↑
                                               ↓
            0    1    2    3    2->4 2    3    4    因为 4 不等于 3
                                ↑  newLen = 4+1 = 5
```


### 代码

```Python []
# Python 3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return len(nums)
        newLen = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[newLen] = nums[i]
                newLen += 1
        return newLen
```

### 画解

<![frame_00001](https://pic.leetcode-cn.com/1cc3780ebb48da12a80b6536b25cea2e843b2e2ac22f5e9743ee278722ba8cc9.jpg),![frame_00002](https://pic.leetcode-cn.com/c50f8a1ad28d877b50042b58eb365ac06b6f24b1f6554061fc290bde908f5ae6.jpg),![frame_00003](https://pic.leetcode-cn.com/d50d7d81136debd29e4a6fa64b4cab8c2a90857729ba056225f95366c36f8da4.jpg)>