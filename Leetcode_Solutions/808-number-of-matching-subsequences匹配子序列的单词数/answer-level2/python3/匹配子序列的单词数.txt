### 解题思路
利用字典树的思想，计算words中每个字符串的前缀，利用waiting存储{w[0]:w[1:]}形式的字典，这样就缩短了words的遍历次数：
S = "abcde"
words = ["a", "bb", "acd", "ace"]

小笔记：
1. defaultdict和dict的区别：当dict[key]查找不存在的key时会出错，但defaultdict[key]查找不存在的key时会返回一个默认值，初始化时defaultdict(list/set/dict/tuple)括号里是啥，默认值就会是对应类型的空，比如defaultdict(list)就会返回一个空列表()
2. 

### 代码

```python3
class Solution:
    def numMatchingSubseq(self, S: str, words: List[str]) -> int:
        waiting = defaultdict(list)
        for w in words:
            waiting[w[0]].append(iter(w[1:]))  # 存储以w[0]开头的前缀，此时waiting = {'a': [[], ['c', 'd'], ['c', 'e']], 'b': [['b']]}
        for c in S:
            for it in waiting.pop(c, ()):
                waiting[next(it, None)].append(it)  # 在本题的例子中 it 分别为[]、['c', 'd']、['c', 'e']
        return len(waiting[None])

# 作者：tc_leetcode


        # 第41个用例超时
        # def helper(s, obj):
        #     obj = list(obj)
        #     for _s in s:
        #         if not obj:
        #             return True
        #         if _s == obj[0]:
        #             obj.pop(0)
        #     return not obj 
        
        # res = []
        # for word in words:
        #     res.append(helper(S, word))
        
        # return res.count(True)

        
```