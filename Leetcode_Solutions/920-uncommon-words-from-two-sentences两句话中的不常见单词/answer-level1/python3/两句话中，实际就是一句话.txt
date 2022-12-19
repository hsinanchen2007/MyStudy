### 解题思路
题目说是两句话中不常见单词，其实就是一句话。
首先：把A中的单词提取放到字典中，再将B中的单词提取出放到字典中。字典的key是每个单词，value是单词出现的次数。
其次，遍历字典中的所有key，找到符合value==1的，加入到结果列表中。
最后，返回结果列表。
### 代码

```python3
class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :param A: 第一个句子
        :param B: 第二个句子
        :return: 返回所有不常用单词的列表
        """
        result = []
        d = {}
        for world_a in A.split(" "):
            d[world_a] = d.get(world_a, 0) + 1
        for world_b in B.split(" "):
            d[world_b] = d.get(world_b, 0) + 1
        for world in d:
            if d[world] == 1:
                result.append(world)
        return result
```