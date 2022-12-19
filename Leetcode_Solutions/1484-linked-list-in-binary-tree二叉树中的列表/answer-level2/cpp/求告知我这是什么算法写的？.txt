```
class Solution {
public:
    bool s(ListNode* head, TreeNode* root)
    {
        if(head==NULL)
            return true;
        if(root==NULL)
            return false;
        if(head->val==root->val)
        {
            return s(head->next,root->left)||s(head->next,root->right);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head==NULL)
            return true;
        if(root==NULL)
            return false;       
        return s(head,root)||(isSubPath(head,root->left)||isSubPath(head,root->right));
    }
};

```
考试迷迷糊糊写了，开始想只用一个递归，然后墨迹半天发现有两种情况，改成了这样，但是算法学的不好，是根据题意写的代码，求告知这种算什么算法。