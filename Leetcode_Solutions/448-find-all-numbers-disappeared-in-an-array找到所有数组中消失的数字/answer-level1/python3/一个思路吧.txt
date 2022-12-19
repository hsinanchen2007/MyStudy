### 解题思路
简单问题，避开几个坑和满足题目要求即可。
1.除入参提供数组外，还可以申请一个数组作为返回数组；
2.入参数组存在重复元素 -》 降低复杂度需要去重 -》 去重最方便可以考虑集合
3.总体数组 -》 list（range(1, len(nums) + 1, 1)）
4.集合求差集即可 S(sum) - S(nums) = S(miss)
5.差集转回list
6.地铁上手写的，比较粗糙，有些步骤可以合并到一起执行。

### 代码

```python3
class Solution:
    def findDisappearedNumbers(self, nums: list) -> list:
        max_num = len(nums)
        nums = set(nums)
        return_nums = set(list(range(1, max_num+1, 1)))

        return_nums = return_nums.difference(nums)

        return list(return_nums)
```