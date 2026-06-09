
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:       
                
        def ksum(nums, target, k, start):
            res = []
            l = len(nums)
            if start>l-1:
                return res
            if k==2:
                left = start
                right = l-1
                while left<right:
                    sums = nums[left]+nums[right]
                    if sums==target:
                        res.append([nums[left], nums[right]])
                        left += 1
                        while left<right and nums[left]==nums[left-1]:
                            left += 1
                        right -= 1
                        while left<right and nums[right]==nums[right+1]:
                            right -= 1
                    elif sums < target:
                        left += 1
                    elif sums > target:
                        right -= 1
                print(res)
                return res

            elif k>2:
                for i in range(start, l-k+1):
                    if i>start:
                        if nums[i]==nums[i-1]:
                            continue
                    target_temp = target-nums[i]
                    temp = ksum(nums, target_temp, k-1, i+1)
                    for t in temp:
                        t.insert(0, nums[i])
                        res.append(t)
                return res
            return res    
        
        nums.sort()
        return ksum(nums, target, 4, 0)
                