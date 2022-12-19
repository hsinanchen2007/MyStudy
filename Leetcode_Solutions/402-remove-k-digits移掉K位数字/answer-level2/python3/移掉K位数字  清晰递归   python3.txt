### 解题思路
从头遍历字符串，遇到第i位字符小于第i+1位字符时，使用删除掉第i位的num和k-1递归调用本函数
如果该字符串单调不减，则使用删除掉最后一位的num和k-1递归调用本函数
如果k等于0，则递归结束，返回num
**注意：在函数的开头，首先要将字符串头部的‘0’删除掉**

### 代码

```python3
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        try:
            while num[0] == '0': num = num[1:]
        except:
            return '0'
        if len(num) == 1 and k == 1: return '0'
        if k == 0: return num
        for i in range(len(num)-1):
            if num[i+1] < num[i]:
                return self.removeKdigits(num[:i]+num[i+1:], k-1)
            if i == len(num)-2:
                return self.removeKdigits(num[:-1], k-1)
```