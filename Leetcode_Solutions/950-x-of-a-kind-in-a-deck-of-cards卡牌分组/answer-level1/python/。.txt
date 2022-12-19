### 解题思路
多次循环判断最大公约数得出结果。
![image.png](https://pic.leetcode-cn.com/6ef8bbd332849d9b52e2e127809e6e70c7d305c6d185dd3aeab9cceff9b49cda-image.png)


### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        myset = set(deck)
        key = 0
        for i in myset:
            if key == 0:
                if len(deck) >1 and len(myset) ==1:
                    result = True
                    break
                lastj = deck.count(i)
                key = 1
                result = False
            elif key == 1:
                j = deck.count(i)
                while j != lastj:
                    if j>lastj:
                        j = j-lastj
                    else:
                        lastj = lastj - j
                if j > 1:
                    result = True
                else:
                    result = False
                    break
                lastj = deck.count(i)
        return result
```