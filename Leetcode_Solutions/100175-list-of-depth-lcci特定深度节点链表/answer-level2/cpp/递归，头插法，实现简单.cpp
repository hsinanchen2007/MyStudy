利用头插法生成链表

先访问根节点，再访问右儿子，最后访问左儿子

为了方便设置哨位节点

最后删除哨位节点

```
class Solution
{
private:
    vector<ListNode*>ans;
    void helper(TreeNode* tree,int level)
    {
        if(!tree)
            return;
        if(level>=ans.size())
        {
            ListNode* head=new ListNode(0);
            ListNode* tmp=new ListNode(tree->val);
            head->next=tmp;
            ans.push_back(head);
        }
        else//利用头插法
        {
            ListNode* tmp=new ListNode(tree->val); tmp=new ListNode(tree->val);
            ListNode* nextl=ans[level]->next;
            ans[level]->next=tmp;
            tmp->next=nextl;
        }

        helper(tree->right,level+1);
        helper(tree->left,level+1);
    }
public:
    vector<ListNode*> listOfDepth(TreeNode* tree)
    {

        helper(tree,0);
        for(int i=0;i<ans.size();i++)
        {
            ListNode* tmp=ans[i]->next;
            delete ans[i];
            ans[i]=tmp;
        }


        return ans;
    }
};

```

 
