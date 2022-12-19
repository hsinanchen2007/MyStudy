

1. 要动态地维护一个当前最长字符串                tmpstr
2. 要判断重复，肯定需要一个集合                  dupset
2. 遍历过程中要维护一个最大长度                  length
3. 遇到重复元素时，要把靠前的部分去掉重新算字符串,要获取元素的位置标号
4. 一次遍历结束，时间复杂度O(n)




```
伪代码

    定义函数
        准备数据结构
        遍历
            未遇重复则：
                字符串生长
                集合增加
            遇重复：
                字符串截断，保留后半部分，
                集合重新生成
            最大长度遍历到每一个元素都要计算
        返回最大长度
```



翻译成Python

```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        tmpstr = ''
        dupset = set()
        length = 0

        for i in s:
            if not i in dupset:
                dupset.add(i)
                tmpstr += i
            else:
                cut_index = tmpstr.index(i)+1
                tmpstr = tmpstr[cut_index:] + i
                dupset = set(tmpstr)
            length = max(length, len(dupset))
            
        return length
        

```
