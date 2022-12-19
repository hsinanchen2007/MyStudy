### 解题思路
利用collections模块中的counter(),most_common()方法

### 代码

```python3
class Solution:
    def frequencySort(self, s: str) -> str:
        lis =  collections.Counter(s).most_common()
        strs = ''
        for i,j in lis :
            strs += i*j
        return strs


```