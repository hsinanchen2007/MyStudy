### 解题思路
方法一用字典来实现查找，每次查找O（1）；方法二主要利用python的collections包的Counter计数，和alla（）的迭代实现类似功能，但因为没有剪枝，所以比方法一慢一些。

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        #方法一
        # char = {}
        # ans = 0
        # for i in chars:
        #     if char.get(i) ==None:
        #         char[i] = 1
        #     else:
        #         char[i] += 1
        # for i in words:
        #     judge = True
        #     count = char.copy()
        #     for j in i:
        #         if count.get(j) == None or count.get(j) ==0:
        #             judge = False
        #             break
        #         else:
        #             count[j] -= 1
        #     if judge:
        #         ans += len(i)
        # return ans

        #方法二
        char = collections.Counter(chars)
        ans = 0
        for i in words:
            k = collections.Counter(i)
            if all(k[j]<=char[j] for j in i):
                ans += len(i)
        return ans
```