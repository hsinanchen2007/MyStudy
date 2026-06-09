### 解题思路
1. 首先判断字符串是否为空.如果为空,直接返回0
2. 分割字符串,然后从后往前遍历list.如果最后一位是'',则删除;同时判断list是否为空,如果为空,说明字符换s是有空格组成,返回0
作为新手,很满意的成绩
![image.png](https://pic.leetcode-cn.com/4817489e1e5eaa2e96495d2bbc6c7a09b43012e97384f2da70591c830cda7023-image.png)

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s:
            return 0

        ns = s.split(' ')
        while ns[-1] == '':
            ns.pop(-1)
            if not ns:
                return 0

        return(len(ns[-1]))

```