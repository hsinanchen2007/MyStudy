### 解题思路
用collections.Counter(A)记录各元素个数。
然后遍历列表，当i/2不在count时在进行操作。即从最底层开始，找2*i

### 代码

```python3
class Solution:
    def canReorderDoubled(self, A: List[int]) -> bool:
        count=collections.Counter(A)
        for i in A:
            if i/2 in count:continue
            elif i not in count:continue
            else:
                while 2*i in count:
                    if count[i]>count[2*i]:return False
                    elif count[i]==count[2*i]:
                        del count[i]
                        del count[2*i]
                        i=i*4
                    else:
                        count[2*i]-=count[i]
                        del count[i]
                        i*=2
                if i in count:return False
        return True
```