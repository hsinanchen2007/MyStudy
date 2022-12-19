### 解题思路
此处撰写解题思路

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
        
        TreeNode* r = root; //首先保存初始root地址
        vector<TreeNode*> path_p; //新建树节点指针类型的vector
        vector<TreeNode*> path_q;
        while(root->val != p->val){//循环找出p节点的寻找路径上的点，并且记录在vector中
            if(root->val > p->val){//如果p比root小，继续查找左子树
                path_p.push_back(root);
                root = root->left;
            }
            else{//如果p比root大，继续查找右子树
                path_p.push_back(root);
                root = root->right;
            }
        }
        root = r;
        while(root->val != q->val){//循环找出p节点的寻找路径上的点，并且记录在vector中
            if(root->val > q->val){
                path_q.push_back(root);
                root = root->left;
            }
            else{
                path_q.push_back(root);
                root = root->right;
            }
        }
        TreeNode* record;
        path_p.push_back(p);
        path_q.push_back(q);
        int n = min(path_p.size(), path_q.size());
        for(int i = 0; i < n; i++){//依次比较两个容器的地址，找出最后一个相同的即是最近公共祖先
            if(path_p[i] == path_q[i]){
                record = path_p[i];
            }
        }
        return record;//返回结果地址
    }
};




















```