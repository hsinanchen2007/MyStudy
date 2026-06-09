### 解题思路
首先将两数组对应位置的差保存在gas中，从正数开始尝试遍历相加，相加过程中若结果小于0，换从下一个正数开始，加到最后，若结果大于等于0 ，则返回这个正数的位置

### 代码

```python
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        if sum(cost) > sum(gas):return -1
        for i in range(len(gas)):
            gas[i] -= cost[i]
        for i in range(len(gas)):
            cur_sum = 0
            if gas[i] >= 0:
                for j in range(i,i + len(gas)):
                    cur_sum += gas[j % len(gas)]  #从gas[i]开始顺序将元素相加
                    if cur_sum < 0:break#过程中，若和小于0，则需要更换正数gas[i]
                if cur_sum >= 0:
                    return i
        return -1
```