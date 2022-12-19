### 解题思路
之前用遍历所有的hashmap，复杂度O(n^2)，重复走了很多。
因为从a出发走一个闭环出来了，下一次可能从这个闭环的另一个起点b出发再走闭环。

关键点：闭环！走过的不再走！
走过的填 -1，在剩余里面走。

反证：如果闭环外有一个元素，会与原闭环形成新的闭环。
假设元素a指向原闭环中元素b，则由原闭环可知无元素指向a，故a无法与原闭环形成新的闭环。
（不知道对不对）

### 代码

```python3
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        tmp = [0] * len(nums)
        max = 0
        for i in range(len(nums)):
            cnt = 0
            while True:
                if tmp[nums[i]] == 0:
                    cnt += 1
                    tmp[nums[i]] = -1
                    i = nums[i]
                else:
                    max = max if max > cnt else cnt
                    break
        return max

            

```