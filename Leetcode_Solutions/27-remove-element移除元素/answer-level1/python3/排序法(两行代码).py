class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums.sort(key=lambda x:x==val)
        return len(nums)-nums.count(val)