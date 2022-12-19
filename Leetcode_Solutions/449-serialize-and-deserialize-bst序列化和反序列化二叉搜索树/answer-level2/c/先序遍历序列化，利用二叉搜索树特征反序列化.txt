对二叉树先序遍历序列化，这个很容易的。但是二叉树反序列化就比较困难了，需要组合才能生成树（例如先序+中序遍历），

但好在这里是二叉搜索树，是有排序特征的（排序后就是中序遍历了），所以是可以直接反序列化的


```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
#define N 100000
void store(int val, char* res) {
    int len = strlen(res);    
    char tmp[N] = {0};
    int pos = 0;
    while (val > 0) {
        int div = val % 10;
        pos += sprintf(tmp + pos, "%d", div);
        val = val / 10;
    }
    for (int i = strlen(tmp) - 1; i >= 0; i--) {
        res[len + strlen(tmp) - 1 - i] = tmp[i];
    }

    strcat(res, "#");

    return;
}
// 先序遍历
void preOrder(struct TreeNode* root, char* res) {
    if (root == NULL) {        
        return;
    }
    // 处理val
    store(root->val, res);
    preOrder(root->left, res);
    preOrder(root->right, res);
    return;
}

char* serialize(struct TreeNode* root) {
    char* res = (char*)calloc(N, sizeof(char));
    preOrder(root, res);   
    
    return res;
}

void insert(struct TreeNode** curNode, int val) {
    struct TreeNode* newNode = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    newNode->val = val;

    if (*curNode == NULL) {
        *curNode = newNode;
        return;
    }
    
    if ((*curNode)->val > val) {
        insert(&((*curNode)->left), val);
    } else {
        insert(&((*curNode)->right), val);
    }

    return;
    
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    int len = strlen(data);
    int val = 0;
    struct TreeNode* root = NULL; 

    for (int i = 0; i < len; i++) {
        if (data[i] == '#') {
            // 处理前面字符串            
            insert(&root, val);            
            val = 0;
        } else {
            val = val * 10 + data[i] - '0';
        }
    }

    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
```
