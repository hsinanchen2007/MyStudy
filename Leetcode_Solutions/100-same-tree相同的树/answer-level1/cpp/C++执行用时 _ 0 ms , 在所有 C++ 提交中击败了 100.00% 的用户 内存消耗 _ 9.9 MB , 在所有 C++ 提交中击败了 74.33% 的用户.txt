class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr)
        {
            if(q == nullptr)
                return true;
            else
                return false;
        }
        if(q==nullptr)
        {
            if(p == nullptr)
                return true;
            else
                return false;
        }
        stack<TreeNode*> nodeStack1;
        stack<TreeNode*> nodeStack2;
        nodeStack1.push(p);
        nodeStack2.push(q);
        while(!nodeStack1.empty()&&!nodeStack2.empty())
        {
            TreeNode* node1 = nodeStack1.top();
            TreeNode* node2 = nodeStack2.top();
            nodeStack1.pop();
            nodeStack2.pop();
            if(node1->val == node2->val)
            {
                if(node1->right!=nullptr&&node2->right!=nullptr)
                {
                    nodeStack1.push(node1->right);
                    nodeStack2.push(node2->right);
                }
                else if(!(node1->right==nullptr&&node2->right==nullptr))
                    return false;
                if(node1->left!=nullptr&&node2->left!=nullptr)
                {
                    nodeStack1.push(node1->left);
                    nodeStack2.push(node2->left);
                }
                else if(!(node1->left==nullptr&&node2->left==nullptr))
                    return false;
            }
            else
                return false;
        }
        if(nodeStack1.empty()&&nodeStack2.empty())
            return true;
        else
            return false;
    }
};