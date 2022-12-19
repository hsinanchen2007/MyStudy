核心思想就是栈操作，遇到左括号栈顶就压入空串，遇到右括号就反转栈顶并与栈顶第二个元素合并，其他情况栈顶直接累加元素，最后输出栈内唯一元素。

![image.png](https://pic.leetcode-cn.com/ba36841ebf9457a8f35e53f45592701f36b4c7e19e481311b6cb993e99d90eac-image.png)

提交时间48ms，仅供参考。

```python []
class Solution:
    def reverseParentheses(self, s: str) -> str:
        ans = ['']
        for c in s:
            if c == '(':
                ans += ['']
            elif c == ')':
                ans[-2] += ans[-1][:: -1]
                ans.pop()
            else:
                ans[-1] += c
        return ans[0]
```

样例栈数组操作示意：

```
a(bcdefghijkl(mno)p)q

a ['a']
( ['a', '']
b ['a', 'b']
c ['a', 'bc']
d ['a', 'bcd']
e ['a', 'bcde']
f ['a', 'bcdef']
g ['a', 'bcdefg']
h ['a', 'bcdefgh']
i ['a', 'bcdefghi']
j ['a', 'bcdefghij']
k ['a', 'bcdefghijk']
l ['a', 'bcdefghijkl']
( ['a', 'bcdefghijkl', '']
m ['a', 'bcdefghijkl', 'm']
n ['a', 'bcdefghijkl', 'mn']
o ['a', 'bcdefghijkl', 'mno']
) ['a', 'bcdefghijklonm']
p ['a', 'bcdefghijklonmp']
) ['apmnolkjihgfedcb']
q ['apmnolkjihgfedcbq']
```
