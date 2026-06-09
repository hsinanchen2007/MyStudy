用一个flag（even_gradparent）来表示当前节点的父节点是否为偶。
把当前节点的子节点push入队列时，用此flag来决定是否把子节点的值加入最后的result中。
```
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int re = 0;
        if(!root) return re;
        queue<pair<bool, TreeNode*>> node_que;
        node_que.push(make_pair(false, root));
        while(!node_que.empty())
        {
            pair<bool, TreeNode*> curr = node_que.front();
            node_que.pop();
            TreeNode* curr_node = get<1>(curr);
            bool even_gradparent = get<0>(curr);
            bool even_parent = ((curr_node->val % 2) == 0);
            if(curr_node->left)
            {
                node_que.push(make_pair(even_parent, curr_node->left));
                if(even_gradparent)
                {
                    re += curr_node->left->val;
                }
            }
            if(curr_node->right)
            {
                node_que.push(make_pair(even_parent, curr_node->right));
                if(even_gradparent)
                {
                    re += curr_node->right->val;
                }
            }    
        }
        return re;
    }
};
```
