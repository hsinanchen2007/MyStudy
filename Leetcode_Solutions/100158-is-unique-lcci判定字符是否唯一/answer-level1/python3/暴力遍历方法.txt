### 解题思路
此处撰写解题思路
遍历字符串，计算该字符在字符串中的统计个数，超过1则重复，返回false，否则返回True

### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        flag = 0
        for ss in astr:
            if astr.count(ss) >1 :
                flag = 1
                break
        if flag == 1 :
            return False
        if flag == 0:
            return True

```