
### 方法一：递归写法

实际上就是在做前序遍历，再根据对称性设计递归往下传递的树的子结点。


**参考代码 1**：

```Java []
class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }
}

public class Solution {
    boolean isSymmetrical(TreeNode pRoot) {
        if (pRoot == null) {
            return true;
        }
        return dfs(pRoot.left, pRoot.right);
    }

    private boolean dfs(TreeNode pRoot1, TreeNode pRoot2) {
        // 先写递归终止条件
        if (pRoot1 == null && pRoot2 == null) {
            return true;
        }

        // 如果其中之一为空，也不是对称的
        if (pRoot1 == null || pRoot2 == null) {
            return false;
        }
        // 以上是递归终止条件

        // 走到这里二者一定不为空
        if (pRoot1.val != pRoot2.val) {
            return false;
        }
        // 前序遍历
        return dfs(pRoot1.left, pRoot2.right) && dfs(pRoot1.right, pRoot2.left);
    }
}
```
```Python []
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        # 先写递归终止条件
        if root is None:
            return True
        return self.__helper(root.left, root.right)

    def __helper(self, p1, p2):
        if p1 is None and p2 is None:
            return True
        if p1 is None or p2 is None:
            return False

        # 以上是递归终止条件
        return p1.val == p2.val and self.__helper(p1.left, p2.right) and self.__helper(p1.right, p2.left)
```

**复杂度分析**：

+ 时间复杂度：$O(N)$，这里 $N$ 为树的结点个数，事实上这个递归方法就是在做树的遍历，每个结点访问一次；
+ 空间复杂度：$O(H)$，这里 $H$ 表示树的高度，系统栈需要 $H$ 长度的空间。


### 方法二：非递归写法（层序遍历）

+ 这个方法有点像层序遍历，故使用队列，但是根据对称性，队首和队尾其实都需要能够执行入队和出队操作，因此使用**双端队列（`Deque`）**；
+ Java 语言中 `Deque` 的实现类在这道题里不能选 `ArrayDeque`，因为该类的 `add` 方法会对添加的元素做非空检查。


**参考代码 2**：

```Java []
import java.util.Deque;
import java.util.LinkedList;

public class Solution {

    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }

        // 实现类不能选用 ArrayDeque，因为该类的 add 方法会对添加的元素做非空检查
        Deque<TreeNode> deque = new LinkedList<>();
        // Deque<TreeNode> deque = new ArrayDeque<>();

        deque.addFirst(root.left);
        deque.addLast(root.right);

        while (!deque.isEmpty()) {
            TreeNode leftNode = deque.removeFirst();
            TreeNode rightNode = deque.removeLast();

            if (leftNode == null && rightNode == null) {
                continue;
            }

            if (leftNode == null || rightNode == null) {
                return false;
            }

            if (leftNode.val != rightNode.val) {
                return false;
            }

            deque.addFirst(leftNode.right);
            deque.addFirst(leftNode.left);
            deque.addLast(rightNode.left);
            deque.addLast(rightNode.right);
        }

        return true;
    }
}
```
```Python []
from collections import deque


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True

        d = deque()
        d.appendleft(root.left)
        d.append(root.right)

        while d:
            left_node = d.popleft()
            right_node = d.pop()

            if left_node is None and right_node is None:
                continue

            if left_node is None or right_node is None:
                return False
            # 代码走到这里一定有 left_node 和 right_node 非空
            # 因此可以取出 val 进行判断了
            if left_node.val != right_node.val:
                return False
            d.appendleft(left_node.right)
            d.appendleft(left_node.left)
            d.append(right_node.left)
            d.append(right_node.right)
        return True
```

**复杂度分析**：

+ 时间复杂度：$O(N)$，这里 $N$ 为树的结点个数，事实上这个递归方法就是在做树的遍历，每个结点访问一次；
+ 空间复杂度：$O(L)$，这里 $L$ 表示树的相邻两层结点个数之和的最大值。