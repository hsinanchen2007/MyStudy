**思路：**

对`B`中的每个单词统计字母出现次数，然后建一个`counter`来统计每个字母在`B`中出现次数的最大值（相当于取并集，也就是下面第二个写法里每次计算差集再相加）。最后判断`A`中的每个单词是否满足`counter`即可。

**代码：**

```python
class Solution:
    def wordSubsets(self, A, B):
        """
        :type A: List[str]
        :type B: List[str]
        :rtype: List[str]
        """
        # make dict
        dict_A = []
        dict_B = []
        for s in A:
            d = dict()
            for c in s:
                if c in d:
                    d[c] += 1
                else:
                    d[c] = 1
            dict_A.append(d)
        for s in B:
            d = dict()
            for c in s:
                if c in d:
                    d[c] += 1
                else:
                    d[c] = 1
            dict_B.append(d)
        # union dict_B
        judger = dict()
        for d in dict_B:
            for c in d:
                if c not in judger or judger[c] < d[c]:
                    judger[c] = d[c]
                    
        # judge if d1 is subset of d2
        def isSub(d1, d2):
            for k in d1:
                if k not in d2 or d1[k] > d2[k]:
                    return False
            return True
        
        # cal ans
        ans = []
        for i in range(len(A)):
            if isSub(judger, dict_A[i]):
                ans.append(A[i])
        return ans
```

更简单的写法

```python
class Solution:
    def wordSubsets(self, A, B):
        """
        :type A: List[str]
        :type B: List[str]
        :rtype: List[str]
        """
        
        union_B = []
        ans = []
        for b in B:
            dict_B = union_B.copy()
            for i in b:
                if i in dict_B:
                    dict_B.remove(i)
                else:
                    union_B.append(i)
                    
        for a in A:
            ok = True
            i = list(a)
            for j in union_B:
                if j in i:
                    i.remove(j)
                else:
                    ok = False
                    break
            if ok:
                ans.append(a)
        return ans
```