分成几步完成
1. 搜索 key, 若存在 key 则继续第二步。搜索过程中保存被删除结点的双亲，若双亲为NULL，则说明被删除结点为根节点，修改返回值。
2. 若被删除结点是叶子结点。将双亲指向被删除结点的指针域置空即可。
3. 若被删除结点没有左子树或者没有右子树，将双亲指向被删除结点的指针域修改为存在的子树即可。
4. 若被删除结点有左右子树。那么 
    - (1) 找到中序遍历中被删除结点的直接前驱。 
    - (2) 将双亲指向被删除结点的指针域修改为被删除结点的左子树。
    - (3) 将直接前驱的右指针域指向被删除结点的右子树。

第4步最好通过画图来理解。第四步的第二小步后，由于被删除结点的右子树上的所有结点都大于被删除结点，而直接前驱在被删除结点的左子树上。所以它肯定大于直接前驱。所以它接到直接前驱的右子树上是没有问题的。原来的树仍然是一颗BST。
```cpp
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *target = root, *parent = nullptr;
        while(target) {
            if(key == target->val) break;
            else if(key < target->val) {
                parent = target;
                target = target->left;
            }
            else if(key > target->val) {
                parent = target;
                target = target->right;
            }
        }
        if(!target) return root;   //  无此结点
        
        TreeNode *child = (target->left) ? target->left : target->right;
        TreeNode *ret = root;
        if(!parent) {  // 删除的是根节点, 改变返回值
            ret = child;
        }
        if(target->left==nullptr && target->right==nullptr) {    // 1. 删除的是叶子节点
            if(parent) {
                if(parent->left == target) parent->left = nullptr;  // 1.1 target是左子树
                else  parent->right = nullptr;                      // 1.2 target是右子树
            }
        }
        else if(target->left && target->right) {  // 2. 既有左子树，也有右子树（child为左子树）
            // 找target的直接前驱(target左子树中序遍历的最后一个结点)
            TreeNode *s = target->left;
            while(s->right) s = s->right;
            
            if(parent) {
                if(parent->left == target) parent->left = child;
                else parent->right = child;
            }
            s->right = target->right;
        } else {  // 3. 只有有一个子树（child）
            if(parent) {
                if(parent->left == target) parent->left = child;
                else parent->right = child;
            }
        }
        delete target;
        return ret;
    }
};
```
