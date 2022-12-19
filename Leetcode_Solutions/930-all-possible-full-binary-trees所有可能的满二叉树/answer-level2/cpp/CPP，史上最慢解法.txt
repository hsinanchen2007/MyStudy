![image.png](https://pic.leetcode-cn.com/7c89ab5932447ac48401bfd60aa3527bf3b2bdda8fa1d3430b4f22175b9c1265-image.png)
我写的时候就想歪了，想着把上一组树的每个叶子结点都插两个就可以，之后全是指针（没去改返回值），到处都要深复制，之后还要去重，感觉是最蠢的解法了
```
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
    bool sametree(TreeNode* a,TreeNode* b)
    {
        if(a==NULL&&b==NULL)
            return true;
        else if(a==NULL||b==NULL)
            return false;
        else if(a->val==b->val)
        {
            return sametree(a->left,b->left)&&sametree(a->right,b->right);
        }
        return false;
    }
    void copytree(TreeNode** a,TreeNode* b)
    {
        if(b==NULL)
            *a=NULL;
        else
        {
            if(*a==NULL)
                *a=new TreeNode(0);
            if(b->left!=NULL)
                (*a)->left=new TreeNode(0);
            copytree(&(*a)->left,b->left);
            if(b->right!=NULL)
                (*a)->right=new TreeNode(0);
            copytree(&(*a)->right,b->right);
        }
    }
    TreeNode* find_p(TreeNode* p,TreeNode* root,TreeNode* the)
    {
        if(root==NULL)
            return NULL;
        if(root==the)
            return p;
        TreeNode* tmp=find_p(p->left,root->left,the);
        if(tmp!=NULL)
            return tmp;
        tmp=find_p(p->right,root->right,the);
        if(tmp!=NULL)
            return tmp;
        return NULL; 
    }
    void FBT(vector<TreeNode*>& tmp,TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            if(q.front()->left==NULL&&q.front()->right==NULL)
            {
                TreeNode* p=NULL;
                bool flag=true;
                copytree(&p,root);
                TreeNode* copy_p=find_p(p,root,q.front());
                copy_p->left=new TreeNode(0);
                copy_p->right=new TreeNode(0);
                for(int i=0;i<tmp.size();++i)
                    if(sametree(p,tmp[i]))
                    {
                        flag=false;
                        break;
                    }
                if(flag)        
                    tmp.push_back(p);
            }
            else
            {
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
    } 
    vector<TreeNode*> allPossibleFBT(int N) 
    {
        int node_num=N/2;
        vector<TreeNode*> vec_tree;
        if(N%2==0)
            return vec_tree;
        else
        {
            TreeNode* root=new TreeNode(0);
            vec_tree.push_back(root);
            for(int i=1;i<=node_num;++i)
            {
                vector<TreeNode*> tmp;
                int size=vec_tree.size();
                for(int j=0;j<size;++j)
                {
                    FBT(tmp,vec_tree[j]);
                }
                vec_tree=tmp;
            }
            return vec_tree;
        }
    }
};
```

