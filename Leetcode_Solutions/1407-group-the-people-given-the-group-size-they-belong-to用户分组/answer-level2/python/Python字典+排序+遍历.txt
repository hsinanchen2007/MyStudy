1.使用Python字典进行存储，key值为序号，value值为groupSizes的值
2.按照value进行排序
3.遍历排序后的items，与前一个进行对比，如果在同一组且最大组员个数没有超出就加入，否则就新开一组加入
```
class Solution(object):
    def groupThePeople(self, groupSizes):
        d={}
        for i in range(len(groupSizes)):
            d[i]=groupSizes[i]
        items=sorted(d.items(), key=lambda x: x[1])
        a=[[]]
        j=0
        a[j].append(items[0][0])
        for i in range(1,len(items)):
            if(items[i][1]==items[i-1][1] and len(a[j])<items[i][1]):
                a[j].append(items[i][0])
            else:
                a.append([])
                j+=1
                a[j].append(items[i][0])
        return a
```
