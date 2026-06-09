```
class Solution {
public:
    map<int, int>m;//哈希表
    void dfs(TreeNode* p)
    {   
        if(p==NULL){return ;}
        m[p->val]++;

        dfs(p->left);
        dfs(p->right);
    }

    vector<int> findMode(TreeNode* root) {
    
        vector<int>ans;
        dfs(root);
        int max=INT_MIN;
        for(auto i:m)
        {   cout<<i.first<<" "<<i.second<<endl;
            if(i.second>max)//如果之前找到的数不是频率最大的
            {   max=i.second;
                ans.clear();
                ans.push_back(i.first);
            }
            else if(i.second==max){ans.push_back(i.first);}
        }

        
        return ans;
    }
};
```
