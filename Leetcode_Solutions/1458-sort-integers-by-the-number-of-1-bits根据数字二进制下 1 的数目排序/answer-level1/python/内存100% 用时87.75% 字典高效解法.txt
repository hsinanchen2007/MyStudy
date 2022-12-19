### 解题思路
将每个数的位置对应一个2进制含1的个数（不能用数作为键，因为arr中可能有重复的数）然后排序即可

### 代码

```python3
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        adict = {}
        result = []
        for i in range(len(arr)):
            adict[i] = bin(arr[i]).count("1")
        list1=sorted(adict.items(),key = lambda x: (x[1],arr[x[0]]))
        for i in list1:
            result.append(arr[i[0]])
        return result
```