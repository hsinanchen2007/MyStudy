### 解题思路
1、先对数组排序，sort()默认从小到大排
2、数组截取前k个，arr[:k]

内存消耗14.5MB，执行用时48ms
ps：期待更简单轻便的解法~~

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        return arr[:k]
```