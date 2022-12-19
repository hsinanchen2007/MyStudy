## 题意解读

划一下题目的重点：

- 原地移除
- 不要使用额外的数组空间
- 不需要考虑数组中超出新长度后面的元素

题目要求我们原地删除所有等于 `val` 的元素，不能使用额外空间，且**不用考虑删除后超出新数组长度后面的元素**。

也就是说，如果原数组 `nums` 长度为 `x`，要删除的 `val` 元素个数为 `y`，那么我们只要**把这 `n` 个要删除的元素所在位置用其他有效元素覆盖掉**，然后返回最终的数组长度 `x - y`。

**题目并非让我们真的删除数组的元素，而是要改写相关元素的值。**

## 思路阐述

那么要如何进行元素的改写呢？

既然要让 `val` 元素都堆在数组尾部，那么我们就派出一个开拓者探路，**只要遇到非 `val` 元素，就把它覆盖到前面来**。

因此，我们可以定义两个指针：

- 快指针 `j`：用于寻找非 `val` 元素
- 慢指针 `i`：当 `j` 找到非 `val` 元素时，就被非 `val` 元素覆盖

## 图解思路

以题中的 `nums = [3,2,2,3], val = 3` 为例。

开始时 `i` 和 `j` 都指向下标 0 位置：

![初始化时，i = 0, j = 0](https://pic.leetcode-cn.com/0e8edb7e17c452afd8d4e432627089e315165273d2ac5ffbce23e0c2d48a43f6-file_1574392293888)

此时 `j` 指向的元素为 `val`，所以把 `j` 右移动 1 位：

![把快指针 j 右移一位](https://pic.leetcode-cn.com/ea4be3c31f229ab908a94414691caa79a28eb69163f08689fb3f5560cfc3c2f6-file_1574392293880)

此时，开拓者 `j` 找到了一个非 `val` 元素，那么就赋值给 `i` 吧：

![赋值得到新序列](https://pic.leetcode-cn.com/c150b3af2c14edb12b94a8ae1346321cba335c5e6bd9bf0693192bfdc452afc2-file_1574392293886)

赋值以后，我们得到了一个新的序列 `[2, 2, 2, 3]`，我们可以得知：

- `i` 指向的元素一定不是 `val`，因为它是从 `j` 指向的元素赋值得来的，`j` 指向非 `val` 元素才会进行赋值
- `j` 指向的元素一定不是非 `val`？？？

这样一来，`i` 和 `j` 都完成了本轮使命，继续前进！

因此每次交换以后，我们都同步增长双指针，令 `i = i + 1`，`j = j + 1`：

![同步增长双指针](https://pic.leetcode-cn.com/8ae496417a84427b126e17fa40ce693720f07ddbf2e2844e2a4f07545fb907bb-file_1574392293863)

此时 `j` 又指向了一个非 `val` 元素，继续赋值：

![再一次赋值得到新序列](https://pic.leetcode-cn.com/805ca9ba3df58883cd0dc277aee7a15c3600c28738c3b09eef040d995d776134-file_1574392293893)

因为本次 `i` 与 `j` 指向元素相同，所以赋值后序列没有改变。赋值操作后，我们继续同步增长双指针：

![同步增长双指针](https://pic.leetcode-cn.com/8590aa70c1194ec15c512c3e8c8f441c457d16a5541db0df8a3dd003b035f9f0-file_1574392293894)

此时 `j` 指向了一个 `val` 元素，无法进行赋值操作，继续增长 `j`，令 `j = j + 1`：

![j 超出数组范围](https://pic.leetcode-cn.com/4dd042e166b941d01e05e9b0f12b9cfc79d9507ed74a2f2648e60c9035306bc0-file_1574392293895)

此时我们发现 `j` 超出数组范围了，循环结束。`[2, 2, 2, 3]` 即为我们最终所求结果，而红色部分即为新数组长度，长度为 `len(nums) - (j - i)`。

## 总结一下

设置双指针 `i` 和 `j`，其中，`j` 用于寻找非 `val` 元素，来覆盖 `i` 所指向的元素。 

- 初始时：设 `i = 0, j = 0`
- 遍历数组：
    - 若 `nums[j] != val`：
        - 把 `j` 的值赋给 `i`：`nums[i] = nums[j]`
        - 同步增长双指针：`i = i + 1, j = j + 1`
    - 若 `nums[j] == val`：
        - `j` 变为快指针：`j = j + 1`，寻找下一个非 `val` 元素

## 具体实现

### Python

```python
class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        length = len(nums)
        i = 0
        j = 0
        while j < length:
            if nums[j] != val:
                nums[i] = nums[j]
                i = i + 1
                j = j + 1
            else:
                j = j + 1
        res = length - (j - i)
        return res
```

### Golang

```go
func removeElement(nums []int, val int) int {
    length := len(nums)
    if length == 0 {
        return 0
    }

    i := 0
    j := 0
    for j < length {
        if nums[j] == val {
            // 去找一个不是 val 的值
            j++
        } else {
            // 赋值
            nums[i] = nums[j]
            i++ 
            j++
        }
    }

    return length - (j - i)
}
```

## 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`，没有使用到额外空间。

----

## 🐱

- 我的题解项目: [GitHub - leetcode-notebook](https://github.com/JalanJiang/leetcode-notebook)
- 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
- 如果你觉得题解写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~

![](https://pic.leetcode-cn.com/19e1d10a6d54a3e362ba5b7ad024a689720b30848e7e7b9e3ca971eae5ebd7b6-file_1574392293896)