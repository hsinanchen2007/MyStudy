### 解题思路
- 始终保证first比second要短，这样可以把问题简化为只需要考虑**插入**和**替换**的情况
- 先过滤掉长度差大于1的情况
- 对于长度相等的情况，只需要统计两**字符串对应位置有多少个不同的字符**即可。
- 对于长度相差为1的情况，若遇到不同的字符，`first`字符串的索引停止增加。不同的次数大于1则所说明不满足要求。
### 代码

```python
class Solution(object):
    def oneEditAway(self, first, second):
        """
        :type first: str
        :type second: str
        :rtype: bool
        """
        # 始终保证first要短一些
        if len(first) > len(second):
            first, second = second, first
        # 只需要考虑插入和替换

        if len(second) - len(first) > 1:
            return False
        elif len(first) == len(second):
            i = fix = 0
            while i < len(first):
                if first[i] != second[i]:
                    fix += 1
                if fix > 1:
                    return False
                i += 1
            return True
        else:  # second 比 first 长一字符
            i = j = fix = 0
            while i < len(first):
                if first[i] != second[j]:
                    fix += 1
                else:
                    i += 1
                j+=1
                if fix > 1:
                    return False
            return True
```