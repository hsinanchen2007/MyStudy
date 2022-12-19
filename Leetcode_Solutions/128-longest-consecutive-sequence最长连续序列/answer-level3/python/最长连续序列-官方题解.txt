### 解题思路
个人愚钝，未想出符合题目要求的解法，在此记录官方题解，仅作学习记录。感谢！
- 按官方的解释，相等的数字不会增长序列长度，但也不会中断序列的统计；
- 使用set集合，去除重复数字；
- 为什么要以前一个数字(num-1)是否存在为先决条件呢？可以先考虑暴力求解的情况（假设数组为：[1,3,2,8,4,5,8,9]）：
  - 寻找1的时候，可以统计到5，记录下此时的连续序列长度；然后寻找2的时候，又会统计到5；
  - 这样会多次遍历已经寻找过的数字，从而造成冗余和时间消耗
- 假如优先判断，前一个数字不存在数组中才开始遍历，也就是，访问1的时候，0不在数组中，则一步一步地进行序列遍历；
- 访问2的时候，因为1已经在数组中了，说明它不是这个最长序列的起点，那么就跳过，直到找到序列的起点1，然后才开始遍历；
- 访问3，4，5时是同样的情况；
- 访问8的时候，因为7不在数组中，所以它是新的序列的起点，那么从9开始一个个地判断；
- 这样下来，相当于while循环只会遍历每个数字一次，因此是O(N)的复杂度；
- 当数组中每个元素都是孤立的，且彼此相差大于等于2的时候，如[1,3,5,7,9], 此时每一个元素只会被最外层的循环遍历一次，无法启动内部的while循环，此时是最坏的情况，复杂度依然为O(N)；
- 当数组为有序数组，且间隔为1时，如[1,2,3,4,5]，此时内部循环while会遍历N次，外部循环则会空转N-1次；时间上则是O(N)+O(N-1),平均复杂度则为O(N)；

个人拙见，仅供参考

### 代码

```python3
class Solution:
    def longestConsecutive(self, nums):
        longest_streak = 0
        num_set = set(nums)

        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak

# 作者：LeetCode
# 链接：https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/zui-chang-lian-xu-xu-lie-by-leetcode/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```