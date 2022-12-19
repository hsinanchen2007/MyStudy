#### 解题思路：
+ 遍历从 `left` 到 `right` 到每个数
+ 如果这个数符合要求，把它添加到输出列表中
+ 如何判断是否符合要求？
    + 设置一个临时变量等于这个原数
    + 每次让临时变量对 10 取余，即是临时变量的末尾，比如 128 对 10 取余的结果是 8
    + 判断原数对这个余数是否能整除，不能就直接 `break` 了，进入下一个数
    + 临时变量对自己整除 10，比如 128 整除 10 就是 12 了，这样再下个循环中取余就是 2
+ 注意两点
    + 取余数后要先判断是否等于 0，因为没有办法对 0 求余数。注意 `or` 运算先算左边再算右边，顺序不能错咯
    + 设置一个临时变量是否等于 0 的判断，来鉴别 `while` 是被 `break` 了还是正常结束。
#### 代码：
8 行 超简单。
```Python [-Python]
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ans = []
        for num in range(left,right + 1):
            copy = num
            while copy > 0:
                div, copy = copy % 10, copy // 10
                if div == 0 or num % div != 0: break
            else: ans.append(num) # while … else 在循环条件为 false 时执行 else 语句块
        return ans
```
#### 花样一行法:
思路是用生成器和生成器的条件筛选构造一个列表，看代码就懂了，挺清晰的。
提一下 `all()` 函数，是这样的，如果里面的参数每一项都是 `True`，那么返回 `True`，否则返回 `False`，`any()` 与之对应。
```Python [-Python]
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        return [n for n in range(left, right + 1) if \
               '0' not in str(n) and all([n % int(b) == 0 for b in str(n)])]
```