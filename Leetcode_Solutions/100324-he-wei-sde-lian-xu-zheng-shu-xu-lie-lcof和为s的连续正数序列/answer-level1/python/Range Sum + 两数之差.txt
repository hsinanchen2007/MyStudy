### 解题思路
连续的和可以看成是range sum问题，那么求出所有的range sum。接下来的问题就是找出所有差为target的可能。

### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        mid = (target + 1) / 2
        sum_arrary = [0]
        sum = 0
        for i in range(1, mid + 1):
            sum += i
            sum_arrary.append(sum)

        sum_record = {}
        for i in range(mid + 1):
            sum_record[sum_arrary[i] + target] = i + 1
            if sum_arrary[i] in sum_record:
                result.append(range(sum_record[sum_arrary[i]], i + 1))
        return result

```