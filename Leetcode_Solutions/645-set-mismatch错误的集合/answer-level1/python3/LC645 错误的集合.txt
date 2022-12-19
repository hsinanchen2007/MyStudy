```
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        '''
        寻找重复元素：
        1、重复的数据可以使用位运算来寻找，或者由于数组的长度最高只有10000，所以只要遍历一次就知道哪个数字是重复的
        2、还可以使用sum(nums) - sum(set(nums))可以找出重复元素
        寻找缺失元素：
        1、根据nums的长度n可以计算出如果没有数据错误时的数组之和为n*(n+1)/2
        2、此时计算数据错误后的数组，则可以知道缺失的数据和重复的数据之间的关系
        '''
        numsum = sum(nums)
        dup_num = numsum - sum(list(set(nums))) # 寻找重复数字
        n = len(nums)
        sum_n = n*(n+1)//2
        drop_num = sum_n - numsum + dup_num # 计算缺失数字
        return [dup_num,drop_num]
        
```