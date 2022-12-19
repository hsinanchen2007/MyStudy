### 解题思路
我的思路：层次遍历的迭代写法稍加改写，与题号【102】【107】类似。
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)

### 代码

```

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return None
        result = []
        cur_queue = [root]
        while cur_queue:
            next_queue = []
            cur_nums = 0
            sums = 0
            for node in cur_queue:
                if node:
                    sums += node.val
                    cur_nums += 1
                    next_queue.extend([node.left,node.right])
            if cur_nums:
                average = sums / cur_nums
                result.append(average)
            cur_queue = next_queue
        return result
            

```