### 解题思路
时间复杂度O(n)
空间复杂度O(1)

解题的方法我想到两个：
1. 将需要移动到头部的元素取出，将其他元素后移，将移动的元素放到前面    
由于python支持insert和pop操作，也就是python的array不是一个原始的数组实现，所以操作起来就很简单了。

```
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        解决思路
        1. 将需要移动到头部的元素取出，将其他元素后移，将移动的元素放到前面        
        """
        item = 0
        for i in range(k):
            item = nums.pop()
            nums.insert(0, item)
        return nums[:k]
```

第二种办法是通用的
2. 使用反转来实现    
    1.想整体反转，这样所有数据就倒了
    2.再把0-k部分反转
    3.把k-end部分反转
    4.对于旋转的次数比数组元素大的情况，可以理解为把所有元素旋转1遍到多遍后（也就是不改变元素原来的位置），最后执行一遍k - length的操作
就是先将数组整体翻转，这样[1,2,3,4]就变成[4,3,2,1]， 如果k=2，这个时候需要放到数组前面的两个元素已经在头部了，这个时候在对数组进行进步交换位置，交换后的结果[3,4,1,2]就是想要的答案了。
            

### 代码

```python
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        解决思路
        1. 将需要移动到头部的元素取出，将其他元素后移，将移动的元素放到前面    
        2. 使用反转来实现    
            1.想整体反转，这样所有数据就倒了
            2.再把0-k部分反转
            3.把k-end部分反转
        """
        length = len(nums)
        if k > length:
            k = k - length
        nums.reverse()
        nums = self.reverse(nums, 0, k - 1)
        nums = self.reverse(nums, k, length - 1)
        return nums
    
        
    def reverse(self, nums, start, end):
        while True:
            if start >= end:
                break

            temp = nums[start]
            nums[start] = nums[end]
            nums[end] = temp
            start += 1
            end -= 1
        return nums
```