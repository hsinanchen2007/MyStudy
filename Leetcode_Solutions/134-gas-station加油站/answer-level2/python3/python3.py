```
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # 只有汽油数大于消耗的才能成为起点
        # 如果从起点开始，累计的汽油数要少于消耗的花费的话，就重置起点，起点为下一个点
        # 把上次起点到被更新的起点处汽油的净消耗，记入过去的机油净消耗
        # 如果从起点开始，到终点的汽油的净入大于过去的净消耗，该点就是起点
        if not gas: return -1
        sp = 0   # sp for staring_point
        net_gas_from_sp = 0
        net_gas_to_sp = 0
        for i in range(len(gas)):
            net_gas_from_sp += gas[i] - cost[i]
            if net_gas_from_sp < 0:
                net_gas_to_sp += net_gas_from_sp
                sp = i + 1
                net_gas_from_sp = 0
        return sp if net_gas_from_sp + net_gas_to_sp >= 0 else -1
```
