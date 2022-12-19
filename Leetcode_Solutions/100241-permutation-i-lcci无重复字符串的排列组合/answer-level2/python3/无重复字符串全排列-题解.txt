### 解题思路
深度递归方法：
- 递归的方法需要维护一个存储排列的变量，用来记录某一种排列方式；
- 为什么会想到递归呢，是因为按照直接的暴力解法，需要不断地写循环，进行字符的排列组合；循环套循环的方式，至少要套N（原字符串长度）个循环，这当然不可能；
- 再考虑，循环的目的是为了得到还未入列的字符，也可以说是还为访问过的字符，那递归也可以实现这样的目的；
- 因为是无重复字符串，所以在每次递归遍历的时候，可以通过判断是否已经入列来进行筛选；
- 递归需要有截止条件，因为本题中的排列与原字符串等长，所以只需要判断存储排列的变量的字符长度是否等于N即可；
- 当满足某一个排列之后，将已有排列存入结果数组中，继续下一个排列的遍历；
- 此时，需要先把已排列变量的最后一个字符剔除，为下一个排列留出空间；

### 代码

```python3
class Solution:

    def find(self, cnt):
        if cnt == self.lgth:
            self.rst += [self.stack]

        for item in self.S:
            if item in self.stack:
                continue
            self.stack += item
            cnt += 1
            self.find(cnt)
            self.stack = self.stack[:-1]
            cnt -= 1


    def permutation(self, S: str) -> List[str]:
        self.lgth = len(S)
        self.stack = ''
        self.rst = []
        self.S = S

        self.find(cnt=0)

        return self.rst
```