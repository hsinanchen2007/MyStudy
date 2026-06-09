# 解题思路：
遍历所有文档对，对每一对文档`(i, j)`，首先将`i`中的单词都放进哈希表中，然后统计`j`中单词在表中出现的次数。

# 复杂度分析：
- 时间复杂度：`O(n^2*m)`，`n`为文档数目，`m`为文档最大长度
- 空间复杂度：`O(m)`

# 注意事项：
在计算相似度时加了一个很小的正数1e-9，用来补偿精度

# 代码实现:
```
class Solution:
    def computeSimilarities(self, docs: List[List[int]]) -> List[str]:
        res = []
        for i in range(len(docs)):
            s = set(docs[i])
            for j in range(i+1, len(docs)):
                insec = 0
                for num in docs[j]:
                    insec += (num in s)
                if insec:
                    union = len(docs[i]) + len(docs[j]) - insec
                    res.append("{0:d},{1:d}: {2:.4f}".format(i, j, insec / union + 1e-9))
        return res 
```
