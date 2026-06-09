

### 代码
第一个指针i用来存放，比较后发现列表中没有这个数
第二个指针j用来遍历列表
```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0  #此处相当于慢指针
        for j in range(0,len(nums)):
            if (nums[j] != val): 
                nums[i]=nums[j]  #覆盖
                i += 1
        return i 

```