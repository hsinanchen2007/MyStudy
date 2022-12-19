```
            #include <iostream>
            using namespace std;
            class Solution {
            public:
                int maxDepth(TreeNode* root) {
                    
                    if(!root)return 0;

                    if(root->left==NULL && root->right==NULL)return 1;

                    int ans=1; //第一层根结点

                    ans+=max(maxDepth(root->left),maxDepth(root->right));

                    return ans;

                }
            }; ；
```
