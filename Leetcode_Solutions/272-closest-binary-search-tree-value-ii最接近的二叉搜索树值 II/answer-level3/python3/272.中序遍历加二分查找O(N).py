### 思路
先中序遍历，再利用[658.找到 K 个最接近的元素](https://leetcode-cn.com/problems/find-k-closest-elements/solution/)的方法套用即可。
### 代码
```
from typing import List
class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        tmp = []
        # 先进行中序遍历，得到有序数组
        def helper(root):
            if not root:
                return []
            helper(root.left)
            tmp.append(root.val)
            helper(root.right)
        helper(root)
        # 完全变成了658题找到K个最接近的元素
        n = len(tmp)
        left = 0
        right = n - k
        while left < right:
            mid = left + (right - left) // 2
            if target - tmp[mid] > tmp[mid + k] - target:
                left = mid + 1
            else:
                right = mid
        return tmp[left:left+k]
```
### 复杂度分析
- time:$O(n)$。658题部分利用了二分查找，时间复杂度为O(logN)，但是前面的先序遍历为O(n)，因为访问到了所有结点
- space:$O(n)$。使用数组存放结果
时间复杂度可惜还是$O(n)$,有没有大神分享$O(logN)$的python3解法啊
