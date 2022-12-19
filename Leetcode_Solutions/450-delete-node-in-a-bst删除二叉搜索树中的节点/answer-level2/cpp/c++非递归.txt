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
    TreeNode* findNode(TreeNode* root, int key, TreeNode* &father, bool &isLeft){
        TreeNode* node = root;
        while(node && node->val != key){
            father = node;
            if(key > node->val){
                node = node->right;
                isLeft = false;
            }
            else{
                node = node->left;
                isLeft = true;
            }
        }
        return node;
    }

    TreeNode* remove(TreeNode* root, TreeNode* node, TreeNode* father, bool isLeft){

        TreeNode* left = node->left;    //被删除节点的左子树
        TreeNode* right = node->right;  //被删除节点的右子树

        if(right != nullptr){   //右子树存在

            // 将左子树移动到右字数最小叶子的左孩子位置
            TreeNode* insert_position = right;
            while(insert_position->left != nullptr)
                insert_position = insert_position->left;
            insert_position->left = left;
            if(node == root)
                return right;

            // 提拔右子树
            if(isLeft)
                father->left = right;
            else
                father->right = right;
        }else{  //右子树不存在，不需要移动
            if(node == root)    //如果删除的是根节点，直接返回左子树
                return left;

            if(isLeft)  //提拔左子树
                father->left = left;
            else
                father->right = left;
        }
        delete node;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node, *father;// node表示被删除节点， father表示被删除节点的父亲
        bool isLeft;    // 标识被删除节点是其父亲的左孩子
        
        node = findNode(root, key, father, isLeft);
        if(node == nullptr)
            return root;
        root = remove(root,node, father, isLeft);
        return root;
    }
};
```
