### 解题思路
与<26删除排序数组中的重复元素>，<27移除元素>相似，这里使用**双指针**后，需要使用**计数器**来计算元素出现的次数。
R指针依次右移，若出现重复元素，记录出现的次数(count)；若count>2,则说明遇到多余的重复项，在此情况下，向后移动R指针寻找不重复元素；若count<=2,将不重复的元素移到L的位置，再L+=1。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #双指针+计数器
        count=1#元素出现的次数
        n=len(nums)
        L,R=1,1
        while R<n:
            if nums[R]==nums[R-1]:#出现重复元素，记录出现的次数
                count+=1
            else:count=1#若不是重复元素，重置计数器
            if count<=2:#若只有2个及以下的重复元素，移动L
                nums[L]=nums[R]
                L+=1
            R+=1
        return L
        
```