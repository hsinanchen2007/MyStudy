* 执行用时 : 40 ms, 在Two City Scheduling的Python3提交中击败了98.33% 的用户
* 内存消耗 : 12.9 MB, 在Two City Scheduling的Python3提交中击败了100.00% 的用户

```
class Solution:
    def twoCitySchedCost(self, costs):
        costs.sort(key=lambda x: (x[0]-x[1]))  # 计算去A地和去B低的费用差，然后按照费用差排序
        length_costs = len(costs)
        result = 0
        result += sum([i[0] for i in costs[:length_costs//2]])  # 前半部分去A地
        result += sum([i[1] for i in costs[length_costs//2:]])  # 后半部分去B地
        return result
```