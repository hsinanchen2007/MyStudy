## 思路：
 - 使用两个循环固定两个数，用双指针找到满足题解的另外两个数。
## 说明：
 - 使用双指针法，解法和三数之和类似
 - 运用剪枝直接排除重复解
 - 合理移动双指针直接排除非正确解
## 重点：
  1. 怎样剪除所有重复枝，建议使用list而非set存储结果，去debug分析有哪些重复枝是没处理好的
  2. 怎样通过特定条件（一般是边界值）排除非正确解集，减少运算次数
## 代码：
```Python
from typing import List


class Solution(object):
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        length = len(nums)
        # result = set()
        result = []

        # 双指针法使用前提：排序
        nums.sort()

        for i in range(length - 3):
            # 去重（剪枝）
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            # 如果固定数与数组三最小数之和大于target, 则后续循环都是不存在解的, 从遍历中跳出
            if nums[i] + sum(nums[i + 1:i + 3 + 1]) > target:
                break
            # 如果固定数与数组三最大数之和小于taget, 则当前遍历不存在解, 进入下一个遍历
            if nums[i] + sum(nums[-1:-3 - 1:-1]) < target:
                continue

            for j in range(i + 1, length - 2):
                # 去重（剪枝）
                if j - i > 1 and nums[j] == nums[j - 1]:
                    continue
                # 如果固定数与数组两最小数之和大于target, 则后续循环都是不存在解的, 从遍历中跳出
                if nums[i] + nums[j] + sum(nums[j + 1:j + 2 + 1]) > target:
                    break
                # 如果固定数与数组两最大数之和小于target, 则当前遍历不存在解, 进入下一个遍历
                if nums[i] + nums[j] + sum(nums[-1:-2 - 1:-1]) < target:
                    continue

                # 双指针法
                left, right = j + 1, length - 1
                while left < right:
                    tmp_sum = nums[i] + nums[j] + nums[left] + nums[right]
                    # 如果当前和小于target, 收缩左边界
                    if tmp_sum < target:
                        left += 1
                    # 如果当前和大于target, 收缩左边界
                    elif tmp_sum > target:
                        right -= 1
                    # 如果值相等
                    else:
                        # 记录解
                        # result.add((nums[i], nums[j], nums[left], nums[right], ))
                        result.append([nums[i], nums[j], nums[left], nums[right]])

                        # 求得正确解后，去重（剪枝）
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        # 求得正确解后，去重（剪枝）
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1

                        # 在求得正确解，并且剪枝后，仅收缩移动一个指针，都不会是正确解；
                        # 因此应收缩移动双指针，直接排除不符合解的情况，减少运算次数
                        left += 1
                        right -= 1

        return result
```
## 备注：
 - 往后做题发现一个很不错的关于剪枝的配图说明，建议移步参考：[回溯算法 + 剪枝（Python 代码、Java 代码）](https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/)（作者：[@liweiwei1419](https://leetcode-cn.com/u/liweiwei1419)）