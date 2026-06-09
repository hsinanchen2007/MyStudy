```
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
       TreeNode* t= new TreeNode(1);
       int left=0,right=nums.size()-1;
       int mid=(left+right)>>1;
       t->val=nums[mid];
       lalala(t->left,left,mid-1,nums);
       lalala(t->right,mid+1,right,nums);
       return t;
    }

    void lalala(TreeNode* &t,int left,int right,const vector<int>& nums){
        if(left>right){
            t=NULL;
            return;
        }
        int mid=(left+right)>>1;
        t=new TreeNode(nums[mid]);
        lalala(t->left,left,mid-1,nums);
        lalala(t->right,mid+1,right,nums);
    }

};
```
