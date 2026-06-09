/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
void serializeTree(struct TreeNode *root, char *t)
{
    if (root == NULL) {
        strcat(t, "$#");
        return;
    }

    char temp[10] = { 0 };
    
    sprintf(temp, "%d#", root->val);
    strcat(t, temp);

    serializeTree(root->left, t);
    serializeTree(root->right, t);

    return; 
}

char *serialize(struct TreeNode *root)
{
    if (root == NULL) {
        return NULL;
    }
    const int treeMax = 100000;

    char *t = (char *)calloc(treeMax, sizeof(char));
    serializeTree(root, t); 

    return t;   
}

struct TreeNode *deserializeTree(char *t)
{
    char *temp = strtok(NULL, t);
    if (temp == NULL) {
        return NULL;
    }
    if (*temp == '$') {
        return NULL;
    }

    struct TreeNode *tree = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
    tree->val = atoi(temp);
    tree->left = deserializeTree(t);
    tree->right = deserializeTree(t);

    return tree; 
}

/** Decodes your encoded data to tree. */
struct TreeNode *deserialize(char *data)
{
    if (data == NULL) {
        return NULL;
    }

    const char dt[2] = "#";
    char *token = strtok(data, dt);

    struct TreeNode *tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    tree->val = atoi(token);
    tree->left = deserializeTree(dt);
    tree->right = deserializeTree(dt);

    return tree; 
}