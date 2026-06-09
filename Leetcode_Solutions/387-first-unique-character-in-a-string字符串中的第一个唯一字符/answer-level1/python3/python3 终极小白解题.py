### 解题思路
1、遍历字符串s, 将字符串的每一个字符存入字典
    - 字典的key为每一个字符，value为一个列表，存2个值，一个为当前字符出现的次数，另一个为第一次出现该字符的索引
2、设置一个变量来存储当前第一个唯一的字符的索引, 初始值为正无穷大float('INF')
3、遍历字典:
    - 当字典中的value中的次数等于1时，便拿出当前索引与min_index进行比较，谁小，则min_index就为谁
4、最后当min_index仍然为无穷大，则没有唯一字符，返回-1

ps:
    做题时，我出现过的问题
    在第一次遍历的时候，当出现重复字符时，为什么没有将其从字典中删除?
        因为将其删除后，后面又出现该字符时，就会使得字典又将其存储一遍，此时便会导致结果出错

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        size = len(s)
        dict = {}
        for i in range(size):
            if s[i] in dict:
                dict[s[i]][0] += 1
            else:
                dict[s[i]] = [1, i]
        min_index = float('INF')
        for key in dict:
            if dict[key][0] == 1:
                min_index = dict[key][1] if dict[key][1] < min_index else min_index
        if min_index == float('INF'):
            return -1
        return min_index
            
```