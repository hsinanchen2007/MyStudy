### 解题思路
通过非递归中序遍历，找到需要交换的两个Treenode，交换两个Treenode的val；
特别注意，节点中的值可能是负的，所以最开始补充的节点值应该取-2147483648;

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
    struct node{
        TreeNode *tree;
        int calnum;
        node(TreeNode * tr,int n=0):tree(tr),calnum(n){}
    };
    void recoverTree(TreeNode* root) {
        node* tmp;
        node* pos;
        node* wnode1;
        node* wnode2;
        stack<node*> que;
        wnode1 = NULL;
        tmp = new node(root);
        pos = new node(new TreeNode(-2147483648));
        que.push(tmp);
        while(!que.empty())
        {
            tmp = que.top();
            que.pop();
            if(++tmp->calnum<2){
                que.push(tmp);
                if(tmp->tree->left) que.push(new node(tmp->tree->left));
            }
            else{
                if(tmp->tree->val<pos->tree->val){
                    if(wnode1==NULL) wnode1 = pos;
                    if(wnode1!=NULL) wnode2 = tmp;
                }
                if(tmp->tree->right) que.push(new node(tmp->tree->right));
                pos = tmp;
            }
        }
        int swap= wnode1->tree->val;
        wnode1->tree->val = wnode2->tree->val;
        wnode2->tree->val = swap;
    }
};
```