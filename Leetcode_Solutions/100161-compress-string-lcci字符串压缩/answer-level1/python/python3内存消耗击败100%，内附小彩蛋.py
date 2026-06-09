### 解题思路
思路很简单：遍历字符串，如果与前一个字母不相同做加num操作

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        ans = ""
        num = 0
        for i in range(len(S)):
            if ans == "":
                ans += S[i]
            if S[i] != ans[-1]:
                ans += str(num) + S[i]
                num = 1
            else:
                num += 1
        ans += str(num)

        #return min(ans,S)#这里我一开始写的return会出错是个小彩蛋
        if len(ans) >= len(S):
            return S
        return ans
```
![捕获.PNG](https://pic.leetcode-cn.com/1e5b459c981b5cc06ddd1f0dd501a655535dfd0afef7e742dd98e176e0e5c9ca-%E6%8D%95%E8%8E%B7.PNG)

    大家可以观察一下这里，min（）里放两个字符串比较的确实是字符串长度但是记录法与我们自数不尽相同

        

