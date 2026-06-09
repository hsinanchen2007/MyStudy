```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        inres = []
        res = []
        hasmap = {}
        nums.sort()
        if len(nums) < 3:
            return []
        #把整个nums变成字典
        #利用字典查找时间复杂度为o(1)的性质，用于后续查找是否有等于两数之和相反数的值
        for ind,numb in enumerate(nums):
            hasmap[numb] = ind
        #i从第一位开始遍历到倒数第二位
        for i in range(len(nums) - 2):
        #如果第一个数的当前值大于0了，后面的肯定都是正数，不可能有等于0的解了
            if nums[i] > 0:
                break
            else:
        #利用已排序好的性质，去除重复解
                if i>=1 and nums[i] == nums[i-1]:
                    continue
                else:
                    for j  in range(i+1,len(nums)):
        #同上，判断条件用于去除重复解
                            if j >= i+2 and nums[j] ==nums[j-1]:
                                continue
                            else:
                                add2 = nums[i] + nums[j]
        #在字典中查找有无与前两个数的和相反的数，如果有并且下标比第二个数的下标大，说明这个数在未遍历过的后半部分，把这个解加入到最终解当中
                                if -(add2) in hasmap:
                                    temp_loc = hasmap.get(-add2)
                                    if temp_loc > j:
                                        inres = [nums[i],nums[j],-(add2)]
                                        res.append(inres)
        return res
```
