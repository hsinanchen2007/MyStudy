本题的解题思路很清晰，就是利用for循环遍历列表，然后将其中的值与val进行比较
之后对比较后的值进行删除
利用反向遍历防止溢出
```
python
```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        lens=int(len(nums))
        for i in range(lens-1,-1,-1):
            if nums[i]==val:
                nums.pop(i)
        return len(nums)