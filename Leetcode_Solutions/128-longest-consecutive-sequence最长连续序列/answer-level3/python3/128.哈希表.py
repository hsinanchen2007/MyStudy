哈希表查询一个数的时间复杂度是O（1）。这题想到哈希表其实也并不难。题目要求时间复杂度O（n）,因此暴力和排序都是不可取的。

## 算法思想
1. 对每个元素进行判断，是不是序列的开始。即nums[i]-1是否在哈希表中（O（1）的时间）。
2. 如果nums[i]-1在set中，说明不是序列的开始，则跳过。
3. 如果nums[i]-1不在，说明nums[i]是序列的开始。判断nums[i]+1是否在哈希集合中，直到没有出现在集合中，判断此时的长度cur_len。和最长序列长度进行比较，max_len = max(curr_len,max_len)。


```python []
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        s = set(nums)
        maxlen = 0
        for num in s:
            cur_len = 1
            if num-1 in s:
                continue
            while num+1 in s:
                num = num+1
                cur_len+=1
            maxlen = max(maxlen,cur_len)
        return maxlen
```
乍一看上去像是O（n^2）的复杂度。对于某个元素nums[i]，如果不是序列开始，直接跳过了,只会花费O（1）的时间。更进一步，两种极端的情况：
1. 整个nums,最长连续子序列长度就是1。比如[1,3,5,7,9,21,32,53]等，不存在连续的，那每个元素都花费O（1）,所以总的时间复杂度为O（n）。
2. 整个nums,最长连续子序列长度就是数组长度。比如[2,1,3,5,4,7,6]。对于2,3,5,4,7,6这几个元素，只会使用O（1）的查询时间，对于1这个元素（序列的开始）会执行代码块中的while语句，使用O（n）的时间复杂度。整体的时间复杂度为O(1)*n+O(n)*1=O(2n)的时间复杂度。**此时的时间复杂度是最高的。**

综上，时间复杂度在O（n）~O（2n)直接，也就是O（n）符合题目要求了。