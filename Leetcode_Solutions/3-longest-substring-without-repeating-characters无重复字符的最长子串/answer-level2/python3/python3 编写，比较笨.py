### 解题思路
记录一下

### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 使用一个 List 按序保存每个字符，把 List 当做是一个滑动窗口
        strList = []
        # unrepeatNumTemp 保存当前遍历过的不重复字符串长度
        # unrepeatNumResult 保存最终的字符串长度
        unrepeatNumResult, unrepeatNumTemp = 0, 0

        for value in s:
            # 如果当前字符在 List 中存在，
            if value in strList:
                # 获取到 value 的索引号，保留 value 后面的数据
                # 这个索引号其实就是新的滑动窗口的左边
                # 例如 [abcdb] 当遍历最后一个 b 的时候，此时滑动窗口是 [0:3] ，然后获取到b的索引是1，滑动窗口就是 [2:end]
                index = strList.index(value)
                # 先记录当前的长度是多少
                if unrepeatNumTemp > unrepeatNumResult:
                    unrepeatNumResult = unrepeatNumTemp
                # 利用切片机制来模拟滑动窗口移动
                strList = strList[index + 1 :]
                # 再把最新的值追加到滑动窗口中
                strList.append(value)
                # unrepeatNumTemp 赋值为当前 list 的长度，因为里面还是不重复的
                unrepeatNumTemp = len(strList)
            else :
                strList.append(value)
                unrepeatNumTemp = unrepeatNumTemp + 1
        # 遍历完成后如果都没有重复的，就直接赋值
        if unrepeatNumTemp > unrepeatNumResult:
            unrepeatNumResult = unrepeatNumTemp
        return unrepeatNumResult
```