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
    /*TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,int inLeft,int inRight,int posLeft,int posRight) {
        if(inLeft>inRight) return NULL;
        //创建根节点
        TreeNode* root=new TreeNode(postorder[posRight]);
        //在中序遍历中找出根
        int i;
        for(i=inLeft;i<=inRight;i++)
            if(inorder[i]==postorder[posRight]) break;
        root->left=buildTree(inorder,postorder,inLeft,i-1,posLeft,posLeft+(i-1-inLeft));
        root->right=buildTree(inorder,postorder,i+1,inRight,posLeft+(i-inLeft),posRight-1);
        return root;
    }*/

    //迭代
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        //创建根节点
        TreeNode* root=new TreeNode(postorder.back());
        //创建栈存放
        stack<TreeNode*> S;
        S.push(root);
        int size=postorder.size();
        //从后遍历
        int j=size-1;//中序遍历的索引
        for(int i=size-2;i>=0;i--)
        {
            TreeNode* back=NULL;
            while(!S.empty()&&S.top()->val==inorder[j])
            {//栈顶为根的右子树结束
                j--;
                back=S.top();
                S.pop();
            }
            TreeNode* newNode=new TreeNode(postorder[i]);
            if(back)//开始左子节点
                back->left=newNode;
            else
                S.top()->right=newNode;
            S.push(newNode);
        }
        return root;
    }
};
```