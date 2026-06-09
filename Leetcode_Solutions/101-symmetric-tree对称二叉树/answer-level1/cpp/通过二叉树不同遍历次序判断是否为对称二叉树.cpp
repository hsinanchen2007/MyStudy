一个对称二叉树，其先序遍历（根节点-->left-->right) 和 先序遍历（根节点-->right-->left) 所走的 “路径” 是一样的。
利用这一点，使用一个队列存储路径。第一遍先序遍历（根节点-->left-->right)入队，第二遍（根节点-->right-->left)出队。
最后判断队列是否为空。
时间复杂度O(n), 空间复杂度O(n)。
也可用中序、后序遍历。
```c++
class Solution {
private:
    queue<int> route;
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        pre_order_left(root);
        pre_order_right(root);
        if(route.empty())
            return true;
        return false;
    }
    // 先序遍历（根节点-->left-->right)
    void pre_order_left(TreeNode* root){
        if(!root) 
        {
            route.push(-1);
            return;
        }
        route.push(root->val);
        pre_order_left(root->left);
        pre_order_left(root->right);
    }
    // 先序遍历（根节点-->right-->left)
    void pre_order_right(TreeNode* root){
        if(!root) 
        {
            if(route.front() == -1)
            route.pop();
            return;
        }
        if(route.front() == root->val)
            route.pop();
        pre_order_right(root->right);
        pre_order_right(root->left);
    }
};
```
