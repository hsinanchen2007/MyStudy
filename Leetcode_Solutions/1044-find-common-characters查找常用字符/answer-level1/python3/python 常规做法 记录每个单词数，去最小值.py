解题思路：用数组代替哈希表，记录每个字母的个数
```
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        a = [0 for _ in range(26)]
        #记录每个单词的个数
        b = []
        #最后返回的列表
        for j in A[0]:
            a[ord(j)-ord('a')]+=1
        #记录第一个单词中每个字母的个数
        for i in range(len(a)):
            if a[i]==0:
                continue
            #如果个数为0直接跳过
            for j in range(1,len(A)):
                a[i]=min(a[i],A[j].count(chr(i+ord('a'))))
            #否则记录它们的最下值
        for i,elemt in enumerate(a):
            if elemt==0:
                continue
            for x in range(elemt):
                b.append(chr(i+ord('a')))
        return b
```
