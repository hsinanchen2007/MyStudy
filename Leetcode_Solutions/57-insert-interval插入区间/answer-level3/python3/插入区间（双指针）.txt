这是我目前写过最长的方案（希望你有心理准备，写的不是很好，直接看代码更好，注释的部分也是可以运行的。。。。。。。）

intervals和newInterval是排序好的list，如果intervals为空，return intervals+[newInterval]

intervals不为空，利用双指针去寻找newInterval两个元素在intervals中的的区间位置（就是寻找他们是否在interval中某一完整的区间内，并记录位置，找不到就为-1）

if temp1==-1 and temp2==-1:

考虑极端情况（直接在左边或者右边添加），没有极端情况，用双指针继续发现新区间的起始位置和结束位置，对双指针判断，返回相应的结果。

elif temp1!=-1 and temp2==-1:

newInterval右边元素在intervals的某一区间，左边元素没有合适的区间，用单指针寻找左边的切入点，返回相应的结果。

elif temp1!=-1 and temp2==-1:

newInterval左边元素在intervals的某一区间，右边元素没有合适的区间，用但指针寻找右边的切入点，返回相应的结果

else：

temp1 和temp2 都不等于-1，

返回return intervals[:temp1]+[[intervals[temp1][0],intervals[temp2][1]]]+intervals[temp2+1:]




    class Solution:
        def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
            if not intervals:return intervals+[newInterval]

            temp1=temp2=-1
            for i in range(len(intervals)):
                if intervals[i][0]<=newInterval[0] and newInterval[0]<=intervals[i][1]:
                    temp1 = i
                if intervals[i][0]<=newInterval[1] and newInterval[1]<=intervals[i][1]:
                    temp2 = i
                    break
            #print(temp1,temp2)

            if temp1==-1 and temp2==-1:
                if newInterval[-1]<intervals[0][0]:
                    intervals.insert(0,newInterval)
                    return intervals
                elif newInterval[0]>intervals[-1][-1]:
                        intervals.append(newInterval)
                        return intervals
                else:
                    flag1 = flag2=-1
                    for i in range(len(intervals)): 
                        if intervals[i][1]<newInterval[0]:
                            flag1 = i
                        if intervals[i][0]>newInterval[1]:
                            flag2 = i
                            break
                    if flag1 == flag2==-1:return [newInterval]
                    if flag1 ==-1 and flag2!=-1:return [newInterval]+intervals[flag2:]
                    if flag1 !=-1 and flag2==-1:return intervals[:flag1+1]+[newInterval]
                    return intervals[:flag1+1]+[newInterval]+intervals[flag2:]
            #elif temp1==temp2:
            #  print(temp1,temp2)
            #  return intervals

            elif temp1!=-1 and temp2==-1:
                flag = -1
                for i in range(temp1+1,len(intervals)):
                #for i in range(len(intervals)):
                    if intervals[i][0]>newInterval[1]:
                        flag=i
                        break
                if flag==-1:return intervals[:temp1]+[[intervals[temp1][0],newInterval[1]]]
                return intervals[:temp1] + [[intervals[temp1][0],newInterval[1]]]+intervals[flag:]
                
                '''
                if temp1==len(intervals)-1:
                    intervals[temp1][1]=newInterval[1]
                    return intervals
                elif intervals[temp1+1][0]>newInterval[1]:
                    intervals[temp1][1]=newInterval[1]
                    return intervals
                else:
                    while intervals[temp1+1][0]<newInterval[1]:
                        intervals.pop(temp1+1)
                        if temp1==len(intervals)-1:break
                    intervals[temp1][1]=newInterval[1]
                    return intervals
                '''
                
            elif temp1 == -1 and temp2!=-1:
                flag = -1
                for i in range(temp2+1):
                #for i in range(len(intervals)):
                    if intervals[i][0]>newInterval[0]:
                        flag=i-1
                        break
                if flag==-1:return [[newInterval[0],intervals[temp2][1]]]+intervals[temp2+1:]
                return intervals[:flag+1] + [[newInterval[0],intervals[temp2][1]]] +intervals[temp2+1:]     
                '''
                if temp2==0:
                    intervals[temp2][0]=newInterval[0]
                    return intervals
                elif intervals[temp2-1][1]<newInterval[0]:
                    intervals[temp2][0]=newInterval[0]
                    return intervals
                else:
                    while intervals[temp2-1][1]>newInterval[0]:
                        intervals.pop(temp2-1)
                        temp2-=1
                        if temp2==0:break
                    intervals[temp2][0]=newInterval[0]
                    return intervals
                '''
            else:
                #newInterval[0]=min(newInterval[0],intervals[temp1][0])
                #newInterval[1]=max(newInterval[1],intervals[temp2][1])
                #return intervals[:temp1]+[newInterval]+intervals[temp2+1:]
                return intervals[:temp1]+[[intervals[temp1][0],intervals[temp2][1]]]+intervals[temp2+1:]
                '''
                intervals[temp1][1] = intervals[temp2][1]
                while temp2 -temp1>0:
                    intervals.pop(temp2)
                    temp2-=1
                return intervals
                '''