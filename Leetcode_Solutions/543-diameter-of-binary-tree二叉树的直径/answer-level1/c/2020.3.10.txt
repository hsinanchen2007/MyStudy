### 解题思路
递归向下找每个节点的最长边长，即左子节点的最长边长和右子节点的最长边长中较大的值再加上1，同时将每个节点左右边长相加得到以该节点为中心的直径长度，将这个长度和目标比较来更新目标。

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLenthOfTreeNode(struct TreeNode* tNode,int *maxr)
{
    if(tNode->left==NULL && tNode->right==NULL)
    {    
        return 0;
    }
    else if(tNode->left==NULL)
    {
        int ml=maxLenthOfTreeNode(tNode->right,maxr)+1;
        if(ml>*maxr)
        {
            *maxr=ml;
        }        
        return ml;
    }
    else if(tNode->right==NULL)
    {
        int ml=maxLenthOfTreeNode(tNode->left,maxr)+1;
        if(ml>*maxr)
        {
            *maxr=ml;
        }        
        return ml;
    }
    else
    {
        int l=maxLenthOfTreeNode(tNode->left,maxr)+1;
        int r=maxLenthOfTreeNode(tNode->right,maxr)+1;
        if(l+r>*maxr)
        {
            *maxr=l+r;
        }
        return l>r?l:r;
    }
}

int diameterOfBinaryTree(struct TreeNode* root){
    int ans=0;
    if(root!=NULL)
    {
        maxLenthOfTreeNode(root,&ans);
    }
    
    return ans;
}
```