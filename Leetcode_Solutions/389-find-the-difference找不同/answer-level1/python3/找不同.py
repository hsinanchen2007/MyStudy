### 解题思路
我的思路：不说啦
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        dicts = {}
        for x in s:
            if x not in dicts:
                dicts[x] = 1
            else:
                dicts[x] += 1
        for x in t:
            if x not in dicts:
                return x
            else:
                dicts[x] -= 1
                if dicts[x] == 0:
                    del dicts[x]
        
```