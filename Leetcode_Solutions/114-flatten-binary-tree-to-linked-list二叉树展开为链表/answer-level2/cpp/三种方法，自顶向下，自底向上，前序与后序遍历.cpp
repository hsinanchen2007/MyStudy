### 解题思路
三种思路
3. 自底向上，右-左-中 的 循环后序遍历
2. 自顶向下，存储左右节点的循环前序遍历
1. 不断将左子树接到右子树的地方，然后将右子树接到左子树的最右节点

[参考](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26/)

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26/

class Solution {
public:

    //解法3-自底向上， 利用栈的左右交换的后序遍历
    //前序遍历结果：1->2->3->4......
    //后序遍历（先右再左）结果：6-5-4-3-2-1, 遍历到当前，将当前cur的right设为pre,
    //即： 6<-5<-4<-3<-2<-1 
    //【注意：解法2中是设置pre的right为当前】
    void flatten(TreeNode* root){
        stack<pair<TreeNode*, bool>> mStack;
        mStack.push(make_pair(root, false));
        TreeNode* pre = nullptr;
        while(!mStack.empty()){
            TreeNode* cur = mStack.top().first;
            bool visited = mStack.top().second;
            mStack.pop();
            if(cur!=nullptr){
                if(visited){
                    //do sth.
                    cur->right = pre;
                    cur->left = nullptr;
                    pre = cur;
                }
                else{
                    //push左右子节点，右节点先弹出访问
                    mStack.push(make_pair(cur, true));
                    mStack.push(make_pair(cur->left, false));
                    mStack.push(make_pair(cur->right, false));
                }
            }
        }
    }



    //解法2-利用栈的前序遍历，保存了左右节点，链表实质就是前序遍历的结果
    void flatten2(TreeNode* root) {
        stack<TreeNode*> mStack;
        mStack.push(root);
        TreeNode* pre = nullptr;
        while(!mStack.empty()){
            TreeNode* cur = mStack.top();
            mStack.pop();
            if(cur!=nullptr){
                //保存左右节点
                mStack.push(cur->right);
                mStack.push(cur->left);
                if(pre!=nullptr){
                    //将前一个节点的右子树设为当前，左子树设为空
                    pre->right = cur;
                    pre->left = nullptr;
                }
                pre = cur;
            }
        }
    }

    //解法1-不断将左子树接到右子树的地方，然后将右子树接到左子树的最右节点
    void flatten1(TreeNode* root) {
        while(root!=nullptr){
            if(root->left==nullptr){
                root = root->right;
            }
            else{
                //找到左子树的最右边节点
                TreeNode* leftSubtreeRight = root->left;
                while(leftSubtreeRight->right!=nullptr){
                    leftSubtreeRight = leftSubtreeRight->right;
                }
                //将root 右子树接到左子树最右边节点
                leftSubtreeRight->right = root->right;
                //将左子树变为右子树
                root->right = root->left;
                //左子树置空
                root->left = nullptr;
                //下一个节点
                root = root->right;
            }

        }
    }
};
```