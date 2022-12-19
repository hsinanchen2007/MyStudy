``` python []
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        out_list = [] #输出列表
        length = len(nums)
        def backtrace(nums=nums,start=0,tmp=[]):
            '''
            回溯函数
            :param nums:每次需要添加的后续列表 
            :param start: 标识位 条件合适就终止回溯且向out_list中添加结果
            :param tmp:  存储当前的计算结果
            :return: 
            '''
            if start == length:
                out_list.append(tmp)
                return
            for i in range(len(nums)):
                backtrace(nums[:i]+nums[i+1:],start+1,tmp+[nums[i]]) # 1除了nums[i]本身之外的列表作为下次迭代列表 2标识位加1 3 tmp累计
        backtrace()
        return out_list
```