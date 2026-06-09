### 解题思路
我的思路：
直接暴力循环了，因为每个值最多出现一次，所以用字典存储比较方便。
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

```python3
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        max_i = 100
        max_j = 100
        dicts = {}
        for i in range(max_i):
            for j in range(max_j):
                value = x**i+y**j
                if value <= bound and value not in dicts:
                    dicts[value] = 1
                elif value > bound:
                    break
            if x**i > bound:
                break
        result = []
        for key in dicts:
            result.append(key)
        return result

```