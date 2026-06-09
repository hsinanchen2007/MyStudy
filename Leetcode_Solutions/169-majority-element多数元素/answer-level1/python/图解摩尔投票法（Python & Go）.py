## 算法描述

摩尔投票法（*Boyer–Moore majority vote algorithm*），也被称作「多数投票法」，算法解决的问题是：**如何在任意多的候选人中（选票无序），选出获得票数最多的那个**。

算法可以分为两个阶段：

1. 对抗阶段：分属两个候选人的票数进行两两对抗抵消
2. 计数阶段：计算对抗结果中最后留下的候选人票数是否有效

这样说比较抽象，我们直接来看一道题：[LeetCode 169. 多数元素](https://leetcode-cn.com/problems/majority-element/ "LeetCode 169. 多数元素")

## 例题：多数元素

给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 `⌊ n/2 ⌋ ` 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

```
输入: [3,2,3]
输出: 3
```

示例 2:

```
输入: [2,2,1,1,1,2,2]
输出: 2
```

### 投票法思路

根据上述的算法思想，我们遍历投票数组，将**当前**票数最多的候选人与其获得的（抵消后）票数分别存储在 `major` 与 `count` 中。

当我们遍历下一个选票时，判断当前 `count` 是否为零：

- 若 `count == 0`，代表当前 `major` 空缺，直接将当前候选人赋值给 `major`，并令 `count++`
- 若 `count != 0`，代表当前 `major` 的票数未被完全抵消，因此令 `count--`，即使用当前候选人的票数抵消 `major` 的票数

### 详细图解

以 `[2,2,1,3,1,2,2]` 为例。

遍历数组第一个元素 `2` 时，因 `major` 空缺，所以赋值 `major = 2`，且票数 `count = 1`：

![](https://pic.leetcode-cn.com/0dccd0d907bcc4389cd63fd6ea4a301594d87405c332c28a14c3d0e6e4942854-file_1584432906657)

我们发现第二个元素依旧是「候选人」`2`，与 `major` 相同，因此将票数加一：

![](https://pic.leetcode-cn.com/dfd4c082d07a1ea48e666c97b955aeff059cd33c43e8766b82eb26f9b1fc281f-file_1584432906668)

第三个元素是 `1`，与 `major` 不同，因此发生「对抗」，将当前 `major` 的票数冲抵掉 1 票：

![](https://pic.leetcode-cn.com/a4ded5266046f251910f0c4869a31167c895f2ccf91ef841e391aafdfce8e396-file_1584432906666)

第四个元素是 `3`，又与 `major` 不同，因此产生「对抗」，票数继续冲抵：

![](https://pic.leetcode-cn.com/0b63277a024aceb521b2bcdbee18b9ad757c789ba63bfb12a701317e267b6df6-file_1584432906669)

当遍历到第五个元素 `1` 时，我们发现当前 `count` 已经归 `0`，说明 `major` 位置空缺，因此我们令 `major = 1`，且 `count = 1`：

![](https://pic.leetcode-cn.com/240ceb555679e967604f02c60e72c70a4125cc171b7edb94a9937121fa600102-file_1584432906670)

第六个元素是 `2`，与 `major` 不同，因此进行票数抵消，元素 `1` 刚上位又要下台了：

![](https://pic.leetcode-cn.com/4b5510c1d2d8b8a5369e4ce97d641a4999cd193c96fd676209df337d86c27eeb-file_1584432906671)

此时 `count` 又归零了，因此当遍历到最后一个元素 `2` 时，令 `major = 2`，票数 `count = 1`：

![](https://pic.leetcode-cn.com/d3e16c86329599c9d212dbfccf986f663e0de9dc2a0fe7327baa76cfc25029e6-file_1584432906673)

至此遍历结束，求出的多数元素为元素 `2`。

### 具体实现

```python []
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        major = 0
        count = 0
        
        for n in nums:
            if count == 0:
                major = n
            if n == major:
                count = count + 1
            else:
                count = count - 1

        return major
```
```go []
func majorityElement(nums []int) int {
    major := 0
    count := 0

    for _, num := range nums {
        if count == 0 {
            major = num
        }
        if major == num {
            count += 1
        } else {
            count -= 1
        }
    }
    
    return major
}
```

### 复杂度

- 时间复杂度：$O(n)$，仅遍历一次数组
- 空间复杂度：$O(1)$，没有使用额外空间

## 总结

题目中给出条件「给定的数组总是存在多数元素」，因此没有涉及「计数阶段」，仅在「对抗阶段」对候选人票数进行了「对抗抵消」。如果想加深理解，推荐大家可以再做做这道题：[LeetCode 229. 求众数 II](https://leetcode-cn.com/problems/majority-element-ii/ "LeetCode 229. 求众数 II")。

----

## 🐱

- 我的题解项目：[点击前往](https://github.com/JalanJiang/leetcode-notebook)
- 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
- 如果你觉得文章写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~

![](https://pic.leetcode-cn.com/ae3bd6547d0aa946436706f70167767b1cdee1429535ad0d6535d46c684365ae-file_1576126672599)