/* 二叉树的层次便利， 求每一行的最后一个元素就好了 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int g_num = 0;
int g_start = 0;
int g_end = 0;

typedef struct TreeNode Node;
typedef  struct NodeInfo {
    int floor;
    int val;
    Node* list;
} NODEINFO;

NODEINFO* g_nodeinfo = NULL;

int calTreeDepth(Node* root) {
    int depthleft = 0;
    int depthright = 0;

    if(root == NULL) {
        return 0;
    }
    g_num++;
    depthleft = calTreeDepth(root->left);
    depthright = calTreeDepth(root->right);

    return depthleft > depthright ? (depthleft + 1) : (depthright + 1);
}

void enquere(int floor, int val, Node* quere) {
    g_nodeinfo[g_end].val = val;
    g_nodeinfo[g_end].floor = floor;
    g_nodeinfo[g_end].list = quere;
    g_end++;

    return;
}

void dequere(NODEINFO* quere) {
    quere->val = g_nodeinfo[g_start].val;
    quere->floor = g_nodeinfo[g_start].floor;
    quere->list = g_nodeinfo[g_start].list;
    g_start++;
}

int* rightSideView(struct TreeNode* root, int* returnSize){
    int depth = 0;
    int** result = NULL;
    int* resultSize = NULL;
    NODEINFO tempInfo = {0};
    int* ret = NULL;

    if(root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    depth = calTreeDepth(root);
    result = (int**)calloc(depth, sizeof(int*));
    resultSize = (int*)calloc(depth, sizeof(int));
    for (int i=0; i<depth; i++) {
        result[i] = (int*)calloc(g_num, sizeof(int));
    }
    g_nodeinfo = (NODEINFO*)calloc(g_num, sizeof(NODEINFO));
    ret = (int*)calloc(depth, sizeof(int));
    enquere(0, root->val, root);
    while(g_start != g_end) {
        dequere(&tempInfo);
        result[tempInfo.floor][resultSize[tempInfo.floor]] = tempInfo.val;
        resultSize[tempInfo.floor] += 1;
        if(tempInfo.list ->left != NULL) {
            enquere(tempInfo.floor + 1, tempInfo.list->left->val, tempInfo.list->left);
        }
        if(tempInfo.list->right != NULL) {
            enquere(tempInfo.floor + 1, tempInfo.list->right->val, tempInfo.list->right);
        }
    }
    for(int i=0; i<depth; i++) {
        ret[i] = result[i][resultSize[i]-1];
    }
    for (int i=0; i<depth; i++) {
        free(result[i]);
    }
    free(g_nodeinfo);
    *returnSize = depth;
    return ret;
}