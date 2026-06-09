### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max=0;
        if(root==NULL)
        return 0;
        else {
            vector<int> vec;
            getdeep(root,vec);
            
            for(auto cur :vec)
            {
                cout<<cur<<endl;
                if(max<cur)
                max=cur;
            }
        }

        
        
        return max;
       

    }

    int getdeep(TreeNode* root,vector<int> &vec){

        if(root==NULL)
        return 0;
        else{

            if(root->right==NULL&&root->left==NULL)
            {
                return 1;
            }else{
                int r=getdeep(root->right,vec);
                int l=getdeep(root->left,vec);
                vec.push_back(r+l);
                if(r>l)
                return r+1;
                else return l+1;
                
            }

           
        }

    }
};
```