> 题目来源：力扣（LeetCode）
> **[更新链接](https://www.zhangjc.site/leetcode-1094-car-pooling/)：https://www.zhangjc.site/leetcode-1094-car-pooling/**

这道题目的模型其实很简单，可以理解为**动态维护一个有限的容器**（例如堆栈等计算资源）。

而按照题意直接进行解答的思路当然就如下：

对每一个计划，需要执行一次遍历，更新当前所有位置上的状态并判断。
此时解决问题的复杂度与计划数量及计划区间成正比，显然 weak scalable。

一个比较高效的思路是：将行程信息预处理，这样可以**得知在每一站的使用量净值变化**（充分利用该问题的离散特点）。这样在预处理后的复杂度将只和站数有关。（对应于资源使用量可以进行动态监测而不会产生较大的性能波动）

下面是一份简单的python3实现代码。

```python3
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        records = [0]*1001
        for (num, start, dest) in trips:
            records[start] += num
            records[dest] -= num
        curNum = 0
        for record in records:
            curNum += record
            if curNum > capacity:
                return False
        return True
```
###### 假设起点与终点距离为$L$且该问题离散处理，显然复杂度为：$O(len(trips)) + O(L)$。