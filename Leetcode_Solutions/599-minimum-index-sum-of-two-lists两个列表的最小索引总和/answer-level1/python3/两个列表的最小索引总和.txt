### 解题思路-哈希表
1. 将`list1`转换成字典结构`list1_dict`：key：字符串；val：下标；
2. 遍历`list2`，其中存在于字典中的字符串存入另一个字典结构`res`中，其值为两个列表中的下标和；
3. 遍历`res`中的元素，将下标和最小的元素（`key`）存入返回结果中；

时间复杂度：`O(m+n)`；
空间复杂度：`O(n)`；

### 代码

```python3
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        if len(list1)*len(list2) == 0:
            return []
        list1_dict = dict()
        for i in range(len(list1)):
            list1_dict[list1[i]] = i
        
        res = dict()
        for i in range(len(list2)):
            try:
                res[list2[i]] = list1_dict[list2[i]] + i
            except:
                pass
        
        sum_index = float('inf')
        ans = []
        for key in res.keys():
            if res[key] < sum_index:
                ans = [key]
                sum_index = res[key]
            elif res[key] == sum_index:
                ans.append(key)
        return ans
```