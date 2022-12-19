## 解法：递归

要判断一个二叉树是否是对称的，只需要判断其左子树和右子树是否为镜像即可。最简单的方法是采用递归实现。

* 声明两个指针`point1`和`point2`分别指向当前根节点的左子树和右子树；

* 如果两个指针`point1`和`point2`指向的节点的值相等，则递归比较

  * `point->left`和`point->right`；
  * `point->right`和`point->left`。

  只有当上述两个比较同时返回`true`时，才能说明对称。

* 递归的终止条件为：

  * 两个指针同时为`nullptr`，则返回`true`；
  * 两个指针只有一个为空，则返回`false`;
  * 两个指针都不为空，且值不相等，则返回`false`。

在进行递归终止条件的判断时，要灵活应用`||`运算符的短路特性。具体代码如下所示：

```c++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isSymmetricCore(root->left, root->right);
    }

    bool isSymmetricCore(TreeNode* root1, TreeNode* root2){
        if (root1 == nullptr && root2 == nullptr){
            return true;
        } else if (root1 == nullptr || root2 == nullptr || root1->val != root2->val){
            // 只有一个节点为null 或 两个节点的值不相等时
            return false;
        }
        
        return isSymmetricCore(root1->left, root2->right) &&  // 左与右
               isSymmetricCore(root1->right, root2->left);  // 右与左
    }
};
```

在递归过程中，每一个节点只会被访问一次，因而时间复杂度为$O(n)$。

## 解法：迭代

在求解该题时，很容易发现有逐层进行节点对比的特点。因而可以借助辅助队列来保存下一层将要访问的值（广度优先遍历）。不过，在从队列中取出节点和将节点插入到队列中时，要采取较为特殊的读取方式和插入方式。

因为我们要比较互为对称位置的两个节点的值是否相等，因而每次需要从队列头部取出两个节点。那么，在进行节点的入队操作时，就要保证进入队列的是二叉树中成对称位置的两个节点。

* 在进行节点值对比时：
  * 如果当前两个节点的值不想等（分为`val`不相等和只有一个节点为`nullptr`两种情况），则直接返回`false`；
  * 如果两个节点都为`nullptr`，则跳过当次循环，进入下一次循环。

* 在进行入队操作时，如果当前两个节点**都是**叶子节点，那么就不进行入队操作。否则，按照正常次序入队；
* 入队时，依次压入第一个节点的左节点和第二个节点的右节点、第一个节点的右节点和第二个节点的左节点；
* 辅助队列为空时退出循环，返回`true`。

代码如下：

```c++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        deque<TreeNode*> node_queue;
        node_queue.push_back(root->left);
        node_queue.push_back(root->right);
        while (!node_queue.empty()){
            TreeNode* node_1 = node_queue.front();
            node_queue.pop_front();
            TreeNode* node_2 = node_queue.front();
            node_queue.pop_front();
            // 对比当前两个节点的值
            if (node_1 != nullptr && node_2 != nullptr){
                if (node_1->val != node_2->val)
                    return false;
            } else if (node_1 == nullptr && node_2 == nullptr){
                continue;
            } else {
                return false;
            }

            // 当前两个节点都不为nullptr的情况
            if (node_1->left == nullptr && node_1->right == nullptr && 
                node_2->left == nullptr && node_2->right == nullptr)  // 当前两个节点为叶子节点
                continue;
            node_queue.push_back(node_1->left);
            node_queue.push_back(node_2->right);
            node_queue.push_back(node_1->right);
            node_queue.push_back(node_2->left);
        }
        return true;
    }
};
```

实测时，迭代代码比递归代码慢一点。