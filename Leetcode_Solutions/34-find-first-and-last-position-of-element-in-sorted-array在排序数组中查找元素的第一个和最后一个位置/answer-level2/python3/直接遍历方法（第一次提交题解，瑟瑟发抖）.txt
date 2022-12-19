方法一： 
先判断列表中是否存在target

存在则进行遍历，遍历过程中，将获取到了下标存入一个列表，当前大于target直接跳出，最后取下标列表的第一个和最后一个

不存在则直接返回[-1,-1]

```python []
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        res = []
        result = []
        
        if target in nums:
            for i in range(len(nums)):
                if nums[i]==target:
                    res.append(i)
                if nums[i]>target:
                    break

            result = [res[0],res[-1]]      
        else:
            result = [-1,-1]
            
        return result
```

方法二：
使用index()函数,index()函数返回子字符串在原字符串中开始的索引值
这里先对正序的nums使用index，获取第一个位置，再对逆序的nums使用index获取最后一个位置，不过要注意逆序获取的index要转化一下，因为逆序遍历时，index也是逆序的。

```python []
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        res = []
        if target in nums:
            idxs = nums.index(target)
            idxe = nums[::-1].index(target)
            res = [idxs, len(nums)-idxe-1]
        else:
            res = [-1, -1]

        return res
```
