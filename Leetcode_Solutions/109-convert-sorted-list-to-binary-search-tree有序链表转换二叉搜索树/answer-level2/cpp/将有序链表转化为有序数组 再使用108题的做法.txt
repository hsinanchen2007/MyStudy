```
class Solution {
public:
    TreeNode* fun(vector<int>&temp,int l,int r){
        if(l>r) return NULL;
        int mid=(r+l)/2;
        TreeNode* root=new TreeNode(temp[mid]);
        root->left=fun(temp,l,mid-1);
        root->right=fun(temp,mid+1,r);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return  NULL;
        vector<int>temp;
        while(head!=NULL){
            temp.push_back(head->val);
            head=head->next;
        }
        return fun(temp,0,temp.size()-1);
    }
};
```
