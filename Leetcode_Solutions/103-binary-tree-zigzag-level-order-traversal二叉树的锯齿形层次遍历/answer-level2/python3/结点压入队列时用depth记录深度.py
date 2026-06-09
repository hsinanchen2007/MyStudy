### 解题思路
用队列que保存下一个应该遍历的（结点、结点的深度）
```
que.append((cur.left, depth+1))
que.append((cur.right, depth+1))
```
用另一个队列ans保存输出
当ans的深度小于当前结点的深度，为ans增添新列表。否则直接在末尾添加：

```
if len(ans)==depth:
    ans[depth-1].append(cur.val)
else:
    ans.append([cur.val])
```
最后逢奇数行倒序之。
好久没写前4%的答案了纪念一下~~
### 代码
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        depth = 1
        ans = []
        que = [(root, depth)]
        while que:
            cur, depth = que.pop(0)
            if cur:
                if len(ans)==depth:
                    ans[depth-1].append(cur.val)
                else:
                    ans.append([cur.val])
                que.append((cur.left, depth+1))
                que.append((cur.right, depth+1))
        ans = [ans[i][::-1]  if i&1==1 else ans[i] for i in range(len(ans))]
        return ans
``````
