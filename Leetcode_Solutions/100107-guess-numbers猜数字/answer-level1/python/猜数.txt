### 解题思路
暴力求解，循环遍历判断，并用累加器记录猜对次数并返回终值

### 代码

```python
class Solution(object):
    def game(self, guess, answer):
        """
        :type guess: List[int]
        :type answer: List[int]
        :rtype: int
        """
        count=0
        for i in range(0,len(guess)):
            if guess[i] == answer[i]:
              count+=1
        return count
        
```