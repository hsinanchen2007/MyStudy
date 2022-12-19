![image.png](https://pic.leetcode-cn.com/0db6eae70ab8b6a465dbe044383d4d657384d91b0ec9249074c04a6d2f61bd3c-image.png)

```
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        _station = 0
        if sum(gas) - sum(cost) < 0:
            return -1
        else:
            _sum = 0
            for i in range(len(gas)):
                if gas[i] - cost[i] < 0 and _sum == 0:
                    _station += 1
                    continue
                _sum += gas[i] - cost[i]
                if _sum < 0:
                    _sum = 0
                    _station = i+1
                    
            return _station
```
