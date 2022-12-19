![image.png](https://pic.leetcode-cn.com/f4ed597548479c7870fbb7bc2dc581c33ee2f3f5716afaa07c9bb6abfddf3ffe-image.png)
```
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        num = 0
        count = 0
        for i in guess:
            if i == answer[num]:
                count+=1
            num+=1
        return count
```
