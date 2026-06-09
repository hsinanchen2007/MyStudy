### 解题思路
抄了作业。。。

### 代码

```python3
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        if A == None:
            return []

        res = []
        key = set(A[0])  # 因为不在A[0]里的字母肯定不会在结果里，所以可以用任何一个单词来获取这些key
        for k in key:  
            minimum = min(a.count(k) for a in A)   # 不用字典的方法，直接用count()来统计这些key在每个单词里出现的次数，取最少次数的
            res += minimum*k   # 加到结果里，有多个相同的则需要加入多次
        return res

        # 想得太复杂了
        # words = []
        # for item in A:
        #     dic = collections.Counter(item)
        #     sortedDic = sorted(dic.items(),key = lambda x:x[0])
        #     words.append(sortedDic)
        #     print(sortedDic)
        
        # res = []
        # for key,_ in words[0].items():
        #     minValue = min()
        #     for i in range(len(words)):
                

```