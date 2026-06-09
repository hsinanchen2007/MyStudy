```
class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        #列表li1用来存放queries中对应字符串的字母最小频次数
        li1=[]
        for i in range(len(queries)):
            k = Solution.SmallNums(queries[i])
            li1.append(k)
        #列表li2用来存放words中对应字符串的字母最小频次数
        li2=[]
        for j in range(len(words)):
            m = Solution.SmallNums(words[j])
            li2.append(m)
        #列表li3为返回的列表
        li3=[]
        for a in range(len(li1)):
            c=0
            for b in range(len(li2)):
                if li1[a] < li2[b]:
                    c += 1
            li3.append(c)
        return li3
    #设计最小字母频次计算的函数
    def SmallNums(x):
        li = []
        li = list(x)
        li.sort()        
        nums = li.count(li[0])
        return nums
```
