### 解题思路
1.将数组arr逆序排序
2.定义一个空数组
3.将排序后的数组的前k个元素放入定义的空数组中

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort(reverse = False)
        result = []
        for i in range(k):
            result.append(arr[i])
        return result
```