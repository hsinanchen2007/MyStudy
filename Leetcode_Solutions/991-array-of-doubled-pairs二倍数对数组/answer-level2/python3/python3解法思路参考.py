### 解题思路
先排序，历遍列表，用字典记录元素和出现次数，负数部分找对应1/2的数，正数部分找2倍的数.

### 代码

```python3
class Solution:
    def canReorderDoubled(self, A):
        # 先历遍一遍用字典存下来元素和数量
        A.sort()
        dct = {}
        for i in A:
            dct[i] = dct.get(i , 0) + 1
        #print(dct)
        for i in dct:
            if dct[i]:   # 数字还有剩的才减
                if i < 0: # 负数部分找1/2的数
                    if i/2 in dct:
                        dct[i/2] -= dct[i]
                        if dct[i/2] < 0:
                            return False
                    else:
                        return False
                else: # 正数部分找2倍的
                    if i * 2 in dct:
                        dct[i * 2] -= dct[i]
                        #print(dct)
                        if dct[i * 2] < 0:
                            return False
                    else:
                        return False
        
        return True
```