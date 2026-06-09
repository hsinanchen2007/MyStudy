class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        try:
            while True:
                nums.remove(val)
        finally:
            return len(nums)


这个方法也可以啊