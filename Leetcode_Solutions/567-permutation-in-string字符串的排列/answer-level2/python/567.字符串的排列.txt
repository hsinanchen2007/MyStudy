### 解题思路
1.获取s1中每个字符的出现次数并存入字典1
2.使用滑动窗口遍历s2的所有字符
2.1.如果字符在字典1中，窗口右边界向右移动一位，并将窗口内的每个字符出现次数存入字典2
2.2 如果字符在字典1中不存在，则清空窗口和字典2，并回到2
2.3 如果该字符在字典2出现次数超过字典1中的次数，窗口起始边界移动到该字符第一次出现位置的下一个字符
2.4 当字典1和字典2相同时，则找到子字符串

### 代码

```python
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        dic = {}
        dic_window = {}
        for chr in s1:
            dic.setdefault(chr, 0)
            dic[chr] = dic[chr] + 1

        window = ""
        for x in s2:
            if x in dic:
                dic_window.setdefault(x, 0)
                dic_window[x] = dic_window[x] + 1
                if dic_window == dic: 
                    return True
                else:
                    window += x
                    if dic_window[x] > dic[x]: 
                        window = window[window.find(x) + 1:]
                        dic_window.clear()
                        for w in window:
                            dic_window.setdefault(w, 0)
                            dic_window[w] = dic_window[w] + 1
            else:
                dic_window.clear()
                window = ""
        return False        
```