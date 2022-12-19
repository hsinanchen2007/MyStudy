
## 递归解法

### 思路
利用递归方法判断，先判断当前结点是否相等，如果相等，在判断左右子树是否相等。注意递归的结束条件。

### 代码实现
```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q ==nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

```

### 复杂度分析
 - 时间复杂度：O(n) 其中n是树的结点数，因为每个结点都访问一次。
 - 空间复杂度：最好情况，树是完成二叉树，递归的深度是log(n), 最坏情况，是完全不平衡二叉树，递归的深度为n， 用于维护递归栈


## 迭代解法

思路：利用广度优先遍历的方法，使用两个队列，分别把根结点加入队列。每次迭代中同时取出两个队列队首结点做以下操作
- 判断结点的值是否相等，如果不相等则不满足条件，返回false
- 如果结点的值相同，再比较结点左右孩子的结构，先比较左孩子
     1) 如果左孩子都不存在，满足条件
     2) 如果左孩子都存在，则把左孩子加入队列
     3) 如果只有其中各一个结点左孩子存储，不符合条件， 返回false
     4）用同样的方法比较右孩子
- 直到两个队列为空


### 代码实现
```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        // 有其中一个为空
        if (!p || !q) return false;

        queue<TreeNode *> p_queue;
        queue<TreeNode *> q_queue;

        p_queue.push(p);
        q_queue.push(q);
        while (!p_queue.empty() && !q_queue.empty()) {

            p = p_queue.front();
            q = q_queue.front();

            p_queue.pop();
            q_queue.pop();

            if (p->val != q->val) {
                return false;
            }

            // 左结点都存储
            if (p->left && q->left) {
                p_queue.push(p->left);
                q_queue.push(q->left);
            } else if (p->left || q->left) { // 只有一个结点的左结点存储，不符合
                return false;
            } else {
                // do nothing
            }

            // 右结点都存储
            if (p->right && q->right) {
                p_queue.push(p->right);
                q_queue.push(q->right);
            } else if (p->right || q->right) { // 只有一个结点的右结点存储，不符合
                return false;
            } else {
                // do nothing
            }
        }

        return true;
    }
};
```

### 复杂度分析
- 时间复杂度：O(n)，其中 n 是树的结点数，因为每个结点都访问一次
- 空间复杂度：最好情况，当树是完全不平衡二叉树时（每个结点最多只有一个孩子），在队列中最多只有一个结点，所以空间复杂度为O(1).最坏情况，当树是完成二叉树时，比较到最后一层时，队列中最多右n/2个结点。所以空间复杂度为O(n). 

空间复杂度分析与官方给的参考答案不一样，我觉得官方的不准确。