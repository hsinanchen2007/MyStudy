时间复杂度为O(n)
空间复杂度为O(1)
除原数组外只有变量count，temp和i
i为数组的索引，随循环递增，每次循环时如果nums[i]与前一次temp记录下的值相同便使count的值+1
如果count的值达到2说明出现了第三个相同的数字，将其pop并给count-1，在这种情况下因为pop了一个数字，所以list缩短了，不必增加i的值，也因此不使用for循环而使用while循环。
如果出现了字符与之前temp记录的不等的情况，说明出现了新数字，对之前数字的重复项删除已经完成，将count归零，更新temp，继续循环。
while 循环的次数为 nums删除后长度 + 删除数量 = nums原长

代码如下：


```python []
class Solution:
    def removeDuplicates(self, nums) -> int:
        count = 0
        temp = -111
        #poplist = []
        i = 0
        while i < len(nums):
            if nums[i] == temp:
                count += 1
                if count >= 2:
                    nums.pop(i)
                    count -= 1
                #i -= 1
                else :
                    i += 1                   

            else :
                count =0
                temp = nums[i]
                i += 1
                
```
