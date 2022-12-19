/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 void *DoNextNode(struct TreeNode *t, char *ret)
 {
    int val = t->val;
    char temp[20] = {0};
    sprintf(temp, "%d", val);
    strcat(ret, temp);

     if (t->left != NULL) {
        strcat(ret, "(");
        DoNextNode(t->left, ret);
        strcat(ret, ")");
     } 

     if (t->left == NULL && t->right != NULL) {
        strcat(ret, "()");
        strcat(ret, "(");
        DoNextNode(t->right, ret);
        strcat(ret, ")");      
     } else if (t->right != NULL){
        strcat(ret, "(");
        DoNextNode(t->right, ret);
        strcat(ret, ")"); 
     }
     return;
 }

char * tree2str(struct TreeNode* t){
    if (t == NULL) {
        return "";
    }

    char *ret = malloc(sizeof(char *) * 10000);
    memset(ret, 0, sizeof(char *) * 10000);
    DoNextNode(t, ret);
    return ret;
}