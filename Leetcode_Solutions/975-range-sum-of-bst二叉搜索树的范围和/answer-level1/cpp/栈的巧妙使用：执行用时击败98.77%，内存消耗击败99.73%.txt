### 解题思路
本题实质：考查树的**中序遍历**，中序遍历三个操作——左操作、中操作、右操作
本题解法：入栈法求解
执行结果：如下图
![image.png](https://pic.leetcode-cn.com/bbf4808addb98d71addefbe86524430d383714f8039f921b3b30eead850cd17c-image.png)

注意事项：在每次将当前结点的左孩子或右孩子入栈后，要记得**断链**，即断掉当前结点指向左孩子或右孩子的指针，并跟新当前结点
代码讲解：如下，每步关键操作均有注释，思路清晰

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        //此题考查中序遍历：入栈法求解
        //中序遍历共三个操作：左操作、中操作、右操作

        //特殊情况：根节点root为空
        if(!root)
            return 0;
        
        //栈的声明，并将根节点入栈
        stack<TreeNode *> tree_node;
        tree_node.push(root);

        TreeNode *cur = root;//当前要处理的节点
        TreeNode *left = NULL;//当前结点的左孩子结点
        TreeNode *right = NULL;//当前结点的右孩子结点
        int sum = 0;
        while(!tree_node.empty()){
            if(cur->left){
                //左操作：先一直看左孩子
                tree_node.push(cur->left);
                left = cur->left;
                cur->left = NULL;//断链操作
                cur = left;
            }
            else{
                //中操作：当前结点的左孩子，则开始出栈
                cur = tree_node.top();
                tree_node.pop();

                if((cur->val >= L) && (cur->val <= R))
                    sum += cur->val;

                if(cur->val > R)
                    break;//因为是二叉搜索树，满足排序关系，故当前结点的值大于R，直接终止循环

                //右操作：如果当前结点有右孩子，则继续入栈
                if(cur->right){
                    tree_node.push(cur->right);
                    right = cur->right;
                    cur->right = NULL;//断链操作
                    cur = right;
                }
            }
        }
        return sum;
    }
};
```