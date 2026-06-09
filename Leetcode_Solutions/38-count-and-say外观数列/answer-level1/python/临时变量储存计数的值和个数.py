基本思路就是递归，临时变量记录计数的值和个数
```python
class Solution:
    def countAndSay(self, n: int) -> str:
        result = ""
        if n == 1:
            result = "1"
        else:
            #当前计数的值
            temp = ""
            #当前计数的个数
            count = 0
            #递归上个答案
            pre = self.countAndSay(n-1)
            for i in range(len(pre)):
                #temp为空表示第一次循环
                if not temp:
                    temp = pre[i]
                    count += 1
                elif temp == pre[i]:
                    count += 1
                elif temp != pre[i]:
                    result += str(count) + temp
                    temp = pre[i]
                    count = 1
                # 最后一次循环
                if i == len(pre)-1:
                    result += str(count) + temp
        return result
```
