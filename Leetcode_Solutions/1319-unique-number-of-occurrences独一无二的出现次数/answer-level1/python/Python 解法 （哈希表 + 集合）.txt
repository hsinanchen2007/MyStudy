### 思路
既然题目问是不是所有元素出现的频率都不一样，

那么我们就先统计出每个元素出现的频率，

然后用一个集合存已经出现过的频率，

如果有多个频率重复出现，则应该返回`False`。

### 代码实现
```python [-Python]
class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        from collections import Counter
        
        dic = Counter(arr)
        
        s = set()
        for key, val in dic.items():
            if val in s: #当前频率已经出现过
                return False
            s.add(val)
        return True
```

### 复杂度分析

时间复杂度：$O(N)$
空间复杂度：$O(N)$