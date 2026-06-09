执行用时 :44 ms, 在所有 python3 提交中击败了92.46%的用户

使用递归对前一个字符串进行报数。
1. 首先添加一个计数器。
2. 每次检查一个字符，将其与下一个字符对比：
    - 如果相同，则计数器加1
    - 否则，计数器加1，报出此位及此位之前的所有相同字符（若无，则报1+本字符），同时计数器清零。
3. 最后一个字符需要单独处理，因为已经没有下一个字符可供比较了。

```python
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        if n == 2:
            return "11"
        if n == 3:
            return "21"

        s = self.countAndSay(n-1)
        say = ""
        count = 0
               
        for i in range(0, len(s)-1):
            count += 1
            if s[i] != s[i+1]: #下一位不同，计数到此位截至
                say += str(count) + s[i] # say 此位和前几位
                count = 0 #计数清零
        
        # 处理最后一位
        count += 1
        say += str(count) + s[-1]
        return say
```

