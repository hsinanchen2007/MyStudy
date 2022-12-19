
## 递归解法

### 思路
以为树天然就具有递归的特性，用递归方式是很容易想到的。遍历整棵树，如果点前是叶子结点（没有左右孩子），判断当前结点的值是否与sum相等，如果相等满足条件，返回true, 否者返回false。如果当前结点不是叶子结点，则递归调用`hasPathSum`函数，检查左右孩子是否满足条件，注意其中第二个参数为sum减去当前结点的值。

### 代码实现
```
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr ) return false;

        if (root->left == nullptr && root->right == nullptr) {
            return root->val == sum;
        }

        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
```

### 复杂度分析
- 时间复杂度: O(n), 需要访问每一个结点，所以时间复杂度为O(n)
- 空间复杂度: 最好情况，当树是完全二叉树时，递归的深度为`log(n)`, 所以最多需要`log(n)`的函数调用栈空间；最坏情况，当树退化为链表时，递归的深度为`n`, 需要`n`的函数调用中空间。



## 迭代解法

### 思路
其实和递归的思路一样，只不过递归是系统维护空间，而这里是自己维护栈空间。需要自定义一个栈，保存当前结点以及当前的sum。

### 代码实现

```
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        
        stack<pair<TreeNode *, int>> __stack;
        __stack.push(make_pair(root, sum));

        while (!__stack.empty()) {
            auto &item = __stack.top();
            auto node = item.first;
            sum = item.second;
            __stack.pop();

            if (node->left == nullptr && node->right == nullptr && node->val == sum) {
                return true;
            }

            if (node->left) {
                __stack.push(make_pair(node->left, sum - node->val));
            }

            if (node->right) {
                __stack.push(make_pair(node->right, sum - node->val));
            }
        }

        return false;
    }
};
```

### 复杂度分析
- 时间复杂度: O(n), 需要访问每一个结点，所以时间复杂度为O(n)
- 空间复杂度: 需要定义一个栈，最好情况，当树退化为链表时，栈中最多保存一个结点，空间复杂度为`O(1)`; 最好情况，当时完全二叉树时，栈中最多需要保存`log(n)`个结点，空间复杂度为`O(log(n))`.
