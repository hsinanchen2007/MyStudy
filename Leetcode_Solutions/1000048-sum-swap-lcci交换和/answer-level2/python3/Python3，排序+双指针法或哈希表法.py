### 解题思路
假设两个数组之和的差为`x`，那么满足条件的两个元素`[a, b]`一定有`b - a = x/2`，那么有两个方法：
1. 先对两个数组进行排序，然后用双指针遍历找到答案，时间`O(Nlog(N))`，空间`O(1)`
2. 先由第一个数组创建哈希表，然后对第二个数组中每个元素`b`，查找`b-x/2`是否在哈希表中，时间`O(N)`，空间`O(N)`

### 代码

```python3
class Solution:
    def findSwapValues(self, array1: List[int], array2: List[int]) -> List[int]:
        x = sum(array2) - sum(array1)
        if x % 2 == 1:
            return []
        x /= 2
        # 方法1：时间O(Nlog(N))，空间O(1)
        '''
        i = j = 0
        array1.sort()
        array2.sort()
        while j < len(array2):
            if array2[j] - array1[i] == x:
                return [array1[i], array2[j]]
            elif array2[j] - array1[i] > x and i+1 < len(array1):
                i += 1
            else:
                j += 1
        return []
        '''
        # 方法2：时间O(N)，空间O(N)
        a = set(array1)
        for num in array2:
            if num - x in a:
                return [num - x, num]
        return []
```