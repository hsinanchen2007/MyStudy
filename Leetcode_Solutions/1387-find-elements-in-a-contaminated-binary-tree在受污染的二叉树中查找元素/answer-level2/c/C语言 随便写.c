```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode FindElements;

void CreateTree(FindElements* root, int index) {
    if (root == NULL) {
        return ;
    }
    root->val = index;
    CreateTree(root->left, 2 * index + 1);
    CreateTree(root->right, 2 * index + 2);
}

FindElements* findElementsCreate(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    CreateTree(root, 0);
    return root;
}

bool findElementsFind(FindElements* obj, int target) {
    if (obj == NULL) {
        return false;
    }
    if (obj->val == target) {
        return true;
    }
    if (findElementsFind(obj->left, target)) {
        return true;
    }
    if (findElementsFind(obj->right, target)) {
        return true;
    }
    return false;
}

void findElementsFree(FindElements* obj) {
    return ;
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 
 * findElementsFree(obj);
*/

```