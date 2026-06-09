```
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==NULL||A==NULL){
            return false;
        }
        queue<TreeNode*> q;
        q.push(A);
        while(!q.empty()){

            int size=q.size();
            TreeNode* temp;
            for(int i=0;i<size;++i){
                temp=q.front();
                q.pop();
                if(temp->val==B->val){
                    if(lalala(temp,B))
                        return true;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return false;
    }

    bool lalala(TreeNode* A,TreeNode* B){
        if(B==NULL){
            return true;
        }
        if(A==NULL){
            return false;
        }
        if(A->val==B->val){
            return lalala(A->left,B->left)&lalala(A->right,B->right);
        }
        return false;
    }
};
```
