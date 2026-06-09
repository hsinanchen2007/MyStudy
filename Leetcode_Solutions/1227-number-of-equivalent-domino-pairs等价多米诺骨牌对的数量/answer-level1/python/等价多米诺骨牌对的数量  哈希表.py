### 解题思路
考虑到字典键值不能为列表，因此将列表内的元素组合成字符串进行存储

### 代码

```python
class Solution(object):
    def numEquivDominoPairs(self, dominoes):
        dic = {}
        for c in dominoes:
            str_c = "".join(map(str,c))
            if str_c not in dic:
                if str_c[::-1] not in dic:
                    dic[str_c] = 1
                else:
                    dic[str_c[::-1]] += 1
            else:
                dic[str_c] += 1
        count = 0
        for c in dic:
            count += 1.0*dic[c]*(dic[c]-1)/2
        return int(count)
```