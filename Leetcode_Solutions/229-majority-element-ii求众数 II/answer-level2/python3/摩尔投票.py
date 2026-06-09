```
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
      '''
      思路：摩尔投票法，这题灵活些应用，首先我们先设定两个候选人位置，以及两个两个计数器。
      遍历数组，如果数在候选位置上，则对应计数器加一，如果都不在候选位置上，则两个候选的
      计数器均减一。当某个候选位计数器为零，则下一个数上位！
      
      （我们可以这么去思考摩尔投票法，我们如果不想让正确的数上位，唯一的办法就是让不是>n/3
      的数去消耗>n/3的数，因为有两个候选位，例如[1,1,1,2,3,4,5],想让2，3,4,5消耗1让其上
      不了位，但是因为有2个候选位，2,3,4,5去消耗1的时候，其实也在内部消耗，这种内部消耗使得
      最终耗不过1,1无论怎么都会成功上位。其他情况也可以这么思考）
      
      和众数的摩尔投票法不同，我们需要去验证上位的两个数是都是>n/3的，还是只有一个是>n/3的，
      验证步骤，分情况讨论。
      '''
      d = {}
      # 摩尔投票阶段
      for n in nums:
        if n in d:
          d[n] += 1
        else:
          if len(d) < 2:
            d[n] = 1
          else:
            res = []
            for temp in d.items():
              temp = list(temp)
              temp[1] -= 1
              if temp[1] != 0:
                res.append(temp)
            d = dict(res)
            
      # 验证步骤
      d_list = list(d.items())
      if len(d_list) == 2:
        count_1 = 0
        count_2 = 0
        for n in nums:
          if n == d_list[0][0]:
            count_1 += 1
          elif n == d_list[1][0]:
            count_2 += 1
        if count_1 > len(nums)//3 and count_2 > len(nums)//3:
          return [d_list[0][0],d_list[1][0]]
        elif count_1 > len(nums)//3:
          return [d_list[0][0]]
        else:
          return [d_list[1][0]]
      elif len(d_list) == 1:
        count = 0
        for n in nums:
          if d_list[0][0] == n:
            count += 1
        if count > len(nums)//3:
          return [d_list[0][0]]
        else:
          return None
      else:
        return None
```
