* 递归也是一种方法，但是由于性能问题，我们尽可能不使用递归的算法解决
* 其实用什么方法遍历不重要
* 先贴上栈的中序遍历代码作为参考，该代码同样可以通过第94题，二叉树的中序遍历那道题
```
//用栈中序遍历二叉树，将遍历结果返回一个数组
        
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        std::stack<TreeNode *> stack;
        std::vector<int> ans;
        TreeNode *current = root;//利用current来遍历
        while (current||!stack.empty()) {
            while (current!=NULL){
                //不断向左走，并且压栈
                stack.push(current);
                current=current->left;
            }
            //走完，此时栈顶是没有左子树的最左边的树，访问，出栈并压入右子树
            current=stack.top();
            ans.push_back(current->val);
            stack.pop();
            current = current->right;
        }
        return ans;
    }
};
```
* 只需要改一行核心代码就可以实现树的翻转
    * 将current = current->right;改为current = current->left;因为之前已经交换过一次，为了正确遍历，此时应该访问左孩子，而非右孩子
    * 详情代码如下
```cpp
class Solution {
public:
    void swapChild(TreeNode* current){
        //先把根节点的左右翻转
        TreeNode *temp  = current->left;
        current->left=current->right;
        current->right=temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *current = root;
        //利用栈来保存其还没翻转的子树
        stack<TreeNode*> stack;
        while(current||stack.size()){
            //利用栈的中序遍历
            while (current){
                stack.push(current);
                current=current->left;
            }
            current = stack.top();
            stack.pop();
            swapChild(current);
            current = current->left;//传统的中序遍历这里应该是right，但是其实前面交换过左右孩子结点，所以这里应该是left
        }
        return root;
    }
};
```