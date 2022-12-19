### 解题思路
我的思路：用字典解决，分为两个步骤，详看代码实现.
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

```python
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        dicts = {}
        sums1 = 0
        sums2 = 0 
        for x in dominoes:
            x = str(x)
            if x not in dicts:
                dicts[x] = 1
            else:
                dicts[x] += 1
        for key in dicts:
            if dicts[key] > 1:
                n = dicts[key]
                sums1 += n*(n-1)//2
               
        for x in dominoes:
            x[0],x[1] = x[1],x[0]
            if x[0]!=x[1]:
                x = str(x)
                if x in dicts:
                    sums2 += dicts[x]
        sums2 = sums2 // 2
        return sums1+sums2
```