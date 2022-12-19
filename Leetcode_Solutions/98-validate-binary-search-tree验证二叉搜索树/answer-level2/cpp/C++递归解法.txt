验证根节点与左结点和右结点的大小关系，比较容易，难于验证的是根节点与左右子树的最大值和最小值的关系。
左子树的最大值应该是左子树中最接近根节点的值，
右子树的最小值应该是右子树中最接近跟结点的值。
所以想到利用一个结构体存储以每个结点为根的子树的最大值和最小值。
代码如下：
理论上来说，下面代码还可以进一步精简，但我就懒的改了。
```
struct Node{
        int min;
        int max;
        bool flag;
        Node(int _min,int _max,bool _flag)
        {
            min=_min;
            max=_max;
            flag=_flag;
        }
    };

    Node dfs(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL)
        {//左右子树均为空
            Node tmp(root->val,root->val,true);
            return tmp;
        }
        else if(root->left!=NULL && root->right==NULL)
        {//仅右子树为空
            Node l=dfs(root->left);
            bool flag=true;
            int min=l.min;
            int max=root->val;
            if(l.flag==false)
            {
                Node tmp(min,max,false);
                return tmp;
            }
            flag=flag && (root->val>l.max)&& (root->val>root->left->val);
            Node tmp(min,max,flag);
            return tmp;
        }
        else if(root->left==NULL && root->right!=NULL)
        {//仅左子树为空
            Node r=dfs(root->right);
            bool flag=true;
            int min=root->val;
            int max=r.max;
            if(r.flag==false)
            {
                Node tmp(min,max,false);
                return tmp;
            }
            flag=flag &&(root->val<r.min)&& (root->val<root->right->val);
            Node tmp(min,max,flag);
            return tmp;
        }
        else //if(root->left!=NULL && root->right!=NULL)
        {//左右子树均不为空
            Node l=dfs(root->left);
            Node r=dfs(root->right);
            bool flag=true;
            int min=l.min;
            int max=r.max;
            if(r.flag==false || l.flag==false)
            {
                Node tmp(min,max,false);
                return tmp;
            }
            flag=flag && (root->val>l.max) &&(root->val<r.min)&& (root->val<root->right->val)&& (root->val>root->left->val);
            Node tmp(min,max,flag);
            return tmp;
        }
    }

    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        Node pNode=dfs(root);
        return pNode.flag;
        
    }
```
