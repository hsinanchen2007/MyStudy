### 解题思路
首先，利用`sorted`函数创建一个已经排好序的副本，此时的列表是有顺序的。然后我们从`sorted_nums[0]`开始查找，并且跳过所有重复的元素。比如一个列表`[1,1,1,1,2,2,2,3,]`，那么我查找第一个元素的时候，程序反馈说在这个列表中有4个这样的元素，而此时列表已经是有序的了，那么直接让程序跳到第5个元素继续就行了。这种情况在应对某些极端例子的时候还是挺有效的。当然也是一个十分简单并且容易想到的解法。这种方法最终用时76ms，不算很快，但是不至于超时。

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        x = 0
        sorted_nums = sorted(nums)
        i = 0
        while i < len(sorted_nums):
            if sorted_nums.count(sorted_nums[i]) > x:
                x = sorted_nums.count(sorted_nums[i])
                res = sorted_nums[i]
            i += sorted_nums.count(sorted_nums[i])
        return res

```