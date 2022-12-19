```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        list1,list2,list3,result = [],[],[],[]
        flg = "tr"
        for i in intervals:
            if i[0] == i[-1]:
                if i not in list3:
                    list3.append(i)
                    continue
            for j in range(i[0],i[-1]):
                if j not in list1:
                    list1.append(j)
        list1.sort()
        for k in list1:
            if list2 == []:
                list2.append(k)
            elif k == list2[-1] + 1 and len(list2) == 1:
                list2.append(k)
            elif k == list2[-1] + 1 and len(list2) > 1:
                list2[-1] = k
            else:
                if len(list2) != 1:
                    list2[-1] = list2[-1] + 1
                else:
                    list2.append(list2[0] + 1)
                result.append(list2)
                list2 = []
                list2.append(k)
            if k == list1[-1]:
                if len(list2) == 1:
                    list2.append(k+1)
                else:
                    list2[-1] = list2[-1] + 1
                result.append(list2)
        if list3 == []:
            return(result)
        else:
            for kk in list3:
                flg = "tr"
                for jj in result:
                    if  jj[0] <= kk[0] <= jj[1]:
                        flg = "fl"
                        break
                if flg == "tr":
                    result.append(kk)
            return(result)
```
