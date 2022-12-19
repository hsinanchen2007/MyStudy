### 解题思路
#此处撰写解题思路
菜鸟
递归解法 （参考：CTRA王磊）
```num = self.countAndSay(n-1) + "*"```
妙啊，此处若改成```num = self.countAndSay(n-1) ```
就会出错 

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        if n ==1:
            return "1"
        count = 1
        return_str = ""
        num = self.countAndSay(n-1) + "*"
        for _ in range(len(num)-1):
            if num[_] == num[_+1]:
                count += 1
            else:
                return_str += str(count) + str(num[_])
                count = 1
        return return_str
```