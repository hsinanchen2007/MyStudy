
给定义节点，判断左子树和右子树是否是二叉搜索树，如果是，判断以该节点为根的子树是不是二叉搜索时。
判断时维护左子树最小最大值和右子树最大最下值，方便比较。
遍历的同时，顺便求出子树和
```
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans=0;
        int max_num=INT_MIN;
        int min_num=INT_MAX;
        int sum=0;
        is_search_tree(root,ans,max_num,min_num,sum);
        return ans;
    }




    bool is_search_tree(TreeNode* x,int &ans,int &max_num,int &min_num,int &sum)
    {
        if(x==NULL)
            return true;
        if(!x->left && !x->right)
        {
            max_num=min_num=x->val;
            sum+=x->val;
            ans=max(ans,x->val);
            return true;
        }
        int left_max=INT_MIN;
        int left_min=INT_MAX;
        int right_max=INT_MIN;
        int right_min=INT_MAX;
        int left_sum=0;
        int right_sum=0;
        bool l=is_search_tree(x->left,ans,left_max,left_min,left_sum) ;
        bool r=is_search_tree(x->right,ans,right_max,right_min,right_sum);
        if(!l||!r)
            return false;
        if(!x->left && right_min > x->val)
        {
            max_num = max(max_num,right_max);
            min_num = min(min_num,x->val);
            sum = x->val + right_sum;
            ans = max(ans,sum);
            return true;
        }
        else if(!x->right && left_max < x->val)
        {
            max_num = max(max_num,x->val);
            min_num = min(min_num,left_min);
            sum = x->val + left_sum;
            ans = max(ans,sum);
            return true;
        }
        else if(left_max < x->val && right_min > x->val  )
        {
            max_num = max(max_num,right_max);
            min_num = min(min_num,left_min);
            sum = left_sum + x->val + right_sum;
            ans = max(ans,sum);
            return true;
        }
        return false;
    }
};
```
