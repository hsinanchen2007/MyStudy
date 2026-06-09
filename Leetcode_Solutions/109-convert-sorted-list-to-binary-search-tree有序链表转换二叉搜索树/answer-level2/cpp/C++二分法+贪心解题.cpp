预遍历一次链表，将链表的所有值按照顺序存储在一个数组中。根据题意可知，要想保持两边平衡，那么每次将数组的中间位置作为根，数组的两边作为左右子树可以满足这种要求，这是一种贪心的选择。然后就利用二分法递归的构造左右子树即可，
```
vector<int> vec;
    TreeNode* buildTree(int low,int high)
    {
        if(low==high)
        {
            TreeNode *root=new TreeNode(vec[low]);
            return root;
        }
        int mid=(low+high)/2;
        TreeNode* root=new TreeNode(vec[mid]);
        if(low<=mid-1)
            root->left=buildTree(low,mid-1);
        if(mid+1<=high)
            root->right=buildTree(mid+1,high);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *tmp=head;
        while(tmp!=NULL)
        {
            vec.push_back(tmp->val);
            tmp=tmp->next;
        }
        return buildTree(0,vec.size()-1);
    }
```
