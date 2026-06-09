![image.png](https://pic.leetcode-cn.com/c39ce601e815669c0f72aba36f421b386ca3c1ec9e83510fe548d03da73c4294-image.png)


```

'''
先求所有子树的节点和，构成节点和列表
然后就是一个一元二次方程求极值问题，二分法找最接近对称轴的位置
'''
from typing import List
import bisect
class Solution:

    # 后续遍历
    def dfs(self, root: TreeNode, sum_list: List[int]):
        if root is None:
            return 0

        ans = root.val + self.dfs(root.left, sum_list) + self.dfs(root.right, sum_list)
        sum_list.append(ans)
        return ans

    def maxProduct(self, root: TreeNode) -> int:
        sum_list = []
        total_sum = self.dfs(root, sum_list)
        sum_list.sort()

        # 二分法找所有子树总和中最接近total_sum一半的一个，这样构造出来的两个子树和的乘积才可能是最大的
        target = total_sum // 2
        idx = bisect.bisect_left(sum_list, target)

        ans = sum_list[idx] * (total_sum - sum_list[idx])
        if idx >= 1:
            ans = max(ans, sum_list[idx-1] * (total_sum - sum_list[idx-1]))

        return ans % 1000000007
```
