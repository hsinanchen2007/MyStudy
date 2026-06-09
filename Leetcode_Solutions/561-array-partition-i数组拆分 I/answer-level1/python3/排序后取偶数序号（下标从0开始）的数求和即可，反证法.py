可以用反证法简单证明一下这个方法是成立的。设现在取的集合为{a[2i]}，a为排序后的数组，假如a[2i+1]>a[2i]可以替换掉a[2i]使得求和更大，那么在a[2i+1:2n]这2n-2i-2个元素中，我们将会取出n-i个元素。根据题意，每个最终求和的元素必须分别找一个比它大的元素进行配对。但2n-2i-2个元素中除去n-i个元素后，只剩n-i-2个元素，不可能完成配对，产生矛盾。证毕

```
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        sum_=0
        for i in range(0,len(nums),2):
            sum_+=nums[i]
        return sum_
```
