思路是按顺序遍历数组，检测当前位及下一位的数字，相减即可得到状态，升还是降，并且和上一轮的状态做比较。如果状态变更了，
则答案计数加一，遍历完即可得到答案。

思路并不难，主要有些细节，容易让人忽略。大多数时间都在debug上了。在备注里会写出来。
比如最初是从无状态到有状态。
还有最初两个数字相减为零的情况。

```

class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        i=0               #记录现在在哪一位
        res=1             #记录答案的字段，因为两个数字才能成为一个状态，所以开始即为1
        m = len(nums)     
        if m<2:           #特殊情况  
            return m
        status=''         #记录上一轮及最开始的状态
        while i<m-1:
            if nums[i+1]-nums[i]>0:
                nstatus='up'        #nstatus记录本轮的状态
            elif nums[i+1]-nums[i]<0:
                nstatus='down'

            i += 1
            if status=='':            #最初无状态
                if nums[i] - nums[i-1] == 0: 相减为0则状态还为空，去下一轮
                    continue
                status = nstatus      #把本轮的状态存下，在下一轮时候做比较用  
                res+=1                #从无状态到有状态，计数加一
                continue
            if (status=='up' and nstatus=='down')or (status=='down' and nstatus=='up'): #状态变更计数加一
                res+=1

            status = nstatus              #把本轮的状态存下，在下一轮时候做比较用
        return res

```
