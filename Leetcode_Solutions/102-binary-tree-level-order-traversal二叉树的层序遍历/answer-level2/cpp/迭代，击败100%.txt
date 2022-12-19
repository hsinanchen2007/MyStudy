迭代遍历二叉树， 每次压入结点， 层级+1， 每次弹出节点层级-1。
当节点没有右子树的时候， 弹出节点，层级减1， 在当前层级记录该节点值。
当节点有右子树时，不直接弹出节点，否则弹出后， 再回溯时，层级就不对了。而是弹出后，把右子树置NULL,再压入堆栈.

代码:
class Solution {
public:
        vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vret;
        vector<TreeNode*> nodeV;
        TreeNode* temp;
        int level = 0;

        while (root)
        {
            level++;
            nodeV.push_back(root);
            root = root->left;
            if (vret.size() < level)
            {
                vret.push_back({});
            }
        }

        while (nodeV.size())
        {
            root= nodeV.back();
            nodeV.pop_back();

            if (root->right)
            {
                temp=root->right;
                root->right=NULL;
                nodeV.push_back(root);
                while(temp)
                {
                    level++;
                    nodeV.push_back(temp);
                    temp=temp->left;
                    if (vret.size() < level)
                    {
                        vret.push_back({});
                    }
                }
            }
            else
            {
                level--;
                vret[level].push_back(root->val);
            }
        }

        return vret;
    }
};
