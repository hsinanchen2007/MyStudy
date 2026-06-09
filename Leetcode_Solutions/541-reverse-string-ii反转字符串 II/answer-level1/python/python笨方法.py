```
class Solution(object):
    def reverseStr(self, s, k):
        s_List = []
        for ss in s:
            s_List.append(ss)
        N = len(s)/(2*k)
        if len(s)%(2*k) == 0:#刚好N份
            reList = []#结果
            for i in range(0,N):#1到N
                tempList = s_List[i*2*k:i*2*k+k]
                tempList = list(reversed(tempList))#反转
                for j in range(k):#不用反转的字符串加在后面
                    tempList.append(s_List[i*2*k+k + j])
                for t in tempList:
                    reList.append(t)
            return "".join(reList)  
        elif len(s)%(2*k) >=k and len(s)%(2*k) <2*k:#肯定小于2K
            reList = []#结果
            for i in range(0,N+1):#1到N+1
                tempList = s_List[i*2*k:i*2*k+k]
                tempList = list(reversed(tempList))#反转
                print(tempList)
                if i < N:
                    for j in range(k):#不用反转的字符串加在后面
                        tempList.append(s_List[i * 2 * k + k + j])
                else:
                    for j in range(len(s)%(2*k) - k):
                        tempList.append(s_List[i * 2 * k + k + j])
                for t in tempList:
                    reList.append(t)
            return "".join(reList)
        else:#小于k
            reList = []#结果
            for i in range(0,N):#1到N
                tempList = s_List[i*2*k:i*2*k+k]
                tempList = list(reversed(tempList))#反转
                for j in range(k):#不用反转的字符串加在后面
                    tempList.append(s_List[i*2*k+k + j])
                for t in tempList:
                    reList.append(t)
            for j in range(len(s)%(2*k)):
                reList.append(s_List[len(s)-1-j])           
            return "".join(reList)
```