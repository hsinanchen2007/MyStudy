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
    TreeNode* goleft(TreeNode *root,stack<TreeNode *>&s)
    {
        if(root==NULL)
        {
            return NULL;
        }
        while(root->left!=NULL)
        {
            s.push(root);
            root=root->left;
        }
        return root;
    }
    void tree_element(TreeNode *p, vector<char> &vc)
    {

        if(p==NULL)
        {
            vc.push_back('K');
            return;
        }
        vc.push_back(p->val+'0');
        tree_element(p->left,vc);
        tree_element(p->right,vc);
    };
    vector<char> element2(TreeNode *p)
    {
        vector<char> ret;
       TreeNode *t=NULL;
       stack<TreeNode *> s;
       t=goleft(p,s);
       
       while(t)
       {
            cout<<t->val<<endl;
            ret.push_back(t->val);
            if(t->right!=NULL)
            {
                    t=goleft(t->right,s);
            }          
            else if(!s.empty())
            {
                t=s.top();
                s.pop();
            }    
            else
            {
                t=NULL;
            }
       }
       return ret;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
    //第一种解法
    //    //这是一道树的遍历的问题
    //    if(p==NULL && q==NULL)
    //    {
    //        return true;
    //    }
    //    if(p==NULL || q==NULL)
    //    {
    //        return false;
    //    }
    //    if(p->val!=q->val)
    //    {
    //        return false;
    //    }
    //    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    
    //第二种解法
       vector<char> vc1,vc2;
       tree_element(p,vc1);
       tree_element(q,vc2);
       for(int i=0;i<vc1.size();i++)
       {
           if(vc1[i]!=vc2[i])
           {
               return  false;
               break;
           }
       }
        return true;
       //第三种解法 利用stack 结构进行非递归遍历 这个是中序遍历的非递推实现 
    }
};
```
2020.1.10 饱读诗书小码农
哈哈哈名称是对自己的期许 
这是今天的第一道题~
在这道题中，自己主要是利用了这个平台建立的树的结构，练习了树的遍历的代码，当然也实现了两种方法的题目解法。

