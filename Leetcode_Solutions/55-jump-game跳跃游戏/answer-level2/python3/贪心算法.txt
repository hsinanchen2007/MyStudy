```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        self.flag=['u']*len(nums)
        if len(nums)<=1:
            return True
        nums_length=len(nums)
        self.flag[nums_length-1]="g"
        j=nums_length-1
        for i in range(nums_length-2,-1,-1):
            if i+nums[i]>=j and self.flag!="b":
                self.flag[i]="g"
                j=i
            else:
                self.flag[i]="b"
            
        if self.flag[i]=="g":
            return True
        else:
            return False
```

先创建一个和nums长度相等的list，每个nums中的数字在list中有一个对应的字符表示能否跳到下一个good节点

首先nums【nums_length-1】 =“g”，j=nums_length-1，j表示从左向右第一个g节点

然后从右向左遍历 如果 i+nums【i】>j 就把list[i]='g'，然后j=i

最后如果list【0】 是g 就返回True 不然就返回False