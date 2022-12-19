### 解题思路
见注释，时间击败85.38%

### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        #特殊情况处理
        size = len(nums)
        if(size <3): return None #长度<3
        if(size == 3): return sum(nums) #长度=3
        #长度>3的情况
        #1.排序
        nums.sort()
        #2.定义找到最小值到方法，会复用, 用绝对值来比较
        def finMin(allNum, tar):
            allNum.append(tar)
            allNum.sort()
            mid = allNum.index(tar)
            if (mid == 0): return allNum[1]
            elif (mid == len(allNum)-1): return allNum[-2]
            else:
                a = allNum[mid-1]
                b = allNum[mid+1]
                if(abs(a-tar)>abs(b-tar)): return b
                else: return a
        #3.使用双指针O(n^2)
        res=[]
        for i in range(0,size-2):
            L=i+1
            R=size-1
            mid = 0
            allMid = []
            dicL = False
            dicR = False
            while(L<R):
                mid=nums[i]+nums[L]+nums[R]
                allMid.append(mid)
                if(mid < target):
                    dicL=True
                    L+=1
                elif(mid > target):
                    dicR=True
                    R-=1
                else:
                    return target
            if(dicR and dicL):
                mid = finMin(allMid,target)
            res.append(mid)
        
        return finMin(res,target)
        


```