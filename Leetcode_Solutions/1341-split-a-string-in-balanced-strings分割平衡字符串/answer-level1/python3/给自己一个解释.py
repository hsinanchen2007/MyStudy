### 解题思路
暴力扫描 当遇到一个L计数 当遇到一个R计数 当LR数量一样的时候 说明有一对平衡字符串

### 代码

```python3
class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        count_L = 0
        count_R = 0
        
        for s_ in s:
            if s_ == 'L':
                count_L += 1
            else:
                count_R += 1
            if count_L == count_R:
                count += 1
        return count

```