# 我搬砖我快乐
统计所有数字出现的次数, 得到一个哈希表(字典)D;   
将每一个数字出现的次数看作砖块的数量;   
![搬砖问题.png](https://pic.leetcode-cn.com/05a34ecaba454c8797a96e05fee636919ee0f5917506ebb25fda1b12a6421c84-%E6%90%AC%E7%A0%96%E9%97%AE%E9%A2%98.png)

设置一个搬运工worker, 他在数轴上的位置为i, 这个搬运工在数轴上前行, 每次走一步(i+1), 他的目标是沿着数轴往前走, 使所有数字的数量为1;   
设置变量cost: 表示当前位置iworker总共的体力消耗, 初始为0;   
设置变量burden: 表示当前位置worker身上砖块数量, 初始为0;   
设置visit: 统计访问过的数字的数量, 用于终止条件;

以最小数字开始, 在当前位置i, 砖块数量为d[i], 他进行如下操作:
    1. 计算体力消耗cost, 消耗等于他的负担burden乘以行走的步数, 也就是burden*1.
    2. 当前位置砖块数量d[i]
        3. if d[i] == 1: cotinue;          # 只有一块砖, 往前走
        3. elif d[i]>1: burden+=d[i]-1    # 将多余的砖背在身上, 只留下一块, 继续往前走;
        4. else: burden -=1 if burden>0 else 0  # 如果有负担, 则将身上的砖放下一块, 继续前行;
        i += 1      # 到下一个位置
    5. 最后, 访问了所有的数字, 且身上没有负担, 则结束, 返回cost;

```
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        d = {}
        L = len(A)

        # 使用AH统计每个数字出现的次数
        for e in A:
            d.setdefault(e,0)         
            d[e] += 1

        burden = 0
        cost = 0
        visit = 0
        i = 0
        while visit < L:
            d.setdefault(i, 0)
            visit += d[i]
            cost += burden
            burden += d[i]-1 
            burden = max(burden, 0)
            i += 1

        cost += (1+burden)*burden//2
        return cost      

        
```
