### 解题思路
首先我们按正常的思路找出二叉树的路径，之后再对有需要的节点做处理
如果最后一层是偶数层，那么需要对奇数层节点做处理
如果最后一层是奇数层，那么需要对偶数层节点做处理
对需要处理的节点，用这一层最左和最右节点的值的和减当前节点的值
这一层最左和最右节点的值的和为(2**i + 2**(i+1)) - 1，其中i为层数
### 代码

```python3
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        ans = []
        while label!=0:
            ans.append(label)
            label = label//2
        ans = ans[::-1]
        l = len(ans)
        if l%2==0:
            for i in range(2,l,2):
                ans[i] = (2**i + 2**(i+1)) - 1 - ans[i]
        else:
            for i in range(1,l,2):
                ans[i] = (2**i + 2**(i+1)) - 1 - ans[i]
        return ans
```