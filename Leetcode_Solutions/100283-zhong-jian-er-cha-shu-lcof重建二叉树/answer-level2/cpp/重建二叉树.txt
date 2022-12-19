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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len1 = preorder.size(),len2 = inorder.size();
        if(len1 == 0 || len2 == 0 || len1 != len2)
            return NULL;
        return buildTreeCore(preorder,0,len1 - 1,inorder,0,len2 - 1);
    }
    //核心代码
    TreeNode* buildTreeCore(vector<int>& preorder,int pre_left,int pre_right,vector<int>& inorder,int in_left,int in_right){
        if(pre_left > pre_right || in_left > in_right)
            return NULL;
        //定义根节点
        int root_val = preorder[pre_left];//注意：千万别一不留神把pre_left写成0
        TreeNode* root = new TreeNode(root_val);

        int index = 0;
        //根据前序序列的根节点来找到该节点在中序序列中的位置，用index记录
        for(int i = in_left;i <= in_right;++i){
            if(inorder[i] == root_val){
                index = i;
                break;
            }
        }
        //分别构建左右子树
        root->left = buildTreeCore(preorder,pre_left + 1,pre_left + index - in_left,inorder,in_left,index - 1);
        root->right = buildTreeCore(preorder,pre_left + index - in_left + 1,pre_right,inorder,index + 1,in_right);
        return root;
    }
};
```