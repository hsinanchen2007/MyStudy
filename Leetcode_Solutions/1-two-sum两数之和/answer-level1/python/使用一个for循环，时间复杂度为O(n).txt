### 解题思路
需要考虑的问题：
1. 如何获得 target - num 的索引值；
2. 避免两个数的 index 相同，例如 nums = [3, 3 ,6]、target = 6 这种情况。

解决思路：
1. 获得 target - num 的索引值，可以先定义一个字典 hasmap ，在使用 for 循环遍历的时候，将 num 作为键、index 作为值，存储在 hashmap 中，然后再通过 if...in... 判断 target - num 是否在这个 hashmap 里面，通过 hashmap[target - num] 的方式获得  target - num 的索引值；
2. 按照 1 中思路，其实就已经避免了两个数的 index 相同的这种情况，因为不难发现 hashmap 中存储的key始终是数组中位于 target - num 之前的所有值。以 nums = [3, 3 ,6]、target = 6 为例：第一次循环 index = 0、num = 3 当执行到 if 语句的时候 hasmap 为空，other in hashmap 返回 False，所以 if 后面的 return 并不会执行，然后执行后面的 hashmap[num] = index ，接着执行第二次循环 index = 1、num = 3 当执行到 if 语句时，因为这时候 hashmap = {3 : 1} 所以判断成功，也就是说 hashmap 中存储的数据始终是 other 前面的所有键值对。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for index, num in enumerate(nums):
            other = target - num
            if other in hashmap:
                return [hashmap[other], index]

            hashmap[num] = index
```