
![image.png](https://pic.leetcode-cn.com/df0e5961bdb316f8790da268541ed635868de1bcd9bbd02ae6be9fb21441e6c3-image.png)

双指针判断

判断的时候需要用
-  r1的左子树和r2的右子树比较
-  r1的右子树和r2的左子树比较


```c
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool ans=true;
        if(root==NULL) return ans;
        judge(root->left,root->right,ans);
        return ans;
    }
    void judge(TreeNode* r1,TreeNode *r2,bool &ans){
        if(r1==NULL&&r2==NULL) return;
        //if((r1==NULL&&r2!=NULL)||(r1!=NULL&&r2==NULL)||r1->val!=r2->val) ans=false; 简化
        if(!r1||!r2||r1->val!=r2->val) ans=false; 
        else{
           judge(r1->left,r2->right,ans);
           judge(r1->right,r2->left,ans);
        }
        
    }
}
```
