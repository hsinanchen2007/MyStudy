### 解题思路
1.对后序进行建树，**此树的根一定是当前先序的第一个值**，顺序遍历先序
2.用这个值去后序中找到这个根的位置
3.对后序中这个根左右两边子树递归进行建树
ps:用了一个pre_cur记录当前在先序中的查找位置
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
    vector<int> ined;
    int pre_cur;
    int find_index_inorder(int start,int end,int key,vector<int>& inorder)
    {   
        while(start<=end){
            if(key==inorder.at(start)){
                pre_cur++;
                break;
            }
            else
                start++;
        }
        return start;               
    }

    TreeNode* buildcurTree(int start,int end,vector<int>& preorder, vector<int>& inorder)
    {
    int cur;
        if(start>end)
            return NULL;
        cur=find_index_inorder(start,end,preorder.at(pre_cur),inorder);
        TreeNode* root=new TreeNode(inorder.at(cur));
        root->left=buildcurTree(start,cur-1,preorder, inorder);
        root->right=buildcurTree(cur+1,end,preorder, inorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int cur,start=0,end=preorder.size()-1;
        pre_cur=0;
        return buildcurTree(start,end,preorder, inorder);
    }
};
```