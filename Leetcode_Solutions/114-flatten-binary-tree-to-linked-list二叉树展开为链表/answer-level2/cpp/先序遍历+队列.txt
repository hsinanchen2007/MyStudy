### 解题思路
从题目给的例子看很显然是一个先序遍历建立的二叉树，而链表顺序就是建树的顺序。那么就按照先序遍历将各节点加入队列。
队列建立完毕后节点依次出队往链表后面加，注意出队的节点要先将左右子树置空

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void PreOrderedTravel(TreeNode* root, queue<TreeNode*>& q)
    {
        if (root == NULL) {
            return;
        }

        q.push(root);//先序
        PreOrderedTravel(root->left, q);
        PreOrderedTravel(root->right, q); 
    }

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        PreOrderedTravel(root, q);

        root = q.front();
        TreeNode* fatherNode = root;
        //cout << fatherNode->val << endl;
        fatherNode->left = NULL;
        fatherNode->right = NULL;
        TreeNode* curNode = NULL;
        q.pop();
        while (!q.empty()) {
            curNode = q.front();//按照建树顺序依次出队
            //cout << curNode->val << endl;
            q.pop();
            curNode->left = NULL;//打断原来的左右子树
            curNode->right = NULL;
            fatherNode->right = curNode;//接到上个节点的右子树上
            fatherNode = fatherNode->right;//链表指针后移（右移）
        }
    }
};
```