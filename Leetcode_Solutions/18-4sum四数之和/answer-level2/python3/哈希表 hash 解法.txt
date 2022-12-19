 
`

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        if len(nums) <= 3:
            return []
        
        memo = dict()
        result_list = []
        nums.sort()
        
        for i in range(len(nums)-1):
            
            for j in range(i+1, len(nums)):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                
                this_sum = nums[i] + nums[j]
                expect = target - this_sum 
                
                if expect in memo:
                    
                    for tup in memo[expect]: # a list
                        if tup[2] < i: # old i < old j < i < j
                            temp = [tup[0], tup[1], nums[i], nums[j]]
                            if temp not in result_list:
                                result_list.append(temp)

                # insert. 
                if this_sum not in memo:
                    memo[this_sum] = [(nums[i], nums[j], j)]
                    
                else:
                    memo[this_sum].append((nums[i],nums[j], j))
                    
        return result_list 


`

