### 解题思路
其实还是排序或者统计
排序就是利用asc或者字典序排列比较
统计就是dict或者count比较元素和数量

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #return True if list(s).sort()==list(t).sort() else False
        return True if sorted(s)==sorted(t) else False
```