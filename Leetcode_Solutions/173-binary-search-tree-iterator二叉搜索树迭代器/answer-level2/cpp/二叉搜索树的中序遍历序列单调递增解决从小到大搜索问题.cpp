### 解题思路
1. 二叉搜索树的中序遍历序列是单调递增的。 
2. 利用二叉树的迭代方式的中序遍历，保存左子链，从而使用O(h)的内存。
3. 当执行next时，返回栈顶元素，并且遍历栈顶元素的右子树


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
class BSTIterator {
private:
    stack<TreeNode*> tstack;
public:
    BSTIterator(TreeNode* root) {
        while(root != nullptr){
            tstack.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* tTopElem = tstack.top();
        int tTopVal = tTopElem->val;
        tstack.pop();
        if(tTopElem->right != nullptr){
            tTopElem = tTopElem->right;
            while(tTopElem != nullptr){
                tstack.push(tTopElem);
                tTopElem = tTopElem->left;
            }
        }
        return tTopVal;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !tstack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```