这道题其实挺简单的。我一共写了三个版本代码，都是逐步优化的。
版本一：找出所有符合条件的长和宽，存入一个列表中，然后再次遍历，找出差最小的那一对，执行的时间比较长，72ms
#   class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        res=[]
        for i in range(1,area+1):
            if i*i<=area and area%i==0:
                res.append([area//i,i])
            if i*i>area:
                break
        return min(res,key=lambda x:x[0]-x[1])

版本二：将上方的for循环改成了while循环，主思路还是一样的，但是减少了i*i的比较次数，运行时长为48ms
# class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        res=[]
        i=1
        while i*i<=area:
            if area%i==0:
                res.append([area//i,i])
            i+=1
        return min(res,key=lambda x:x[0]-x[1])

版本三：不再将所有的长和宽存入到列表中，而是借助长和宽的最小值——当找到符合的长和宽时，求差，如果差比当前m的值要小，则更新m和res的值，这个版本省掉了min函数的计算时间，运行时长为40ms
# class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        res=[]
        i=1
        while i*i<=area:
            if area%i==0:
                res.append([area//i,i])
            i+=1
        return min(res,key=lambda x:x[0]-x[1])