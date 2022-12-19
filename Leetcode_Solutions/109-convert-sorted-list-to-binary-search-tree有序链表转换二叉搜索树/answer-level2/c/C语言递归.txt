```
static struct TreeNode *NewTree(void)
{
    struct TreeNode *tree = NULL;

    tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (tree == NULL) {
        return NULL;
    }
    memset(tree, 0, sizeof(struct TreeNode));
    return tree;
}

static struct TreeNode *GetBstFrmArray(int *array, int len)
{
    struct TreeNode *result = NULL;

    if (len == 0) {
        return NULL;
    }
    if (len == 1) {
        result = NewTree();
        result->val = array[0];
        return result;
    }
    if (len == 2) {
        result = NewTree();
        result->val = array[len / 2];
        result->left = GetBstFrmArray(array, len / 2);
        result->right = NULL;
        return result;
    }

    result = NewTree();
    result->val = array[len / 2];
    result->left = GetBstFrmArray(array, len / 2);
    result->right = GetBstFrmArray(&array[len / 2 + 1], len - len / 2 - 1);
    return result;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    int i = 0;
    int listLen = 0;
    int *listArray = NULL;
    struct ListNode *list = head;
    struct TreeNode *result = NULL;

    if (head == NULL) {
        return NULL;
    }

    while (list != NULL) {
        listLen++;
        list = list->next;
    }
    listArray = (int *)malloc(listLen * sizeof(int));
    if (listArray == NULL) {
        return NULL;
    }
    list = head;
    while (list != NULL) {
        listArray[i++] = list->val;
        list = list->next;
    }

    result = GetBstFrmArray(listArray, listLen);
    return result;
}
```
