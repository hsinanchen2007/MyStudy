# 关于小A和小B的随机选择。

一开始以为需要进行随机选择，后来发现是在输入guess数组和answer数组时存在随机性。所以代码中没有随机性选择数字的体现。
```
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        count = 0
        for i in range(3):
            if answer[i] == guess[i]:
                count += 1
        return count
```



