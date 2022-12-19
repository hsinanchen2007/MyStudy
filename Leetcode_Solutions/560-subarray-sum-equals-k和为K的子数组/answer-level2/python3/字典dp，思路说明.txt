### 解题思路
要求时间复杂度O(n)，则使用循环时不能嵌套，那就考虑依次遍历。
在依次遍历的时候，假设已遍历数组为[1,2,3,4,5]，k=9，显然后两位符合要求。
可以看出，当符合要求时，必定是已遍历数组的后一段相加等于k，如果此时遍历到的元素和为sum，那么前半段和就是sum-k。
换个角度想，如果用此时的sum减去k，得到的值是曾经出现过的sum值，是不是就说明当前遍历的数组可以分为前一段和为sum-k的数组，再加上后一段和为k的数组了。
所以就构建一个字典来储存每一个sum，其实就是用字典进行dp

### 代码

```python3
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if not nums:
            return 0
        sum_t = 0
        count = 0
        dic = {0:1}
        for i in nums:
            sum_t += i
            if sum_t - k in dic:
                count += dic[sum_t-k]
            dic[sum_t] = dic.get(sum_t,0) + 1
        return count

```