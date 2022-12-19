### 解题思路
python3 是没什么人用吗？执行时间排第一还是第一次！！！有没有大神看看怎么优化一下我丑陋的code。。。。

### 代码

```python3
class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        A.sort()
        a = iter(A)
        b = [(v, k) for k, v in enumerate(B)]
        b.sort()
        useless = []
        result = [0] * len(A)

        for i in b:
            try:
              currentA = next(a)
            except StopIteration:
                break
            while currentA <= i[0] and currentA != '':
                useless.append(currentA)
                try:
                    currentA = next(a)
                except StopIteration:
                    break
            result[i[1]] = currentA
        lenth = len(A)
        lenthU = len(useless)
        if lenthU:
            for k in range(lenthU):
                key = b[lenth-lenthU+k][1]
                result[key] = useless[k]

        return result

```