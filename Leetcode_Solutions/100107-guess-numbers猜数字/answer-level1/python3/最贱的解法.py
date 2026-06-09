![image.png](https://pic.leetcode-cn.com/46e013c83b69fab3c2bf3d4a2bcb6d64bfb4191ee41d2474c44b69c89a0e5501-image.png)
史上最简单的题目和史上最简单的解法（看到了限制，我写for的手在微微颤抖，老板看到了我写这么多代码肯定会夸奖我的），第一次在leetcode找到自信
```
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        r=0
        if guess[0]==answer[0]:
            r=r+1
        if guess[1]==answer[1]:
            r=r+1
        if guess[2]==answer[2]:
            r=r+1
        return r
```
