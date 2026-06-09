### 解题思路

先序遍历+kmp算法

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
    vector<int> a,b;
    vector<int>next;
    bool isSubtree(TreeNode* s, TreeNode* t) {
        dfs(s,a);dfs(t,b);
        getN(b,next);
        int i=0,j=0,na=a.size(),nb=b.size();
        while(i<na&&j<nb){
            //cout<<i<<' '<<j<<endl;
            if(j==-1||a[i]==b[j])++j,++i;
            else j=next[j];
        }
        return j==b.size();
    }
    void getN(vector<int> vi,vector<int>& ne){
        vector<int> tmp(vi.size());
        tmp[0]=-1;
        int p=-1,i=0;
        while(i+1<vi.size()){
            if(p==-1||vi[i]==vi[p]){
                ++p;++i;
                tmp[i]=p;
            }else p=tmp[p];
        }
        ne.swap(tmp);
    }
    
    void dfs(TreeNode* s,vector<int>&t){
        if(s==NULL){
            t.push_back(INT_MIN);
            return ;
        }
        t.push_back(s->val);
        dfs(s->left,t);
        dfs(s->right,t);
    }
};
```