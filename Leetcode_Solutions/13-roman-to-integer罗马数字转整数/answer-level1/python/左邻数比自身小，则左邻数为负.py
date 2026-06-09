
```python []
    class Solution(object):
        def romanToInt(self, s):
            """
            :type s: str
            :rtype: int
            """
            map={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000,'O':0}
            s=s+'O'
            sum=0
            for i in range(0,len(s)-1):
                if map[s[i]]<map[s[i+1]]:
                    sum-=map[s[i]]
                else:
                    sum+=map[s[i]]
            return sum
```

执行用时 :
32 ms
, 在所有 Python 提交中击败了
99.05%
的用户
内存消耗 :
11.5 MB
, 在所有 Python 提交中击败了
34.77%
的用户