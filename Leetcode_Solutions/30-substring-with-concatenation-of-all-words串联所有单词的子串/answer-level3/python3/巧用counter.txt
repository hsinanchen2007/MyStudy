滑块模型逐行匹配，用字典Counter函数解决不同单词的组合问题

 

```python3
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        from collections import Counter 
        if not s or not words:return []
        word_lenth=len(words[0])
        word_num=len(words)
        all_lenth=word_lenth*word_num
        harsh=Counter(words)
        n=len(s)
        index=[]
        for i in range(0,n-all_lenth+1):
            a=[]
            for j in range(i,i+all_lenth,word_lenth):
                a.append(s[j:j+word_lenth])
            res=Counter(a)
            if res==harsh:
                index.append(i)
        return index
```