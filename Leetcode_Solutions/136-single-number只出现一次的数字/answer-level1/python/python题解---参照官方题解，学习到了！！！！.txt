```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #方法一
        result = []
        for i in nums:
            if i in result:
                result.remove(i)
            else:
                result.append(i)
        return result[0]
    
        #方法二 哈希表
        dic = {}
        for i in nums:
            try:
                dic.pop(i)
            except:
                dic[i] = 1
        return dic.popitem()[0]
    
        #数学方法
        return 2*sum(set(nums)) - sum(nums)
        
        #二进制的异或方法
        j = 0
        for i in nums:
            j^=i
        return j
            
    
```
