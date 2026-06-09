### 解题思路
i指向起始位置
j指向末尾位置
i和j相遇循环结束
以下为四种情况及对应做法：
 偶   奇  交换两个元素，i+1，j-1
 奇   偶  i+1,j-1
 偶   偶  j-1
 奇   奇  i+1
看后三种情况能够发现，只要j指向的元素为偶数，则执行j-1，同理，只要i指向的元素为奇数，则执行i+1
### 代码
```
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        i=0
        j=len(nums)-1
        while (i<j):
            if nums[i]%2==0 and nums[j]%2!=0:
                nums[i],nums[j]=nums[j],nums[i]
                i+=1
                j-=1
            if nums[j]%2==0:
                j-=1
            if nums[i]%2!=0:
                i+=1
    return nums

```

