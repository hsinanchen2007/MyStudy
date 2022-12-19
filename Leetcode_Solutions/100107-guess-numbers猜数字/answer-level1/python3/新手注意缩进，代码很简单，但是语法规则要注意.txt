### 解题思路
代码很简单，主要是python3的话在def下一行需要缩进一个空格不然会报错

### 代码

```python3
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
     return sum(guess[i]==answer[i] for i in range(3))
```