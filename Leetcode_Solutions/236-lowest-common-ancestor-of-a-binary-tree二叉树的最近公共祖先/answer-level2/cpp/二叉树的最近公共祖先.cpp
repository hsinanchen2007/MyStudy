### 解题思路
从根节点去找这两个节点，并将路径放倒队列里面；
两个队列挨个pop，最后一个相同的节点即是最近公共祖先。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> deq1;
        deque<TreeNode*> deq2;
        if (!FindPath(root, p, deq1)) {
            return NULL;
        }
        if (!FindPath(root, q, deq2)) {
            return NULL;
        }
        //cout<<"test"<<endl;
        TreeNode* res;
        //cout<<deq1.size()<<" "<<deq2.size()<<endl;
        while(!deq1.empty() && !deq2.empty()) {
            //cout<<deq1.front()->val<<" "<<deq2.front()->val<<endl;
            if (deq1.front() == deq2.front()) {
                res = deq1.front();
                deq1.pop_front();
                deq2.pop_front();
            } else {
                break;
            }
        }
        return res;
    }

    bool FindPath(TreeNode* node, TreeNode* p, deque<TreeNode*>& deq) {
        if (node == NULL) {
            return false;
        }
        if (node == p) {
            deq.push_back(node);
            return true;
        }
        deq.push_back(node);
        if ( FindPath(node->left, p, deq) == true ) {
            return true;
        }
        if ( FindPath(node->right, p, deq) == true ) {
            return true;
        }
        deq.pop_back();
        return false;
    }
};
```