## 思路
二叉排序树的性质：若要求当前节点cur的后继有如下性质：（永远在其右边的第一个）
* 性质一： 若`cur->right`不为空, 其后继为cur右孩子往下最左边的点。（一直往下找左儿子）
* 性质二： 若`cur->right`为空，说明其后继在右上方。一直往上找，找到**第一个为左孩子**的**父节点**即可。。 若父亲为空则返回null

### 代码

```cpp
class Solution {
public:
    inline bool check(Node *cur) { // 若cur是右孩子返回true， 否则返回false
        Node *fa = cur->parent;
        if (!fa) return false;
        return fa->right == cur;
    }
    
    Node* inorderSuccessor(Node* node) {
        if (!node) return nullptr;

        if (node->right) {  // 性质一
            node = node->right;
            while (node->left) node = node->left;
            return node;
        }

        while (check(node)) {   // 性质二。 找到到第一个不是右孩子的节点
            node = node->parent;
        }
        return node->parent;
    }
};
```