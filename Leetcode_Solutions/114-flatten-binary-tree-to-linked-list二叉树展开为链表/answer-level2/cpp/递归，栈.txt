### 解题思路
这里用到的是后序遍历。因为是先把左子树换到右子树来，再把原来的右子树连接在现在的右子树上，

注意连接的时候一定要while一下，

使用栈的方法时要把节点保存在栈中。 再依次取出来交换左节点位置。
记住最后要把root指向right节点。


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
class Solution {
public:
    // 执行用时 :16 ms, 在所有 C++ 提交中击败了5.45% 的用户
    // 内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        if(!root->left&&!root->right) return;
        flatten(root->left);
        flatten(root->right);

        //把右子树保存起来。然后把左子树移动到右子树上挂着。把左子树设为nullptr
        TreeNode* temp = root->right;        
        root->right = root->left;
        root->left = nullptr;

        //把右子树和temp相连时，要保证迭代到最终的一个叶子节点。再连接。
        while(root->right) root = root->right;
        root->right = temp;
    }


    // 执行用时 :8 ms, 在所有 C++ 提交中击败了66.21% 的用户
    // 内存消耗 :8.4 MB, 在所有 C++ 提交中击败了100.00%的用户
    void flatten(TreeNode* root){
        if(!root) return;
        stack<TreeNode*> temp;//利用一个栈来保存遍历到的节点。
        while(root||!temp.empty()){//注意这里是root不为nullptr或者栈不为空的情况
            while(root){//一直向左走，把节点先压进去。
                temp.push(root);
                root = root->left;
            }
            if(!temp.empty()){//若此时栈里面不为空
                TreeNode* node = temp.top();//取出栈顶节点。
                temp.pop();
                
                //把左边连到右边
                TreeNode* right = node->right;
                node->right = node->left;
                node->left = nullptr;
 
                //再把right连接在后面
                while(node->right) node = node->right;
                node->right = right;

                //换到右边上去。
                root = right;

            }
        }
    }
};
```