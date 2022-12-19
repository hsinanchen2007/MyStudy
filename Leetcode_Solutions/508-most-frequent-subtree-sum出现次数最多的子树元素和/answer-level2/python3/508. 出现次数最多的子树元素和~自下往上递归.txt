### 解题思路
每个节点的子树元素和 == 当前节点的元素值 + 左右节点的子树元素和
**看图**
![image.png](https://pic.leetcode-cn.com/7b8d25e28f7448cc0ab92a19b01548691684f21a1d11f773e6436113512fcf4f-image.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        from collections import defaultdict
        cnt = defaultdict(int)

        def find_sum(root):
            if root is None:
                return 0
            cur_val = root.val

            cur_val += (find_sum(root.left) + find_sum(root.right))

            cnt[cur_val] = cnt.get(cur_val, 0) + 1 
            return cur_val

        find_sum(root)
        # 根据子树元素和出现的次数进行对字典进行排序
        sorted_cnt = sorted(cnt.items(), key=lambda x: -x[1])
        
        # 可能出现子树元素和出现的次数相同
        ans = [sorted_cnt[i][0] for i in range(len(sorted_cnt)) if sorted_cnt[0][1] == sorted_cnt[i][1]]
        return ans
```