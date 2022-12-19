执行用时:140ms,在所有Python提交中击败了34.65%的用户内存消耗:16MB,在所有Python提交中击败了6.67%的用户

    def subarraySum(self, nums, k):
      from collections import defaultdict
      pre_sum=0
      record=defaultdict(int)
      record[0]=1
      res=0
      for i in range(len(nums)):
          pre_sum+=nums[i]
          res+=record[pre_sum-k]
          record[pre_sum]+=1
      return res

而第二个解答超出了时间限制：

    def subarraySum(self, nums, k):
      pre_sum=0
      record={}
      record[0]=1
      res=0
      for i in range(len(nums)):
          pre_sum+=nums[i]
          res+=record.get(pre_sum-k,0)
          if pre_sum in record.keys():
              record[pre_sum]=record[pre_sum]+1
          else:
              record[pre_sum]=1
      return res