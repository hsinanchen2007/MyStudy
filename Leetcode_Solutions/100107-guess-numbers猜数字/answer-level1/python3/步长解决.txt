### 解题思路
连接起新的列表利用步长对称性进行比较。
### 代码

```python3
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        t=0
        if len(guess)==3 and len(answer)==3:
            lst=guess+answer
            for i in range(len(guess)):
                    if len(set(lst[i::3]))==1:
                        t=t+1
            return t
```