原地操作，时间复杂度$O(N)$，额外空间复杂度$O(1)$
将路径数组转换为距离数组
生成距离数组的时候，值设置为负数，可以标记状态
路径转成距离数组的过程中，每一个城市只经历跳出去和跳回来两个过程，
整个过程没有使用额外的数据结构，只使用了有限几个变量，所以额外空间复杂度为O（1）

![image.png](https://pic.leetcode-cn.com/c4257c91e493472d661f97e08be18e494609bb5d316417354a3b47eaaa53ce92-image.png)


参照了左神[路径数组变为统计数组](https://weread.qq.com/web/reader/1be32b907184877a1be90a2k1ff321e02ac1ff8a7b5d0fc)
本题只需计算距离，无需统计，是要**求最大距离**

不行了，折磨我自己，我现在脑袋一片浆糊，要口胡了......

```
class Solution(object):
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        for i in range(n):
            if manager[i] >= 0:
                pre_idx = -1
                cur_idx = i
                # 向上级跳
                while manager[cur_idx] >= 0:
                    next_idx = manager[cur_idx]
                    manager[cur_idx] = pre_idx
                    pre_idx = cur_idx
                    cur_idx = next_idx
                # 向下级跳
                tmp = pre_idx
                pre_idx = cur_idx
                cur_idx = tmp
                while manager[cur_idx] >= 0:
                    next_idx = manager[cur_idx]
                    if pre_idx != headID:
                        manager[cur_idx] = manager[pre_idx] - informTime[cur_idx]
                    else:
                        manager[cur_idx] = -informTime[headID] - informTime[cur_idx]
                    pre_idx = cur_idx
                    cur_idx = next_idx
                if pre_idx != headID and cur_idx != -1:
                    manager[cur_idx] = manager[pre_idx] - informTime[cur_idx]
                else:
                    manager[cur_idx] = -informTime[headID] - informTime[cur_idx]
        manager[headID] = -informTime[headID]
        max_time = 0
        for i in range(n):
            if manager[i] < max_time:
                max_time = manager[i]
        return -max_time
```

