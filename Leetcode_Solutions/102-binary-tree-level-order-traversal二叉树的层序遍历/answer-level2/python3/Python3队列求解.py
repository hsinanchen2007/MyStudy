首先因为是层次遍历，也就是广度优先搜索，所以直接使用队列求解；
第二点在于由于每一行的结果要单独放在一个列表里面，所以需要额外的信息来记录当前遍历到的节点的层数，当正在遍历的节点的层数和上一个遍历的节点的层数不一样时，加入到最终结果然后层数加一；
最后就是当最后一个节点被遍历到时，此时队列已经为空，因此需要在每次循环后判断队列是否为空，然后加入最后一行的答案。
```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        result = []; level = 0
        queue = []; queue.append((root, level))
        cu_res = []
        while len(queue):
            this = queue[0]; del queue[0]
            if this[1] != level:
                level += 1
                result.append(cu_res)
                cu_res = []
            if this[0].left != None:
                queue.append((this[0].left, level+1))
            if this[0].right != None:
                queue.append((this[0].right, level+1))
            cu_res.append(this[0].val)
            if not len(queue):
                result.append(cu_res)
        return result
```
