```

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        int res=-1;
        int value=INT_MIN;
        deque<TreeNode*> sq{root};
        int cnt=1;
        while(!sq.empty())
        {
            int size=sq.size();
            int tmpres=0;
            for(int i=0;i<size;++i)
            {
                TreeNode* tmproot=sq.front();
                sq.pop_front();
                tmpres+=tmproot->val;
                if(tmproot->left) sq.push_back(tmproot->left);
                if(tmproot->right) sq.push_back(tmproot->right);
            }
            res=tmpres>value?cnt:res;
            value=tmpres>value?tmpres:value;
            cnt++;

        }
        return res;
    }
};
```
