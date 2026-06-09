### 解题思路
首先子树和root是一个建立方法，所以用递归。
首先每个前序的值都是根节点优先遍历，所以先依次查找前序的每次迭代最开始的值（用引用的pre_cur代替），然后在中序里查找
对应的值，该值前面即为根节点左子树，后面则为右子树。
写好递归后，加入递归终止条件即完成。

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
        if(preorder.size() != inorder.size() || preorder.empty()){
            return nullptr;
        }
        preTree = preorder;
        inTree = inorder;
        int pre_start =0;
        return buildTreeCore(0,inorder.size()-1,pre_start,preorder.size()-1);
    }

private:    
    TreeNode* buildTreeCore(int in_start, int in_end,int& pre_cur,int pre_end){
        int index = 0;
        if (in_end<in_start || pre_end<pre_cur)
            return nullptr;
        while(inTree[in_start+index] != preTree[pre_cur]){
            index++;
        }
        TreeNode* root = new TreeNode(preTree[pre_cur]);
        pre_cur++;
        
        root->left = buildTreeCore(in_start,index+in_start-1,pre_cur,pre_end);
        root->right =  buildTreeCore(in_start+index+1,in_end,pre_cur,pre_end);
        return root;
    }

    vector<int> preTree;
    vector<int> inTree;
};
```