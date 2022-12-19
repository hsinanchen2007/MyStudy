### 解题思路
我的思路：效率不高，因为每次都要重置数组。有个问题就是其实两个字典就可以了，但是赋值就变成别名...Python没掌握好
	

复杂度分析：                                                             
	• 时间复杂度：o(n^2)
	• 空间复杂度：o(n)



### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        dicts = {}
        for x in chars:
            if x not in dicts:
                dicts[x] = 1
            else:
                dicts[x] += 1
        pipei = 1
        sums = 0
        for x in words:
            for k in x :
                if k in dicts:
                    dicts[k] -= 1
                    if dicts[k] == 0:
                        del dicts[k]
                else:
                    pipei = 0
                    break
            if pipei:
                sums += len(x)
            pipei = 1
            dicts = {}
            for x in chars:
                if x not in dicts:
                    dicts[x] = 1
                else:
                    dicts[x] += 1
        return sums
            
```