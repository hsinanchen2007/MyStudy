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
 //利用两个栈 进行后根序遍历 当找到一个p时 将栈暂存起来 当找到另外一个q时 返回栈中距离根节点最远的一个相同节点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s,temp;
        TreeNode* cur=root,*last=NULL;
        while(cur||!s.empty())
        {
            if(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=s.top();
                if(cur->right&&cur->right!=last)
                {
                    cur=cur->right;
                    s.push(cur);
                    cur=cur->left;
                }
                else
                {
                    if(temp.empty()&&(cur==p||cur==q))
                        temp=s;
                    else if(!temp.empty()&&(cur==p||cur==q)) break;
                    s.pop();
                    last=cur;
                    cur=NULL;
                }
            }
        }
        int temp_len=temp.size();
        int s_len=s.size();
        if(temp_len>s_len)
        {
            int i=temp_len-s_len;
            while(i){temp.pop();i--;};
            while(s_len)
            {
                if(temp.top()==s.top()) return temp.top();
                else 
                {
                    temp.pop();
                    s.pop();
                }
            }
        }
        else
        {
            int i=s_len-temp_len;
            while(i){s.pop();i--;};
            while(temp_len)
            {
                if(temp.top()==s.top()) return temp.top();
                else 
                {
                    temp.pop();
                    s.pop();
                }
            }
        }
        return NULL;
    }
};
```

```
 //法2 官方题解递归 后根序遍历 递归 如果一个节点的左子树是要找的 那这个节点的left为true 右子树不是要找的 
 //那这个节点的right为false 若一个节点它本身是要找的 则self=true
 //当一个节点的right&&left或self&&(left||right)时 它是最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res=NULL;
        helper(root,p,q,res);
        return res;
    }
    bool helper(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode* &res)
    {
        if(!root) return false;
        bool left=helper(root->left,p,q,res);
        bool right=helper(root->right,p,q,res);
        bool self=root==p||root==q;
        if((left&&right)||(self&&(left||right)))res=root;
        return left||right||self;
    }
};
```
