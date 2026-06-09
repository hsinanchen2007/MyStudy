采用官方思路，注意以下几点：
- hash字典的表示方式为：`{索引和:餐厅名称}`
- 如果有多个共同的名称，它们的索引和相同且恰好为最小，那么一个`key`对应多个`value`，故上面的`“餐厅名称”`需采用列表的数据结构，这样可实现一个`key`对应多个`value`
```
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        hash = {}
        for i in range(len(list1)):
            for j in range(len(list2)):
                if list2[j] == list1[i]:
                    if hash.get(i+j):
                        hash[i+j].append(list2[j])
                    else:
                        hash[i+j] = [list2[j]]
        min_key = len(list1) + len(list2)
        for k,value in hash.items():
            min_key = min(min_key,k)
        return hash[min_key]
```


![白色背景关注.jpg](https://pic.leetcode-cn.com/47d1b5430e869ed420bb0c6e8a90250773528ccf1bf6d4d43aef80dd326eeef9-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
