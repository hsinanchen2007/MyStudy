C++记忆搜索，map实现python的字典
```
class Solution {
public:
    map<pair<int,int>,vector<TreeNode*>> dic;//dic是一个键为(left,right)左右边界的pair对，值为边界对应的TreeNode*型的数组的字典
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
        {
            vector<TreeNode *> res;
            return res;
        }
        getRoot(1,n);
        pair<int, int> result(1,n);
        return dic[result];
    }
    vector<TreeNode*> getRoot(int l, int r){
        vector<TreeNode*> res;
        pair<int, int> node(l,r);
        if(dic.count(node)>0)
            return dic[node];
        if(l > r)
            {
                res.push_back(NULL);
                return res;
            }
        for(int i=l;i<=r;++i)
        {
            vector<TreeNode*> le = getRoot(l,i-1); //递归获取左子树
            vector<TreeNode*> rig = getRoot(i+1,r); //递归获取右子树
            for(int j=0;j<le.size();++j)
            {
                for(int k=0;k<rig.size();++k)
                {
                    TreeNode* root= new TreeNode(i); //以i为根节点的生成的搜索二叉树
                    root->left = le[j];
                    root->right = rig[k];
                    res.push_back(root);
                }
            }
        }
        dic.insert(map<pair<int,int>, vector<TreeNode*>>::value_type(node,res));
        return res;
    }
};
```
