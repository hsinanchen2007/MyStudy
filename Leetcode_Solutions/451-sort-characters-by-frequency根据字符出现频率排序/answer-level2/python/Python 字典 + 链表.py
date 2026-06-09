### 解题思路
Python 字典 + 链表 ， 字典用来记录字符中每个单词出现的频率， 链表用来根据词频进行排序， 排序时需要自定义比较函数
时间复杂度 O(nlogn) 空间复杂度 O(n)

### 代码

```python
class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        def func(elem): # 自定义比较函数
            return elem[1]

        d = {}
        for c in s: # 记录词频
            if c not in d:
                d[c] = 1
            else:
                d[c] += 1
        l = sorted(d.items(), key=func, reverse=True) # 根据词频进行排序
        res = []
        for i in l:
            res.append(i[0] * i[1]) # 根据词频生成相应数量的单词
        return "".join(res)
    
```