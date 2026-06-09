### 解题思路
1.排序
2.分别以每个元素为最小值进行遍历
3.有两种情况，一是可以找到这样的序列，即最大值-最小值=1
  二是找不到，即后续所有元素差值大于1或者后续元素与之全部相等，即[1,1,1,1的情况，这是不符合的
4.每找到一个序列，计算长度，如果大于当前最大长度，就赋给输出变量
5.输出


### 代码

```python3
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums.sort()  #排序，便于遍历（不排序也是可以的，但是会添加很多时间复杂度）
        count=0      #输出
        for i in range(len(nums)):
            tmp=0       #当前子序列长度
            flag=False  #用于确认是否有这样的最大值，它比最小值大1，每次循环初始为否
            for j in range(i,len(nums)):
                if nums[j]-nums[i]>1:  #已经大于1了，直接跳过，i++
                    break 
                elif nums[j]==nums[i]: #遇到相等
                    tmp+=1
                else:                  #正好大1，标记设True
                    tmp+=1  
                    flag=True

            if tmp>count and flag:      #更新输出
                count=tmp
        return count

             

```