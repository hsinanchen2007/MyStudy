### 解题思路
利用二叉树的中序遍历，找到相同节点并标记，最后构造相同节点的下一树节点返回
用t标记返回节点在中序遍历序列中的位置
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //二叉搜索树的中序遍历
        stack<TreeNode*>sk;
        int t=0;
        vector<int>res;
        while(!sk.empty()||root){
            while(root){ 
                sk.push(root);
                root=root->left;
            }
            root=sk.top();
            res.push_back(root->val);
            if(root==p)t=res.size();
            sk.pop();
            root=root->right;
        }
        //若t=0说明没有找到相同节点，若t与中序遍历序列的长度相同说明最后一个节点与给定节点相同，这两种情况都没有下一节点
        if(t==0||t==res.size())return NULL;  
        else{
            TreeNode* r=new TreeNode(res[t]);
            return r;
        }
        return NULL;
    }
};
```