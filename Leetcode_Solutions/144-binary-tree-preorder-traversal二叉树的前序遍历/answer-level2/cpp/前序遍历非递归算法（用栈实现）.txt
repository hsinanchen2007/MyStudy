1. 时间复杂度O(n)
```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        if(root==nullptr) return ans;
        stack<TreeNode*>  s;    //使用栈空间完成前序遍历的非递归算法
        while((s.empty()==0) || root!=nullptr)
        {
            if(root)   //如果节点不为空，那就访问并且入栈，继续访问它的左孩子
            {
                ans.push_back(root->val);    //访问
                s.push(root);               //入栈
                root=root->left;           //访问左孩子
            }
            else     //如果当前节点为空，取出栈顶节点，访问它的右子树
            {
                root=s.top();   //获取栈顶元素
                s.pop();        //栈顶元素出栈，注意直接用pop()只能出栈，无法获取返回值 
                root=root->right;
            }

        }
        return ans;
    }
};
```
