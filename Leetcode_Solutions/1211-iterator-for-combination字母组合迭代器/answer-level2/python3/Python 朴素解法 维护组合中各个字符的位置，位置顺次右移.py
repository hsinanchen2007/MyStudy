![image.png](https://pic.leetcode-cn.com/a8ec8d2f1e970155d2c908ba4737e61f3c219f89f31cf2328b7ef818b7f29739-image.png)


```
'''
维护combinationLength个数位的数值，每次调用next时候顺次把数位移动到下一位置
'''


class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.s = characters
        self.pos = [i for i in range(combinationLength)]
        self.valid = combinationLength <= len(characters)

    def next(self) -> str:
        n = len(self.s)

        ans = ''
        for val in self.pos:
            ans += self.s[val]

        if self.pos[-1] == n - 1 and self.pos[0] == n - len(self.pos):
            self.valid = False
            return ans

        # 更新位置
        if self.pos[-1] != n-1:
            self.pos[-1] += 1
        else:
            i = len(self.pos)-1
            while self.pos[i-1] == self.pos[i] - 1:
                i -= 1

            self.pos[i-1] += 1
            for j in range(i, len(self.pos)):
                self.pos[j] = self.pos[j-1] + 1

        return ans


    def hasNext(self) -> bool:
        return self.valid
```
