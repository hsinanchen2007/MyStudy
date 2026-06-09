### 解题思路
不用额外的空间去后序遍历。
最主要的知识点：“前驱节点”、“双指针”
主要实现思想：先找到前驱节点，将前驱节点的右孩子设置为当前节点（第一次找到其右孩子一定为NULL），再找到该前驱节点就能知道下一步该回到哪继续了。
前序、中序遍历都可实现。后序的实现较难，因为还需要倒叙输出当前节点的左节点到前驱节点的所有节点。
前序、中序每个节点最多遍历两次，后序需要4次（因为不用栈的话，倒叙输出将树倒叙后还需还原），所以时间复杂度是O(n)。

### 前序遍历代码
```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *node = root;
        while(node){
            if(node->left == NULL){
                ans.emplace_back(node->val);
                node = node->right;
            }else{
                TreeNode *pre = node->left;
                while(pre->right != NULL && pre->right != node){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = node;
                    ans.emplace_back(node->val);
                    node = node->left;
                }else{
                    pre->right = NULL;
                    node = node->right;
                }

            }
        }        
        return ans;
    }
};
```

### 中序遍历代码
```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *node = root;
        while(node){
            if(node->left == NULL){
                ans.emplace_back(node->val);
                node = node->right;
            }else{
                TreeNode *pre = node->left;
                while(pre->right != NULL && pre->right != node){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = node;
                    node = node->left;
                }else{
                    ans.emplace_back(node->val);
                    pre->right = NULL;
                    node = node->right;
                }

            }
        }        
        return ans;
    }
};
```
### 后序遍历代码

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
    vector<int> ans;

    void flashBack(TreeNode* t1,TreeNode* t2){
        if(t1 == t2)
            return;
        TreeNode* p = t1;
        TreeNode* q = p->right;
        do{
            TreeNode *temp = q->right;
            q->right = p;
            p = q;
            q = temp;
        }while(p != t2);
    }

    void printNode(TreeNode* t1,TreeNode* t2){
        flashBack(t1,t2);
        TreeNode *node = t2;
        while(true){
            ans.emplace_back(node->val);
            if(node == t1)
                break;
            node = node->right;
        }
        flashBack(t2,t1);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL){
            return ans;
        }
        TreeNode *tempNode = new TreeNode(-1);
        tempNode->left = root;
        TreeNode *node = tempNode;
        while(node){
            if(node->left == NULL){
                node = node->right;
            }else{
                TreeNode *pre = node->left;
                while(pre->right != NULL && pre->right != node){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = node;
                    node = node->left;
                }else{
                    printNode(node->left,pre);
                    pre->right = NULL;
                    node = node->right;
                }
            }

        }
        return ans;
    }
};
```