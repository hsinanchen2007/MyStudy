思路：如果知道二叉树的深度求解办法，那么本题很容易求解，只要用一个Vector保存子节点；另一个容器保存子节点的深度即可
int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        vector<int> depth;
        int maxdepth=0;
        for(int i=0;i<root->children.size();i++)
        {
            //遍历树的每一个节点，找出所有子节点的最大深度，用一个Vector保存期深度
            int nodeDepth=maxDepth(root->children[i]);
            depth.push_back(nodeDepth);         
        }
        for(int i=0;i<depth.size();i++)
        {
            if(maxdepth<=depth[i])
                maxdepth=depth[i];            
        }
        return maxdepth+1;
    }