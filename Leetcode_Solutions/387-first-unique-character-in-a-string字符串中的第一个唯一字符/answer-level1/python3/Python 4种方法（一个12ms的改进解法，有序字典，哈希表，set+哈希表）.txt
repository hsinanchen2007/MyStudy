## 0. 12ms的改进解法
#### 说明：
 1. 已知字符串由小写字母构成，则遍历a-z
 2. 分别从目标的字符串头和字符串尾查找对应字母的索引；如果两索引相等，则说明是单一字符
 3. 从该索引和此前遍历记录的最小索引中选出新的最小索引
 4. 遍历结束后，最小索引即为进行26次遍历返回的最小索引值
#### 效率：
> Runtime: 12 ms, faster than 99.96% of Python online submissions for First Unique Character in a String.
> Memory Usage: 12.2 MB, less than 76.06% of Python online submissions for First Unique Character in a String.
> 执行用时 :24 ms, 在所有 Python 提交中击败了100.00%的用户
> 内存消耗 :12 MB, 在所有 Python 提交中击败了38.99%的用户
#### 复杂度分析：
 - 时间复杂度：$O(N)$ - 常数级别的遍历; 内嵌O(N)[(r)find一般情况下为](https://stackoverflow.com/questions/26008904/python-cost-of-find-function)
 - 空间复杂度：$O(1)$
#### 代码:
```Python
class Solution(object):

    def firstUniqChar(self, s: str) -> int:
        # 先假设最小索引为最后的字符索引
        min_unique_char_index = len(s)

        # 已知字符串由小写字母构成，则遍历a-z
        for c in "abcdefghijklmnopqrstuvwxyz":
            i = s.find(c)
            # 分别从目标的字符串头和字符串尾查找对应字母的索引；如果两索引相等，则说明是单一字符
            if i != -1 and i == s.rfind(c):
                # 更新最新的最小索引
                min_unique_char_index = min(min_unique_char_index, i)

        # 如果返回值不为最后字符的索引，则返回最小索引值
        # 否则，根据题意，返回-1
        return min_unique_char_index if min_unique_char_index != len(s) else -1

```
## 1. 有序字典（OrderedDict）
#### 效率：
> Runtime: 476 ms, faster than 5.17% of Python online submissions for First Unique Character in a String.
> Memory Usage: 12.1 MB, less than 82.75% of Python online submissions for First Unique Character in a String.
#### 复杂度分析：
 - 时间复杂度：$O(N)$
 - 空间复杂度：$O(N)$
#### 代码：
```Python
from collections import OrderedDict


class Solution(object):

    def firstUniqChar(self, s: str) -> int:
        odict = OrderedDict()

        # 记录字符出现次数
        for c in s:
            odict[c] = odict[c] + 1 if c in odict else 1

        # 利用有序的特性，在字典中找出首个出现次数为一的字符串
        for k, v in odict.items():
            if v == 1:
                # 返回字符串首次出现的位置
                return s.index(k)

        return -1

```
## 2. 字典
#### 改进：
 - 字典的创建与修改操作，相比有序字典，更加高效
#### 效率：
> Runtime: 108 ms, faster than 77.25% of Python online submissions for First Unique Character in a String.
> Memory Usage: 12.1 MB, less than 84.16% of Python online submissions for First Unique Character in a String.
#### 复杂度分析：
 - 时间复杂度：$O(N)$
 - 空间复杂度：$O(N)$
#### 代码：
```Python
class Solution3(object):

    def firstUniqChar(self, s: str) -> int:
        dic = {}

        # 记录字符出现次数
        for c in s:
            dic[c] = dic[c] + 1 if c in dic else 1

        # 过滤出现次数不为一的字符
        unique_chars = [k for k, v in filter(lambda kvp: kvp[1] == 1, dic.items())]
        # 遍历目标字符串，返回首个出现在unique_chars中的字符的索引
        for i, c in enumerate(s):
            if c in unique_chars:
                return i

        return -1

```
## 3. 字典+集合
#### 改进：
 - 使用Python内置的set()以及str.count()，进一步提高代码执行效率
#### 效率：
> Runtime: 68 ms, faster than 92.07% of Python online submissions for First Unique Character in a String.
> Memory Usage: 12.2 MB, less than 68.66% of Python online submissions for First Unique Character in a String.
#### 复杂度分析：
 - 时间复杂度：$O(N)$
 - 空间复杂度：$O(N)$
#### 代码:
```Python
class Solution(object):

    def firstUniqChar(self, s: str) -> int:
        # 计算字符出现次数
        dic = {c: s.count(c) for c in set(s)}

        # 找到并返回首个满足出现次数为一的字符
        for i, c in enumerate(s):
            if dic[c] == 1:
                return i

        return -1

```