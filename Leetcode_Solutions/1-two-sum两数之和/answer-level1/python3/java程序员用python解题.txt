class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for x in range(0,len(nums)):
            if map.__contains__(nums[x]):
                return [map.get(nums[x]),x]
            map[target-nums[x]]=x;
        return None;