- __执行用时 :20 ms, 在所有C++提交中击败了99.54%的用户__

- __内存消耗 :16.4 MB, 在所有C++提交中击败了91.80%的用户__

```c++
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
        //递归迭代
        //前序：中前后
        //中序：前中后
        //可以假设树中没有重复的元素。
        if(preorder.size()==0) return NULL;
        return getroot(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* getroot(vector<int>& preorder,vector<int>& inorder,int pre1,int pre2,int in1,int in2)
    {
        if(pre2-pre1<0||in2-in1<0) return NULL;
        TreeNode* root=new TreeNode(preorder[pre1]);//前序段的第一个
        int indx=in1;//中序中根的下标
        for( ;indx<inorder.size();indx++)
        {
            if(inorder[indx]==preorder[pre1])
                break;
        }
        
        root->left=getroot(preorder,inorder,pre1+1,pre1+indx-in1,in1,indx-1);
        root->right=getroot(preorder,inorder,pre1+indx-in1+1,pre2,indx+1,in2);
        return root;
        
    }
    
};
```
