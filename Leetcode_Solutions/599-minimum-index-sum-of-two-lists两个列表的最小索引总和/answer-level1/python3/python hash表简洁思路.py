## 解题思路
题意重点: 最少的索引和, 共同喜爱的餐厅
1. 把输入的两个list转换成hash映射
2. 找出共同喜爱的餐厅,交集
3. 把交集的成员分别进行索引相加,找出最少的

## 代码实现
用了评论里的 SKX ,写法比我自己的优雅
```python
class Solution:
    def findRestaurant(self, list1, list2):
        map1 = {list1[i]: i for i in range(len(list1))} #转换hash
        map2 = {list2[i]: i for i in range(len(list2))} #转换hash
        inter = set(list1) & set(list2)                 #求交集
        sum_index = {i: map1[i] + map2[i] for i in inter} #交集成员索引求和
        return [val for val in inter if sum_index[val] == min(sum_index.values())] #找最少的索引和的成员
```