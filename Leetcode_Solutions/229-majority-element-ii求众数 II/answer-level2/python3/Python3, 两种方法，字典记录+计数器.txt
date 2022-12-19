方法1，利用字典记录每个数字出现的次数
```
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        if len(nums) < 3: #长度小于3，直接返回去重结果
            return set(nums)
        length = len(nums)//3
        res = {}
        result = []
        for i in range(len(nums)):
            if nums[i] not in res:
                res[nums[i]] = 0
            else:
                res[nums[i]] += 1
                if res[nums[i]] >= length and nums[i] not in result:
                    result.append(nums[i]) 
        return result
```

方法2，利用计数器，遍历一遍。
```
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        if len(nums) < 3:
            return set(nums)
        length = len(nums)//3
        nums = sorted(nums) #先排序，将相同数字放在一起。
        count = 1 #计数器初值为1
        tmp = nums[0] #初始值。
        for i in range(1, len(nums)):
            if nums[i] == tmp:
                count += 1
                if i != len(nums) - 1: #最后一个边界情况，不能continue了，否则会错过。
                    continue
            if count > length:
                result.append(nums[i - 1])
            count = 1 #计数器归位。
            tmp = nums[i] #记下当前值， 
        return result
```
