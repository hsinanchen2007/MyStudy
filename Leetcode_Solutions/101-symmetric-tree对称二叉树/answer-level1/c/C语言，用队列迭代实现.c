#define MAXSIZE 500

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }

    struct TreeNode *q[MAXSIZE];
    int front = 0;
    int rear = 0;

    q[rear++] = root;
    q[rear++] = root;

    while (front != rear) {
        struct TreeNode *t1 = q[front++];
        struct TreeNode *t2 = q[front++];

        if (t1 == NULL && t2 == NULL) {
            continue;
        }
        if (t1 == NULL || t2 == NULL) {
            return false;
        }
        if (t1->val != t2->val) {
            return false;
        }
        q[rear++] = t1->left;
        q[rear++] = t2->right;
        q[rear++] = t1->right;
        q[rear++] = t2->left;
    }
    return true;
}