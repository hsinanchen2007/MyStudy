#### 思路
如果结果为`True`，相当于将`nums`倒序，并将`6`替换为`9`后与输入相同。所以遍历`nums`，保存在`ans`中，如果倒序`ans`与`nums`相同则为True，否则为False
#### 代码
```
class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        ans = ''
        for i in num:
            if i == '2' or i == '3' or i == '4' or i == '5' or i == '7':
                return False
            elif i == '9':  # 遇到6或者9需要换一下
                a = '6'
                ans += a
            elif i == '6':
                a = '9'
                ans += a
            else:
                a = i
                ans += a
            print(ans)
        if num != ans[::-1]:
            return False
        return True
```
#### 复杂度分析
- 时间复杂度：O(N)
- 空间复杂度：O(1)

![白色背景关注.jpg](https://pic.leetcode-cn.com/6c18bb76abad971a2db54a010561f44fd1445ca10f9b671ecfee1a7df2482c08-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
