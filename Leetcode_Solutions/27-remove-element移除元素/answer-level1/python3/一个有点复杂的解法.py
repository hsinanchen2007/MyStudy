### 解题思路
总体思想：将尾部与val不同的值填入头部与val相等的位置
实现：首先从尾部倒着找出第一个与val不同的值，如果找不到说明就是没有返回0，然后从头开始遍历数组，如果遇到与val相等且头尾不相等的就将尾部的值赋给该处然后重新找一个尾部的值，如果此时头尾位置相同说明结束返回长度，位置+1，否则继续循环 然后如果头尾相等就直接返回长度
### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        l = len(nums)
        temp = l - 1
        while  temp >= 0 and nums[temp] == val :
            temp -= 1
        
        if temp == -1:
            return 0
        
        for i in range(l):
            if nums[i] == val and i != temp:
                nums[i] = nums[temp]
                temp -= 1
                while nums[temp] == val and temp > i:
                    temp -= 1
                if temp == i:
                    return i+1
            elif i == temp:
                return i+1
                
```