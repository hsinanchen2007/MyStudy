### 解题思路
### 1. 把原表按其最大值处一分为二，使两个子表都按最大值在最右侧。
例如，原表是[0,1,0,2,1,0,1,3,2,1,2,1]，切分后part1=[0,1,0,2,1,0,1,3],part2=[1,2,1,2,3]
### 2. 对两个子表执行同一策略：
1）higher标记为前高,初始为part[0];
2)higherIdx标记为前高所在索引，初始为0,；
3）从表头向后找，每找到一个比higher相等或大的位置时，就停下来计算当前所接到雨水数量：
higher*(i-higherIdx-1)-sum(part[higherIdx+1:i])
计算后，重置higher，higherIdx标记为当前;
4）走完for循环，也就完成了所有计算。
时间复杂度O(n)

### 代码
##python3
```
class Solution:
    def trap(self, lis: List[int]) -> int:
        if lis==[]:return 0
        #find max value and cut into two parts 
        highest=0
        for i in range(len(lis)):
            highest=i if lis[i]>lis[highest] else highest
        part1=lis[0:highest+1]
        part2=lis[highest:][::-1]
        return self.solve(part1)+self.solve(part2)
    def solve(self,part):
        if len(part)==1:return 0
        higher,higherIdx,ans=part[0],0,0
        for i in range(1,len(part)):
            if part[i]>=higher:
                ans+=higher*(i-higherIdx-1)-sum(part[higherIdx+1:i])
                higher,higherIdx=part[i],i
        return ans
```
