### 解题思路
利用正则表达式匹配连续出现两次的字符，再用sub去替换，重复此过程直到找不到这种匹配模式
![捕获.PNG](https://pic.leetcode-cn.com/bdfd804f7824d623a93b23908f7b8eacb3d70c6046cec08e59c3337254c31087-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```python3
class Solution:
    def removeDuplicates(self, S: str) -> str:
        import re
        def func(s):
            return re.sub(r'(.)\1',"",s)
        while re.findall(r'(.)\1',S) != []:
            S = func(S)
        return S
```