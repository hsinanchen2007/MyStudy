思路是这样的：
1、从末位到首位观察，观察倒序到哪一位为止；
如42357432，我们不可能通过调整呈倒序的数位来提高该数的数值。即，我们不可能改变7432这四位的顺序来提高使这个数字变大；于是，我们发现倒序到7这一位为止，则令变量 down = “7前面的一位，即5，对应的索引（即5的索引是nums[3]）”，则down=3。

2、借助nums[down]=5来改变整个数字的值。寻找倒序的数当中，即7432中超过5的数中的最小值，即为7。令这个数的索引为onebiggerdown。即onebiggerdown=4。调换onebiggerdown和down所对应的数字的位置（但是down和onebiggerdown本身的值不变）。再令down后面的所有数字reverse。即得到最后的结果。

```
class Solution(object):
    def nextPermutation(self,nums):
        lenth=len(nums)
        a=0
        reversubsequence=1
        down=0
        onebiggerthandown=0
        for i in range(lenth-1,0,-1):
            if nums[i]<=nums[i-1]:
                continue
            reversubsequence=0
            down=i-1
            for j in range(lenth-1,down,-1):
                if nums[j]<=nums[down]: 
                    continue
                onebiggerthandown=j
                break
            nums[onebiggerthandown],nums[down]=nums[down],nums[onebiggerthandown]
            nums[down+1:lenth]=nums[lenth-1:down:-1]
            break
        if reversubsequence==1:
            nums.reverse()
            return nums
        else:
            return nums```

