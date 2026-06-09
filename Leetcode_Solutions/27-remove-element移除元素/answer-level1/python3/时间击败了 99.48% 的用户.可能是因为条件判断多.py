### 解题思路
太难了，写了半天

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if len(nums)==0:
            return 0
        if len(nums)==1 :
            if nums[0]==val:
                return 0
            else:
                return 1
        p1=0
        p2=0
        while p2!=len(nums):
            if nums[p2]!=val:
                nums[p1]=nums[p2]
                # nums[p2]=val

                p1+=1
                p2+=1
            else:
                p2+=1

        return p1

```