### 解题思路
题目本身不难，只是需要考虑的特殊情形太多了。稍微梳理下，实际上分为4类字符：
1. **空格**：允许跳过的空格必须是在数字或符号之前发现；一旦已经有数字或者符号了，那么再出现空格就必须跳出
2. **正负号**：允许接收的符号必须在数字之前，且最多一次；如果已经接收了一个符号，那么再出现符号就必须跳出
3. **数字**：再不是空格和符号的情况下，如果是有效的数字全盘接收，用一个ans列表保存
4. **其他**：如果不满足1、2或3，则意味着后续的字符不再接收

对结果进行处理：
- 如果接收到的数字列表ans为空，则直接返回0
- 如果ans不为空，说明有结果，此时如果已经接收到了一个明确的正负号flag，则用flag，否则默认为+1
- 如果解析的整数超出有效区间（python实际无数值大小限制），则进行相应的截断处理。

### 结果
![image.png](https://pic.leetcode-cn.com/da834eb1bb0b0efc29e1af78d0045b02b4b34aec38f2015fc042d2a78ba0b450-image.png)

先这样吧……

### 代码

```python3
class Solution:
    def myAtoi(self, str_: str) -> int:
        flag, ans = None, []
        for c in str_:
            if c == ' ' and not ans and not flag:
                continue
            elif c in '+-' and not flag and not ans:
                flag = (1 if c=='+' else -1)
            elif c in '0123456789':
                ans.append(c)
            else:
                break
        if not ans:
            return 0
        ans = (flag if flag else 1)*int(''.join(ans))
        return ans if -2**31<=ans<=2**31-1 else (2**31-1 if ans>0 else -2**31)
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)