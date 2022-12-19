贡献个题解，写的有点复杂
```
#define MAX_SIZE 8501
char g_Res[MAX_SIZE];
char g_Tmp[MAX_SIZE];
char g_Mid[MAX_SIZE];
void InitChr(void)
{
    g_Res[0] = '\0';
    g_Tmp[0] = '\0';
    g_Mid[0] = '\0';
    return;
}
void RefreshRes(void)
{
    int len = strlen(g_Tmp);
    for (int i = 0; i < len; ++i) {
        g_Mid[i] = g_Tmp[len - i - 1];
    }
    g_Mid[len] = '\0';
    if (strlen(g_Res) == 0) {
        memcpy(g_Res, g_Mid, len);
        g_Res[len] = '\0';
    } else {
        if (strcmp(g_Res, g_Mid) > 0) {
            memcpy(g_Res, g_Mid, len);
            g_Res[len] = '\0';
        }
    }
    return;
}
void MyDfs(struct TreeNode* node, int tmpIndex)
{
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
       // printf("enter leaf, %d\n", node->val);
        g_Tmp[tmpIndex++] = (char)node->val + 'a';
        g_Tmp[tmpIndex] = '\0';
        RefreshRes();
        return;
    }
    g_Tmp[tmpIndex++] = (char)node->val + 'a';
    if (node->left != NULL) {
        MyDfs(node->left, tmpIndex);
    }
    if (node->right != NULL) {
        MyDfs(node->right, tmpIndex);
    }
    return;
}
char * smallestFromLeaf(struct TreeNode* root){
    /* 树的前序遍历 */
    InitChr();
    MyDfs(root, 0);
    int len = strlen(g_Res);
    //printf("len %d\n", len);
    char *rtnArr = (char *)calloc(len + 1, sizeof(char));
    for (int i = 0; i < len; ++i) {
        rtnArr[i] = g_Res[i];
        //printf("%c ", rtnArr[i]);
    }
    rtnArr[len] = '\0';
    return rtnArr;
}
```
