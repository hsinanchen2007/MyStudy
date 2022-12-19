```

class Solution {
public:

    vector<int>all_data;
    vector<int>data_updata;
    int visit(TreeNode*root)
    {
        if(root==NULL)
            return 1;
        visit(root->left);
        all_data.push_back(root->val);
        visit(root->right);
        return 1;
    }
    int myupdata(TreeNode*root,int &pos)
    {
        if(root==NULL)
            return 1;
        myupdata(root->left,pos);
        root->val=data_updata[pos];
        pos++;
        myupdata(root->right,pos);
        return 0;

    }
    TreeNode* bstToGst(TreeNode* root) {
        visit(root);
        if(all_data.size()<=1)
            return root;
        int pre(0);
        for(int i=all_data.size()-1;i>=0;i--)
        {
            pre+=all_data[i];
            data_updata.insert(data_updata.begin(),pre);
        }
        int x=0;
        myupdata(root,x);
        return root;
    }
};
```
![批注 2019-11-24 231303.png](https://pic.leetcode-cn.com/a8187cffd7d54de5c80254ba78690f3751b3d3fd3219986f6982ce21fcfc2ec0-%E6%89%B9%E6%B3%A8%202019-11-24%20231303.png)






