### 解题思路
第一次用python做题
很好懂的方法，查找-c-d有没有相等的a+b就行了
有一说一，python是比java好做。。。
但还不熟悉，看不懂大佬的两行。。。
### 代码

```python
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        count ={}
        for a in A:
            for b in B:
                if(a+b) in count:
                    count[a+b]+=1
                else:
                    count[a+b]=1
        counter=0
        for c in C:
            for d in D:
                if(-c-d in count):
                    counter+=count[-c-d]
        return counter
```