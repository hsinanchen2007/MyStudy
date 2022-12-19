将newInterval插入intervals中，然后创建一个数组，里面保存着【起始端点，True】，【结束端点，False】的信息，然后利用sorted对数组进行排序，优先按照端点的值排序，再按照Ture，False的值降序排序。对排序后的数组进行遍历，用count值来判断是否应该作为最后的结果，若遍历到True，则count加一，否则，count减一。利用count来判断是否应该作为最后的结果存在。
```
class Solution(object):
    def insert(self, intervals, newInterval):
        intervals.extend([newInterval])
        temp=[]
        #构造中间数组
        for k in intervals:
            temp.append((k[0],True))
            temp.append((k[1],False))
        #对中间数组进行排序
        temp=sorted(temp,key=lambda x:(x[0],-x[1]))
        res=[]
        count=0
        #print(temp)
        #遍历中间数组，得到最后的结果
        for i,j in temp:
            if j==True:
                count+=1
                if count==1:
                    res.append([])
                    res[-1].append(i)
            else:
                count-=1
                if count==0:
                    res[-1].append(i)
        #print(res)
        return res
```
