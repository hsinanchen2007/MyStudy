class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        if(head==NULL)return NULL;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        TreeNode* ans=new TreeNode(-1);
        lalala(ans,v,0,v.size()-1);
        return ans;
    }
    void lalala(TreeNode* ans,const vector<int>& v,int left,int right){
        if(left==right){
            ans->val=v[left];
            ans->left=NULL;
            ans->right=NULL;
            return;
        }
        int size=right-left+1;
        int mid=size/2;
        ans->val=v[left+mid];
        if(left>left+mid-1){
            ans->left=NULL;
        }
        else{
            ans->left=new TreeNode(-1);
            lalala(ans->left,v,left,left+mid-1);
        }
        if(right<left+mid+1){
            ans->right=NULL;
        }
        else{
            ans->right=new TreeNode(-1);
            lalala(ans->right,v,left+mid+1,right);
        }
    }

};