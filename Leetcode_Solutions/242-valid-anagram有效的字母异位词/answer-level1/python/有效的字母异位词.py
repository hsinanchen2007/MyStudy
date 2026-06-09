### 解题思路
方法较多，可以排序之后看两者是否相等，但时间复杂度为nlgn，也可以用dict或者counter去比较是否相等。
此解法利用set先去比较两者元素是否相同，再去比较出现次数是否相同

### 代码

```python
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t): 
            return False
        se = set(s)
        if se == set(t):
            for i in se:
                # 直接比较字符元素个数比较字符的个数
                if s.count(i) != t.count(i):return False
            return True
        else:
            return False
```