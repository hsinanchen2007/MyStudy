
解题思路：
题目给定的是有序数组，使用for循环遍历每个元素，如果碰到相邻（有序所以只需判断相邻）的相等元素时，则查询的index不增加，删除列表中的一个元素，原长度减一。若不等，则查询的index增1直到等于原长为止。

```python []
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        pre_len = len(nums)
        index = 1
        while (index < pre_len):
            if (nums[index -1 ] == nums[index]):
                nums.pop(index)
                pre_len = pre_len - 1
            else:
                index = index + 1
        return index
```

```
Accepted
161/161 cases passed (108 ms)
Your runtime beats 60.51 % of python3 submissions
Your memory usage beats 99.15 % of python3 submissions (14.4 MB)
```

后来我提交后，查看了一下大神们的解法，然后尝试了一下双指针，发现Python3的解法中好像必须删除原来的数据，否则会判错。不知道大家是不是也这样。


