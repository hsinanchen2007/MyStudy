### 解题思路
此处撰写解题思路
二叉搜索树的第K小元素，首先明确二叉树的遍历方式：中序遍历
中序遍历的两种经典方式就是：堆栈、递归
1、堆栈的方法：
思想是，先只遍历左节点，并依次推入栈中，直到最左边的节点开始查询右节点，如果有右节点，像之前一样（将右节点作为根节点那样），从上到下将遍历到的左节点推入栈中，因为栈尾始终存储的是当前的最左边节点，所以没推出栈一次,--k.
2、递归的方法：
这个更容易想到，直接是先遍历到最左边，然后依次往上走，没上走一个节点，--k。

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while(root){
            s.push(root);
            root = root->left;
        }
        while(!s.empty()||root){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            while((--k)==0) return root->val;
            root = root->right;
        }
        return 0;
    }
    /*int out;
    int kthSmallest(TreeNode* root, int k) {
        find(root, k);
        return out;
    }
    void find(TreeNode *root, int &k){
        if(!root) return ;
        find(root->left, k);
        while((--k)==0) out=root->val;
        find(root->right, k); 
    }*/
};
```