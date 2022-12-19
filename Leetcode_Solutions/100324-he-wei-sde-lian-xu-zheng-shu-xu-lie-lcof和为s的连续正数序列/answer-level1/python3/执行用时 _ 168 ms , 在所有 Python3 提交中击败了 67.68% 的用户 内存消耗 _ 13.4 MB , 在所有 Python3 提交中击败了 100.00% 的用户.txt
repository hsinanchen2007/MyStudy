### 解题思路
连续正数序列为等差数列，和为cur =(low + high)*(high - low +1)/2,定义两个指针，low=1，high=2，当和>cur时low+=1,反之high+=1
### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        low = 1
        high = 2
        all_result = []
        while low < high:
            cur = (low + high)*(high - low +1)/2
            if cur < target:
                high += 1
            elif cur == target:
                all_result.append(list(range(low,high+1)))
                low +=1
            else:
                low +=1
        return all_result

```