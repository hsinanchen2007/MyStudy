思路：主要是先用非递归求出垂直线上一共有多少列，然后广度遍历来写主体逻辑，同一层从左到右遍历，但是由于题目要求，
同一层元素x值相同情况下需要按大小排列，所以这里不使用sort,直接每一层再创建一个vector<vector<int>> tmp来存取，
然后插入的时候只需要遍历一次就行了，调用sort 貌似时间复杂度会更高。

```
class Solution {
public:
    int mindeep = 1;
    int maxdeep = -1;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> tmp;
        if(root==NULL) return tmp;

        dfs(root,0);
  
        int startIndex = std::abs(mindeep);
        vector<vector<int>> res(startIndex+1+maxdeep);

        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,startIndex));

        while(!q.empty()){         
            int size = q.size();
            vector<vector<int>> tmp(startIndex+1+maxdeep);
            for(int i=0;i<size;i++){
                pair<TreeNode*,int>& toppair = q.front();
                int curval = toppair.second;
       
                if (tmp[curval].empty()){
                    tmp[curval].push_back(toppair.first->val);
                }else{
                    
                    int tmpsize = tmp[curval].size();
                    int insertIndex = 0; //元素真正要插入的位置
                    for(int k=0;k<tmpsize;k++){
                        if(toppair.first->val < tmp[curval][k]){
                             continue;
                        }
                        insertIndex++;
                    }
                    tmp[curval].insert(tmp[curval].begin()+insertIndex,toppair.first->val);
                }


                if(toppair.first->left!=NULL){
                    q.push(make_pair(toppair.first->left,curval-1));
                }
                if(toppair.first->right!=NULL){
                    q.push(make_pair(toppair.first->right,curval+1));
                }
                q.pop();
            }

            for(int i=0;i<tmp.size();i++){
                for(int j=0;j<tmp[i].size();j++){
                    res[i].push_back(tmp[i][j]);
                }
            }

        }
        return res;
    }

    void dfs(TreeNode* node,int val){
        if(node==NULL)return ;
        if(val<mindeep) mindeep = val;
        if(val>maxdeep) maxdeep = val;
        //cout<<node->val<<"***"<<val<<endl;
        dfs(node->left,val-1);
        dfs(node->right,val+1);
    }
};
```
