#### 解题思路：

本文解法基于性质：二叉搜索树的中序遍历为 **递增序列** 。

将 二叉搜索树 转换成一个 “排序的循环双向链表” ，其中包含三个要素：

1. **排序链表：** 节点应从小到大排序，因此应使用 **中序遍历** “从小到大”访问树的节点；
2. **双向链表：** 在构建相邻节点（设前驱节点 $pre$ ，当前节点 $cur$ ）关系时，不仅应 $pre.right = cur$ ，也应 $cur.left = pre$ 。 
3. **循环链表：** 设链表头节点 $head$ 和尾节点 $tail$ ，则应构建 $head.left = tail$ 和 $tail.right = head$ 。

![Picture1.png](https://pic.leetcode-cn.com/5aed07658207b77c5c9ffbb5c054c1ac39df07ddd1e716d86f21a20a1ef66dd6-Picture1.png){:width=450}

- **中序遍历** 为 “左、根、右” 顺序，递归法代码如下：

```python []
# 打印中序遍历
def dfs(root):
    if not root: return
    dfs(root.left)  # 左
    print(root.val) # 根
    dfs(root.right) # 右
```

```java []
// 打印中序遍历
void dfs(TreeNode root) {
    if(root == null) return;
    dfs(root.left); // 左
    System.out.println(root.val); // 根
    dfs(root.right); // 右
}
```

- 根据以上分析，考虑使用中序遍历访问树的各节点 $cur$ ；并在访问每个节点时构建 $cur$ 和前驱节点 $pre$ 的引用指向；中序遍历完成后，最后构建头节点和尾节点的引用指向即可。

##### 算法流程：

**`dfs(cur):`** 递归法中序遍历；

1. **终止条件：** 当节点 $cur$ 为空，代表越过叶节点，直接返回；
2. 递归左子树，即 `dfs(cur.left)` ；
3. **构建链表：**
    1. **修改引用：** $pre.right = cur$ ， $cur.left = pre$ ；
    2. **保存 $cur$ ：** 更新 $pre = cur$ ，即节点 $cur$ 是后继节点的 $pre$ ；
4. 递归右子树，即 `dfs(cur.left)` ；

**`treeToDoublyList(root)：`**

1. **特例处理：** 若节点 $root$ 为空，则直接返回；
2. **伪头节点：** 由于递归时，首个节点 $cur$ 没有 $pre$ ，因此初始化一个伪头节点， $head$ 和 $pre$ 共同指向它；
3. **转化为双向链表：** 调用 `dfs(root)` ；
4. **构建循环链表：**
    1. 由于伪头节点指向头节点，因此执行 $head = head.right$ ，此时 $head$ 指向链表头节点。
    2. 中序遍历完成后， $pre$ 指向尾节点，因此构建 $head$ 和 $pre$ 的引用指向即可。

<![Picture2.png](https://pic.leetcode-cn.com/fb76253d314e57ba55f594a165a78a6a2652c8f1d82218b07bfe6460236ecc1e-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/c301ce5dbc002c4e7a8c1937a15227d3ba7ba3bb1e69db42a3e0cd23712f66cd-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/b50ce695b1b21244e9f7e30f986c2b2d9dfae41b31749cf7775ca00d837b2eab-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/e100cb438b44887fc1cf0830bc31e1733dbe1a02f2bee95ec3ce9d2937a1846a-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/52511ac203557ed278c3bf3a25f1b45196038f3ccf5377f21b74ce7777516e82-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/cc5762a5cba817021c399ea74e191e535e6586fa875f4d8677941829fe4283ed-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/633b37f71be71f52b83d8f30efee04dfdae14e452b018d3b67cfc55f8ff6f2a0-Picture8.png),![Picture9.png](https://pic.leetcode-cn.com/06373b554501099b981583646828cfcf76e069e9e5956a5172dfbefd1b52d8b0-Picture9.png),![Picture10.png](https://pic.leetcode-cn.com/33b74b99bd62372a67a8732a8c5cd3863178117ae14619e9efc9f8fc22930587-Picture10.png),![Picture11.png](https://pic.leetcode-cn.com/7d3957c479d064d4a918aa40303842d4ccd477ed770c40461987653316e8e6aa-Picture11.png),![Picture12.png](https://pic.leetcode-cn.com/da32c84386946464eafca2b2b87725969116d73c054b64c67821dc02e4fd1efb-Picture12.png),![Picture13.png](https://pic.leetcode-cn.com/538b053ffe7e92180f6af019789b8e329970b78098836597f62a6efe18d12a8e-Picture13.png),![Picture14.png](https://pic.leetcode-cn.com/2f4bee10fdf8a8f9c09d26e1c0cfa8889c5c9ee2138e189e35aa72de27bfa991-Picture14.png),![Picture15.png](https://pic.leetcode-cn.com/b5878bfb79123cd065afe06db6b78a7b9ca4e220db0d3be0cfa1bd88582ca08b-Picture15.png),![Picture16.png](https://pic.leetcode-cn.com/09eb275558869c439be43540355708e275039e03d114e8c1b3d19c817b637400-Picture16.png)>

##### 复杂度分析：

- **时间复杂度 $O(N)$ ：** $N$ 为二叉树的节点数，中序遍历需要访问所有节点。
- **空间复杂度 $O(N)$ ：** 最差情况下，即树退化为链表时，递归深度达到 $N$，系统使用 $O(N)$ 栈空间。

#### 代码：

```python []
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def dfs(cur):
            if not cur: return
            dfs(cur.left) # 递归左子树
            self.pre.right, cur.left = cur, self.pre # 修改引用
            self.pre = cur # 保存 cur
            dfs(cur.right) # 递归右子树
        
        if not root: return
        head = self.pre = ListNode(0) # 伪头节点
        dfs(root)
        head = head.right
        head.left, self.pre.right = self.pre, head
        return head
```

```java []
class Solution {
    Node pre = new Node(0), head = pre;
    public Node treeToDoublyList(Node root) {
        if(root == null) return null;
        dfs(root);
        head = head.right;
        head.left = pre;
        pre.right = head;
        return head;
    }
    void dfs(Node cur) {
        if(cur == null) return;
        dfs(cur.left);
        pre.right = cur;
        cur.left = pre;
        pre = cur;
        dfs(cur.right);
    }
}
```