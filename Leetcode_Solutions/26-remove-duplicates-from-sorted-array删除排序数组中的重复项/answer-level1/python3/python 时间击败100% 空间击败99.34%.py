### 解题思路
每次向后看一位 重复的话删除当前位置的元素
当然了，很谜，按理说删除数组元素时间复杂度是O(n)，不知道为啥会超过100%。。。有大佬指点一下吗
![image.png](https://pic.leetcode-cn.com/f80057a31886ae6efd0612ebad7090d13b1a5cb6ef6b85344c343b6a3aad2394-image.png)


### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=0
        while(i<len(nums)-1):
            if(nums[i]==nums[i+1]):
                del nums[i] #删除数组元素时间复杂度是O(n) 为啥时间超过100%  双指针的时间复杂度似乎低
            else:
                i+=1
        return len(nums)
```

为啥代码显示不全。。。