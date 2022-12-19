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
- [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/er-cha-shu-xi-lie-116-tian-chong-mei-ge-jie-dian-d/)
- [199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/tree-bfs-199-er-cha-shu-de-you-shi-tu-python3-bfs-/)
- [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/solution/er-cha-shu-xi-lie-200-dao-yu-shu-liang-python3-bfs/)
- [863. 二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/solution/tree-bfs-863-er-cha-shu-zhong-suo-you-ju-chi-wei-k/)



### BFS
指路：
[102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/) 的题解


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
- 空间复杂度：`O(m)`
  我们需要用辅助的队列来存放树的一部分节点，m为树中每一层节点个数的最大值


### Follow up
![image.png](https://pic.leetcode-cn.com/49a6362d8662c5c421eaf3cbcd96c3634c8bab58ee505dc6862edb2794fdce44-image.png)

对于层次遍历，我们用了额外的数组空间，去保存每一层的节点，那么如何优化，来满足我们只用`constant extra space`的常数级空间复杂度呢？

指路：
[116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/er-cha-shu-xi-lie-116-tian-chong-mei-ge-jie-dian-d/) 的题解
**116题**的树是完全二叉树，所以非叶子节点就一定有左右孩子，但是**117题**就不一定了，我们不再知道每个节点的孩子情况，那么似乎**116题**里的解题方法就不再有用了【不是似乎，虽然有可能可以，但是麻烦到不想去思考。。。】放在这里图个吉利吧~

但是我们能通过116题有一个大概的概念，我们依然是要**通过n-1层实现对n层的连接**，在遍历上一层的时候就把下一层连接了，只是连接的方式不再是用左右子树的关系，而是我们需要新建一个`dummy node`来指向每一层的首节点，因为有可能第一层的首节点并不是上一层首节点的左孩子，所以用`dummy_node.next来保存首节点`，然后遍历的时候用一个`tail = dummy`节点来遍历:
`dummy用于更新每一层，tail用于遍历每一层`

![image.png](https://pic.leetcode-cn.com/4c57a4a8662b4dc3bad2ddc196fe8f9e9c461975cda14ab381b81b144535b4a2-image.png)

然后在遍历当前层的时候，之前是通过直接设定左右子树的连接关系实现，现在需要先判断了，要是当前节点有左子树或右子树：`if node.left/if node.right`，那么把这个点接在`tail`的后面，然后`tail`更新：`tail.next = node.left/right, tail = tail.next`：

![image.png](https://pic.leetcode-cn.com/03aaf2cf5591f2cbf0ed144593a684855beb6b93a5743162a4d7d6bddceb62a3-image.png)

### 代码：
```python3
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        
        cur = root
        while cur:
            dummy = Node()  '''用来指向每一层的首节点'''
            tail = dummy  '''用来遍历每一层，实现连接功能'''
            while cur:
                '''如果node有左右子树，就连接在tail后面，并更新tail'''
                if cur.left:
                    tail.next = cur.left
                    tail = tail.next
                if cur.right:
                    tail.next = cur.right
                    tail = tail.next
                if not cur.next:
                    tail.next = None
                cur = cur.next

            # 更新下一层
            cur = dummy.next
        return root
```


### 复杂度
`n`是树的节点个数

- 时间复杂度：O(n)
  我们遍历了所有节点
- 空间复杂度：O(1)
  通过`dummy node和tail的遍历和更新`，我们没有使用额外空间


