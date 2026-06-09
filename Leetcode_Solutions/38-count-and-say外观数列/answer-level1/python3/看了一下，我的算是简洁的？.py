### 解题思路
主要用到的是迭代，关键点是这样的有实际含义的变量命名要合理一些。两层和上一字符比较的过程。

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        pre="1"
        for i in range(1,n):
            say=""
            cur=""
            count=1
            for char in pre:
                if cur=="":
                    cur=char
                elif cur==char:
                    count+=1
                else:
                    say+=str(count)+cur
                    count=1
                    cur=char
            say+=str(count)+cur
            pre=say
        return pre
```