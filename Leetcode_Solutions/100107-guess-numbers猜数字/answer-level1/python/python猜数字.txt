```python
class Solution(object):
    def game(self, guess, answer):
        """
        :type guess: List[int]
        :type answer: List[int]
        :rtype: int
        """
        count=0
        for i in range(len(guess)):
            if guess[i]==answer[i]:
                count+=1
        return count
```

![image.png](https://pic.leetcode-cn.com/4c7fb9f5f82367e8d053319e3127007326bf7a6f07ffd23d6350233b02bb44bb-image.png)
