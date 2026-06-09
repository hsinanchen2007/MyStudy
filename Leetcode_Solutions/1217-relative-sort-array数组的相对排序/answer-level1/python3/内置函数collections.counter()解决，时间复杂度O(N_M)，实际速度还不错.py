
```python []
import collections

class Solution:
    def relativeSortArray(self, arr1, arr2):
        cur = []
        hashmap = collections.Counter(arr1)
        for i in arr2:
            for j in range(a[i]):
                cur.append(i)
                arr1.remove(i)
        return cur + sorted(arr1)

```
使用内置函数counter获取arr1中每个数字的个数，遍历arr2，得到的每个数字在字典中匹配，cur添加相应个数的当前数字，arr1中剔除所有该数字。
最后加上剔除后的arr1即可