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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> re;
        if(!root)
            return re;
        TreeNode *s[1000];
        int top =-1;
        TreeNode *p=root,*last = NULL;
        while(p || top >=0){
            if(p){
                s[++top]=p;
                p=p->left;
            }else{
                p = s[top];
                if(p->right && p->right != last){
                    p=p->right;
                    s[++top] = p;
                    p=p->left;
                }else{
                    if(!p->left && !p->right){
                        int tmp=0;
                        for(int i = 0; i <= top; i++){
                            tmp += s[i]->val;
                        }
                        if(tmp == sum){
                            vector<int> tmp;
                            for(int i=0;i<=top;++i){
                                tmp.push_back(s[i]->val);
                            }
                            re.push_back(tmp);
                        }
                    }
                    last = p;
                    top--;
                    p = NULL;
                }
            }
        }
        return re;
    }
};
```