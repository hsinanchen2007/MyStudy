首先按照字符串长度进行排序，从最短字符串入手，用set函数去除重复字符，并分别遍历set中的每个字符在所有字符串中的count的最小值，并以此字符串为字符和count的最小值为数量append到ans里面。
```
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        sortA=sorted(A,key = lambda i:len(i))
        ans=[]
        for letter in set(sortA[0]):
            tem=[]
            for words in A:
                tem.append(words.count(letter))
            if min(tem)!=0:
                for i in range(min(tem)):
                    ans.append(letter)
        return ans
```
