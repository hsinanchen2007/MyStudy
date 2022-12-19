### 解题思路
一般能想到的暴力方法其时间复杂度是大于O(N)的，原因在于，其遍历每个元素时都要再向后查找第一个比它大的元素，而多次重复向后查找没有充分利用之前的信息，比如T = [3, 4, 1, 2, 5]，在对4和1进行查找的时候他们都遍历了[2, 5]元素，所以我们通过某种方法将该重复信息记录下来，我们可以通过倒序遍历数组来，这样就可以利用当前元素右边的信息。

### 代码

```python
class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        length = len(T)
        if length == 0:
            return []
        res = [0] * length
        for i in range(length - 2, -1, -1):
            j = i + 1
            while res[j] != 0 and T[j] <= T[i]:
                j += res[j]
            res[i] = j - i if T[j] > T[i] else 0
        return res
```