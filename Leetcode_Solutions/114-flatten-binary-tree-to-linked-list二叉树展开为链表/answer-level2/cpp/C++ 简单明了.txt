### 解题思路
新建一个栈用来保存节点数据

看一下题目的要求就是先序遍历 但是采用递归遍历会破坏结构
因此采用栈来保存

注意一定要先让右子树入栈 然后再放入左子树 这样才可以保证左子树 在右子树之前被遍历到

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
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;

        //新建工作指针
        TreeNode* pre = new TreeNode(0);

        //保存stack
        stack<TreeNode*> myStack;
        myStack.push(root);

        while(!myStack.empty())
        {
            //弹出栈顶
            TreeNode* cur = myStack.top();
            myStack.pop();
            pre->right = cur;
            pre->left = nullptr;
            pre = cur;

            //加入左右节点
            if(cur->right!= nullptr)
                myStack.push(cur->right);
            
            //加入顺序 左节点必须在下面
            if(cur->left != nullptr)
                myStack.push(cur->left);
        }
    }
};
```