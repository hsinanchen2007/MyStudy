```
class Solution:
    def checkSubarraySum(self, nums: list, k: int) -> bool:
        if nums == [] or nums.__len__()<=1:
            return False
        if k == 0:
            for i in range(nums.__len__()-1):
                if nums[i] == 0 and nums[i+1]==0:
                    return True
            return False


        # dp=[0]*nums.__len__()
        pre_set = set()
        pre_set.add(nums[0])
        now = 0

        for i in range(1, nums.__len__()):
            now = nums[i] % k
            tmp_set = set()
            # judge n*k
            for j in pre_set:
                if (j + now) % k == 0:
                    return True
                tmp_set.add((j + now) % k)
            # change pre_set
            tmp_set.add(now)
            pre_set = tmp_set

        return False
```
