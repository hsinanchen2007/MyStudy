### 解题思路
此处撰写解题思路

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
    // 递归解法
    // 返回节点p和节点q的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        // 递归遍历每一个节点的左子树和右子树有没有p、q的最近公共祖先
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 如果左子树和右子树同时存在p、q的最近公共祖先，那么p、q一定各在一个子树，最近公共祖先就是本节点
        if (left != nullptr && right != nullptr) return root;
        // 如果p、q都在其中一个子树中，那么另一个子树的返回必定为空
        return left == nullptr ? right : left;
    }
    
    // 求出p q两个节点的路径存入栈中。再比较栈中元素，找到第一个相同的节点，即为二者的最近公共祖先节点。递归求解
    // 返回节点p和节点q的最近公共祖先
    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ppath; // 保存p路径
        stack<TreeNode*> qpath; // 保存q路径
        
        getpath(root,p,ppath);  // 递归计算p路径
        getpath(root,q,qpath);  // 递归计算q路径
        
        // p路径的长度 不等于 q路径的长度，清除掉长度较长的栈的多余元素，因为最近公共祖先之前的路径都是一样的。
        while (ppath.size() != qpath.size()) {
            if (ppath.size() > qpath.size())
                ppath.pop();
            else
                qpath.pop();
        }
        // 两栈栈顶比较，不一样就都出栈，找到第一个相同的节点。
        while(ppath.top() != qpath.top())
        {
            ppath.pop();
            qpath.pop();
        }
        return ppath.top();
    }
    
    // 递归计算，从树root中，查找节点node的路径，保存在path栈中，root在栈底，node在栈顶。
    bool getpath(TreeNode* root, TreeNode* node, stack<TreeNode*>& path)
    {
        if(root == NULL)
            return false;
        path.push(root);
        if(root == node)
            return true;
        
        if(getpath(root->left,node,path))
            return true;
        if(getpath(root->right,node,path))
            return true;
        
        path.pop();
        return false;       
    }
    
    // 求出p q两个节点的路径存入栈中。再比较栈中元素，找到第一个相同的节点，即为二者的最近公共祖先节点。dfs求解
    // 返回节点p和节点q的最近公共祖先
    TreeNode* lowestCommonAncestor_3(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return root;
        }
        stack<TreeNode*> s1;        // 保存p路径
        stack<TreeNode*> s2;        // 保存q路径
        TreeNode* cur1 = root;      // 求p路径的当前节点，指向根节点
        TreeNode* cur2 = root;      // 求q路径的当前节点，指向根节点
        TreeNode* prePop1 = root;
        TreeNode* prePop2 = root;
        s1.push(root);
        s2.push(root);
        
        while (cur1 != p) {
            // 当前节点没有左子树也没有右子树，出栈回退到上一个节点
            if (!cur1 -> left && !cur1 -> right) {
                s1.pop();
                prePop1 = cur1;
                cur1 = s1.top();
                continue;
            } 
            // 
            if(prePop1 == cur1 -> right || (prePop1 == cur1 -> left && cur1 -> right == NULL)){
                s1.pop();
                prePop1 = cur1;
                cur1 = s1.top();
                continue;
            }  
            if (cur1 -> left == NULL || prePop1 == cur1 -> left) {
                if(cur1 -> right){
                    s1.push(cur1 -> right);
                }
                else{
                    s1.pop();
                    prePop1 = cur1;
                }
                cur1 = s1.top();
                continue;
            }
            if(cur1 -> left){
                s1.push(cur1 -> left);
            }
            cur1 = s1.top();
        }

        while(cur2 != q){
            if(!cur2 -> left && !cur2 -> right){
                s2.pop();
                prePop2 = cur2;
                cur2 = s2.top();
                continue;
            }
            if(prePop2 == cur2 -> right || (prePop2 == cur2 -> left && cur2 -> right == NULL)){
                s2.pop();
                prePop2 = cur2;
                cur2 = s2.top();
                continue;
            }
            if(cur2 -> left == NULL || prePop2 == cur2 -> left){
                if(cur2 -> right){
                    s2.push(cur2 -> right);
                }
                else{
                    s2.pop();
                    prePop2 = cur2;
                }
                cur2 = s2.top();
                continue;
            }
            if(cur2 -> left){
                s2.push(cur2 -> left);
            }
            cur2 = s2.top();
        }      
        int l = s1.size() - s2.size();
        if(l > 0){
            while(l--){
                s1.pop();
            }
        }
        else{
            l = -l;
            while(l--){
                s2.pop();
            }
        }
        while(!s1.empty() && !s2.empty()){
            if(s1.top() == s2.top()){
                return s1.top();
            }
            else{
                s1.pop();
                s2.pop();
            }
        }
        return root;
    }
    
    /************************************************************************************/
    
    // 先序遍历
    void _pre_tra(TreeNode *x) {
        if(x) {
            cout << x->val << " ";
            _pre_tra(x->left);
            _pre_tra(x->right);
        }
    }
    
    // 中序遍历
    void _in_tra(TreeNode *x) {
        if(x) {
            _in_tra(x->left);
            cout << x->val << " ";
            _in_tra(x->right);
        }
    }
    
    // 后序遍历
    void _post_tra(TreeNode *x) {
        if(x) {
            _post_tra(x->left);
            _post_tra(x->right);
            cout << x->val << " ";
        }
    }
    
    // 按层遍历
    void level_traversal(TreeNode *root) {
        queue<TreeNode*> que;
        if (root == NULL) return;
        que.push(root);
        // 队列que非空，使用队列先进先出的特性
        while (!que.empty()) {
            // 当前节点访问队首元素
            TreeNode *cur = que.front();
            // 出队
            que.pop();
            cout << cur->val << " ";
            // 左节点存在，入队，右节点存在，入队。
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        cout << endl;
    }
};





#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) return root;
    return left == nullptr ? right : left;
}

int main() {
    TreeNode node1 = TreeNode(3); TreeNode node2 = TreeNode(5);
    TreeNode node3 = TreeNode(1); TreeNode node4 = TreeNode(6); 
    TreeNode node5 = TreeNode(2); TreeNode node6 = TreeNode(0);
    TreeNode node7 = TreeNode(8); TreeNode node8 = TreeNode(7); 
    TreeNode node9 = TreeNode(4); 
    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5; 
    node5.left = &node8; node5.right = &node9;
    node3.left = &node6; node3.right = &node7;
    TreeNode *root = &node1;
    TreeNode *p = &node2; TreeNode *q = &node3;
    TreeNode *res = lowestCommonAncestor(root, p, q);
    cout << res->val << endl;
}








```