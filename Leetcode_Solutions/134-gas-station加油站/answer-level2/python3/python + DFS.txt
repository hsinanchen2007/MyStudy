```python
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # Greedy method
        arr_l = len(gas)
        def traverse(start, index, now_gas):
            if index == start: return 1
            now_gas += gas[index] - cost[index]
            if now_gas < 0: return now_gas
            else: return traverse(start, (index + 1) % arr_l, now_gas)
        pre = 0
        for i in range(len(gas) - 1, -1, -1):
            if gas[i] - cost[i] < pre: 
                pre -= gas[i] - cost[i]
                continue
            rest = traverse(i, (i + 1) % arr_l, gas[i] - cost[i])
            if rest >= 0: return i
            else: pre = -rest
        return -1
```