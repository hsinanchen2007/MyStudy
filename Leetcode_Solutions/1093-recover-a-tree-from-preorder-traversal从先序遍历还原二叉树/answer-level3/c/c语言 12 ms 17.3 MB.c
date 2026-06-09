/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ha[10000][2] = {{0}};
int j = 0;
int num = 0;
void DFS(struct TreeNode* root, struct TreeNode* next) {
    int i = 0;
    int a = num;
    //printf("a %d\n", a);
    if (num >= j) {
        return;
    }
    //printf("num %d, root %d next %d\n", num, root->val, next->val);
    //printf("ha[num + 1][1] %d, ha[num][1] %d\n", ha[num + 1][1], ha[num][1]);
    //printf("ha[num + 1][0] %d, ha[num][0] %d\n", ha[num + 1][0], ha[num][0]);
    if (ha[num + 1][1] == ha[num][1] + 1) {
        //printf("1\n");
        struct TreeNode* tmp1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        memset(tmp1, 0, sizeof(struct TreeNode));
        next->left = tmp1;
        tmp1->val = ha[num + 1][0];
        num++;
        
        DFS(next, tmp1);
    }
    if ((num == a) && (ha[num + 1][1] == ha[num][1])) {
        //("2\n");
        struct TreeNode* tmp2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        memset(tmp2, 0, sizeof(struct TreeNode));
        root->right = tmp2;
        tmp2->val = ha[num + 1][0];
        num++;
        DFS(root, tmp2);
    }
    //printf("1ha[num + 1][1] %d, ha[a][1] %d\n", ha[num + 1][1], ha[a][1]);
    //printf("1ha[num + 1][0] %d, ha[a][0] %d\n", ha[num + 1][0], ha[a][0]);
    if ((num != a) && (ha[num + 1][1] == ha[a][1] + 1)) {
        //printf("3\n");
        struct TreeNode* tmp3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        memset(tmp3, 0, sizeof(struct TreeNode));
        next->right = tmp3;
        tmp3->val = ha[num + 1][0];
        num++;
        DFS(root, tmp3);
    }
    //printf("return\n");
    return;
}
struct TreeNode* recoverFromPreorder(char * S){
    int len = strlen(S);
    int i = 0;
    j = 0;
    int q = 0;
    int tmp = 0;
    num = 0;
    char w[9] = {0};
    int c = 0;
    ha[0][0] = S[0] - '0';
    ha[0][1] = 0;
    for (i = 0; i < 10000; i++) {
        ha[i][0] = 0;
        ha[i][1] = 0;
    }
    for (i = 0; i < len; i++) {
        if (S[i] != '-') {
            for (q = 0; q < 9; q++) {
                 w[q] = '0';
            }
            c = 0;
            while ((S[i] != '-') && (S[i] != '\0')) {
                w[c] = S[i] - '0';
                c++;
                i++;
            }
            c--;
            i--;
            for (int z = c; z >= 0; z--) {
                ha[j][0] = ha[j][0] + w[z] * (int)pow(10, c - z);
            }
            ha[j][1] = i - tmp - c;
            tmp = i + 1;
            j++;
        }
    }
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(root, 0, sizeof(struct TreeNode));
    root->val = ha[0][0];
    if (len == 1) {
        return root;
    }
    DFS(root, root);
    return root;
}