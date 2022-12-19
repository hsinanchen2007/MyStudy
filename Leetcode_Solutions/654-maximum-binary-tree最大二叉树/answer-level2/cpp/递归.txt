```
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       int size = nums.size();
        if(size == 0)
            return NULL; 
        return MaximumBinaryTree(nums,0,size-1);
    }
    
    
     TreeNode* MaximumBinaryTree(vector<int>& nums,int left,int right){
         if(left > right)
             return NULL;
         int MaxIndex = max(nums,left,right);
         TreeNode* head = new TreeNode(nums[MaxIndex]);
         head->left = MaximumBinaryTree(nums,left,MaxIndex-1);
         head->right = MaximumBinaryTree(nums,MaxIndex+1,right);
         return head;    
     }
    int max(vector<int>& nums,int left,int right){
        int max = nums[left];
        int index = left;
        for(int i=left;i<=right;i++)
            if(max < nums[i]){
                max = nums[i];
                index = i;
            }
        return index;
        
    }
};
```

![image.png](https://pic.leetcode-cn.com/f51c72cb1ee2ed68c3b9fe1e61c4885c6dc7fa7b0bc0122cb615d910a8d7a506-image.png)



