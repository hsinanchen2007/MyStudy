```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> stk;
        TreeNode *node = root;
        while(node != NULL || !stk.empty()){
            //一直遍历找到最左边的结点
            while(node != NULL){
                stk.push(node);
                node = node->left;
            }

            //此时已到达最深且最左的结点
            node = stk.top();
            
            //此时node有两种情况
            if(node->right == NULL){
                //1.node就是最左的叶子结点
                //  所以可以直接输出node了
                stk.pop();
                vec.emplace_back(node->val);
                
                //node弹出去以后, 此时栈顶就是node的父亲结点
                //因为是后续遍历, 所以在输出node的父亲结点前要看看node的父亲结点有没有右孩子(或者右子树), 也就是看看node有没有兄弟
                while(!stk.empty()){
                    if(stk.top()->left == node && stk.top()->right != NULL){
                        //1.1如果node是左孩子且有兄弟, 则开始遍历node兄弟
                        node = stk.top()->right;
                        break;
                    }
                    else{
                        //1.2如果node没有兄弟, 或者node是有孩子的时候, 就可以直接输出栈顶的node的父亲结点了
                        //   因为输出node的父亲结点后, node就变成了node的父亲结点
                        //   所以此时逻辑要再次回到这个while, 看看node有没有兄弟
                        //   只有在以下两种条件的时候才会退出这个while：
                        //   (1)因为是后序遍历, 所以要先输出右孩子, 所以要找到node的兄弟才能退出while
                        //   (2)栈空了, 说明root没有右孩子
                        node = stk.top();
                        stk.pop();
                        vec.emplace_back(node->val);
                    }
                }
                if(stk.empty()) node = NULL;  //当满足1.2(2)条件时, 栈就空了, 所以为了退出最外层的while, 要令node=NULL
            }
            else{
                //2.node是最左的中间结点, 也就是node还有个右孩子(当然也可能是右子树)
                //  此时开始遍历node的右子树
                node = node->right;
            }
        }
        return vec;
    }
};
```
