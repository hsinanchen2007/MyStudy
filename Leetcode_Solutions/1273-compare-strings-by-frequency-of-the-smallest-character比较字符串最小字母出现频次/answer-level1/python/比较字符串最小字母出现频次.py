### 解题思路
字符与ASCII的相互转换，map函数

### 代码

```python
class Solution(object):
    def numSmallerByFrequency(self, queries, words):
        #map(fuction,iterable...)内置函数
        r1 = []
        r2 = []
        ans = []
        for c in queries:
            r1.append(c.count(chr(min(map(ord,c)))))  #通过map、ord函数找到ASCII最小，再利用chr函数恢复字母，然后用count计数
        for d in words:
            r2.append(d.count(chr(min(map(ord,d)))))
        for i in range(len(r1)):
            j = 0
            count = 0
            while j < len(r2):
                if r1[i] < r2[j]:
                    count += 1
                j += 1
            ans.append(count)
        return ans
```