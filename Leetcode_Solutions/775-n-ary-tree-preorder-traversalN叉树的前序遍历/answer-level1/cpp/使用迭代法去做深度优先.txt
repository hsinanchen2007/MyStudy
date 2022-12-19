# 首先本文是以实现迭代法为目标去做的
    当然可能会因为一些部分的内容，这里首先是考虑实现迭代法为目标。
    而在本方法中，定义了两个queue，一个是为了去记录剩下的Node,另一个是去记录该节点下面会有的其他的子节点
`class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root)return {};
        vector<int> res;
        queue<Node*> q{{root}};
        queue<Node*> q2;
        while(!q.empty()){
            Node* n=q.front();
            q.pop();
            res.push_back(n->val);
            for(auto i:n->children){
                if(i)q2.push(i);
            }
            while(!q.empty()){
                q2.push(q.front());q.pop();
            }
            swap(q,q2);
        }
        return res;
    }
};`