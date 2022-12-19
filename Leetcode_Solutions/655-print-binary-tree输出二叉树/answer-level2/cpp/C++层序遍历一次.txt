首先用层序遍历的方式遍历完二叉树，将节点按层存进二维vector中；
注意即使是空节点也要存进去，树中的空节点仍然存为NULL，空节点的子节点也全部存为NULL；
这样的储存方式保证了最后一层节点的数量*2-1必然是输出二维数组的宽度(每行的长度）；
之后对于得到的vector进行遍历，对于所有非空节点，进行字符串的替换。
注意到每层开始前有0，1，3，7。。。。个空位，即为2的n次方-1，记为b；
每行元素之间有1，3，7.。。。个空位，为（b+1）*2；
得到了元素位置的规律后进行字符串替换就可以了。
```
vector<vector<string>> printTree(TreeNode* root) 
    {
        bool next = true;
        vector<vector<TreeNode*>> Tree;
        vector<TreeNode*> row;
        vector<TreeNode*> update;
        row.push_back(root);
        while(next)
        {
            next = false;
            Tree.push_back(row);
            for(int i=0;i<row.size();i++)
            {
                if(row[i] == NULL)
                {
                    update.push_back(NULL);
                    update.push_back(NULL);
                }
                else
                {
                    next = true;
                    update.push_back(row[i]->left);
                    update.push_back(row[i]->right);
                }
            }
            row = update;
            update.clear();
        }
        Tree.erase(Tree.begin()+Tree.size()-1);
        int s = 2*Tree[Tree.size()-1].size()-1;
        vector<vector<string>> print;
        int b = 0;
        for(int i=0;i<Tree.size();i++)
        {
            vector<string> p(s,"");
            print.push_back(p);
        }
        for(int i = 0;i<Tree.size();i++)
            for(int j=0;j<Tree[i].size();j++)
            {
                b = pow(2,Tree.size()-i-1)-1;
                if(Tree[i][j] != NULL)
                    print[i][b + (b+1)*2*j] = to_string(Tree[i][j]->val);
            }
        return print;
    }
```