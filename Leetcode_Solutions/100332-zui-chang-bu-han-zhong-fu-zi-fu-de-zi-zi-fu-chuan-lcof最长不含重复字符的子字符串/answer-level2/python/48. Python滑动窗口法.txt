### 解题思路
这道题是很典型的滑动窗口法，定义两个指针p, q，当q指针指向的字符不存在于窗口中的时候q指针移动，否则左指针移动直到左指针指向的字符与右指针指向的字符相同，用哈希表可以作为存储窗口内元素的数据结构。

### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        if length == 0:
            return 0
        p = q = 0
        wind_set = set()
        max_size = 0
        temp_size = 0
        while q < length:
            # 右指针移动
            while q < length:
                ch = s[q]
                if ch not in wind_set:
                    wind_set.add(ch)
                    temp_size += 1
                    if temp_size > max_size:
                        max_size = temp_size
                    q += 1
                else:
                    break
            # 左指针移动
            if q < length:
                while s[p] != s[q]:
                    wind_set.remove(s[p])
                    temp_size -= 1
                    p += 1
                wind_set.remove(s[p])
                temp_size -= 1
                p += 1
        return max_size
```