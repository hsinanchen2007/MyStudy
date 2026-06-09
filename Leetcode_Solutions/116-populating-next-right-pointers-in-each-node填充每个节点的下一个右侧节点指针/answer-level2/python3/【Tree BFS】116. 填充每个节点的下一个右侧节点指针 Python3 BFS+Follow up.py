### 解题思路
- 相似题型
- BFS
- **Follow up**
- 代码
- 复杂度

### 相似题型
- [102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/)
- [107. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/solution/er-cha-shu-xi-lie-107-er-cha-shu-de-ceng-ci-bian-l/)
- [103. 二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-xi-lie-103-er-cha-shu-de-ju-chi-xing-ce/)
- [637. 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/solution/er-cha-shu-xi-lie-637-er-cha-shu-de-ceng-ping-jun-/)
- [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/er-cha-shu-xi-lie-111-er-cha-shu-de-zui-xiao-shen-/)
- [117. 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/er-cha-shu-xi-lie-117-tian-chong-mei-ge-jie-dian-d/)
- [199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/tree-bfs-199-er-cha-shu-de-you-shi-tu-python3-bfs-/)
- [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/solution/er-cha-shu-xi-lie-200-dao-yu-shu-liang-python3-bfs/)
- [863. 二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/solution/tree-bfs-863-er-cha-shu-zhong-suo-you-ju-chi-wei-k/)



### BFS
指路：[102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/) 的题解

**重点**：`树即为directed graph`，层次遍历就可以用`Breadth Search First`完成

**区别**：对于每一层的节点，我们不再保存值，而是遍历将`[A,B,C,D]`这样的一层节点依次附上`next`指向，即为`A->B->C->D->None`

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        
        queue = [root]  # 保存下一层的节点
        
        while queue:
            nxt = []
            for i in range(len(queue)):
                '''依次用next指向同层下一个节点'''
                if i == len(queue)-1:
                    queue[i].next = None
                else:
                    queue[i].next = queue[i+1]
            
                if queue[i].left:
                    nxt.append(queue[i].left)
                if queue[i].right:
                    nxt.append(queue[i].right)
                    
            queue = nxt  # 每次更新queue
            
        return root
        
```

### 复杂度
`n`是树的节点个数
- 时间复杂度：`O(n)`
  我们遍历了所有节点
- 空间复杂度：`O(n)`
  这是一棵完美二叉树，它的最后一个层级包含 `n/2` 个节点。广度优先遍历的复杂度取决于一个层级上的最大元素数量。这种情况下空间复杂度为 `O(n)`。

```python3
'''
如果是二叉树，空间复杂度是一层最大节点数O(m)
如果是完美二叉树，那么最后一层的节点数是n/2，那么空间复杂度是O(n）
'''
```




### Follow up
![image.png](https://pic.leetcode-cn.com/49a6362d8662c5c421eaf3cbcd96c3634c8bab58ee505dc6862edb2794fdce44-image.png)

对于层次遍历，我们用了额外的数组空间，去保存每一层的节点，那么如何优化，来满足我们只用`constant extra space`的常数级空间复杂度呢？

如果我们不再能用一个队列保存一行的节点，那么我们一定要利用树的左右子树的特性将左右子树连接起来：即为对于每一个节点，我都能实现`node.left.next = node.right`的连接，也就是如图蓝色的箭头：
![image.png](https://pic.leetcode-cn.com/80783aeef0c42da423bf011b38a2a599bdb826c470e63ee08bfe6cca89696de0-image.png)

这个蓝色的箭头的实现，能够看出我们是**通过n-1层实现对n层的连接**，那么我们实际上就是在**遍历上一层的时候连接下一层**，这样层次增加的时候，我们当前层依然能用`.next`的方式遍历全部的节点，那么对于我们的`while`循环条件，即为`while root.left`，这里的root指代每一层的第一个节点，只要第一个节点有左孩子，我们就继续循环

那么对于图中红色部分的箭头，应该怎么实现呢？我们依然是利用树的左右孩子，因为这是一棵完全二叉树，那么每个节点都有它的左右孩子，那么对于一对左右孩子来说，我们可以通过`left_node.right.next = right_node.left`来实现，而我们又在这之前已经获得了`node.left.next = node.right`，也就是`right_node = left_node.next`，那么我们就可以得到：
```
left_node.right.next = right_node.left
--> node.right.next = node.next.left
```

**小trick：** 对于树的层级的判断，一定要判断到上一层
也就是如果我们要用到`node.right.next = node.next.left`，那么前提是我们一定要判断到`if node.right and node.next`，又由于我们的循环条件是`while root.left`，完全二叉树就一定有对应的右孩子，那么这里的条件就可以简化为：`if node.next`

那么整体的遍历过程就是：
从每一层的第一个节点开始【这个点就是`root.left, root=root.left`，通过左子树不断的向下】，只要`if node`，那么`node.left.next = node.right`，如果还有`if node.next`，那么就可以继续连接：`node.right.next = node.next.left, node = node.next`


### 代码
```python3
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root or not root.left:
            return root
        root.next = None
        
        res = root
        
        while root.left:
            tmp = root

            while tmp:
                tmp.left.next = tmp.right
                if tmp.next:
                    tmp.right.next = tmp.next.left
                else:
                    tmp.right.next = None
                tmp = tmp.next
            root = root.left
            
            '''
            上面的代码块等价于下面注释掉的代码块
            从侧面也能说明，while嵌套while的时间复杂度也能是O(n)，因为总体我们也只遍历了全部节点
            '''
        #  while tmp.left:
        #     if tmp.left:
        #         tmp.left.next = tmp.right
        #     if tmp.next:
        #         tmp.right.next = tmp.next.left
        #         tmp = tmp.next
        #     else:
        #         tmp.right.next = None
        #         root = root.left
        #         tmp = root  更新tmp放在这里，而不能放在while内第一行
        return res
```

### 复杂度
`n`是树的节点个数
- 时间复杂度：`O(n)`
  我们遍历了所有节点
- 空间复杂度：`O(1)`
  通过使用了树的`left，right，next`特性，我们没有使用额外空间