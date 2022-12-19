class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
         stack<TreeNode*> sta;
         TreeNode *p;
          int result;

          while(root)
          {
           sta.push(root);
           root=root->left;
          }

          while(!sta.empty())
          {
                  p=sta.top();
                  if(k==1) {
                      result=p->val;
                      break;
                  }  
                  k--;
                  sta.pop();
                  if(p->right){
                       p=p->right;
                       while(p)
                       {
                           sta.push(p);
                           p=p->left;
                        }
                    }
                 }
          return result;   
    }
};