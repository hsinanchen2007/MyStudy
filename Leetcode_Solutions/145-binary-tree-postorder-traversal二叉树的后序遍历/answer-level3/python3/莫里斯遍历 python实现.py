#### 同前序遍历的思想一致，再加上题解中的逆序输出即可完成后序遍历
>**需要建立一个临时节点，并令该节点的左子节点为root**，
>
>1. 如果当前节点的左子节点为空时，则将其右子节点作为当前节点
>2. 如果当前节点的左子节点不为空，找到当前节点左子树的最右节点（该节点为当前节点中序遍历的前驱节点）
>           1. 如果最右节点的右指针为空，将最右节点的右指针指向当前节点，当前节点置为其左子节点
>           2. 如果最右节点的右指针不为空，将最右节点右指针重新置为空(恢复树的原状)，倒序输出从当前节点的左子节点到该最右节点路径上的所有节点，并将当前节点置为其右节点
>
>   3. 重复1，2，直到当前节点为空

```python3
def postorderTraversal(root):
    dumy = TreeNode(-1)
    dumy.left = root
    node = dumy
    ret = []
    while node:
        if not node.left:
            node = node.right
        else:
            predecessor = node.left
            while predecessor.right and predecessor.right is not node:
                predecessor = predecessor.right
            if not predecessor.right:
                predecessor.right = node
                node = node.left
            else:
                predecessor.right = None
                tmp = node.left
                part = []
                while tmp: #从左子节点遍历到最右节点
                    part.append(tmp.val)
                    tmp = tmp.right
                ret.extend(part[::-1]) #逆序输出
                node = node.right
    return ret
```
##### 复杂度
时间复杂度$O(n)$ 空间复杂度$O(1)$

