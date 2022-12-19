/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct List
{
    char *arr;
    size_t capacity;
    size_t size;
};

void CheckCapacity(struct List*plist)
{
    plist->capacity *= 2;
    plist->arr = (char*)realloc(plist->arr, sizeof(char)*(plist->capacity));
}

void pushList(struct List* plist, char a)
{
    if(plist->size == plist->capacity)
    {
        CheckCapacity(plist);
    }
    plist->arr[plist->size] = a;
    plist->size++;
}

void Split(struct List* plist,int num)
{
    int count = 0;
    int k = num;
    while(k /= 10)
    {
        count++;
    }
    count = pow(10,count);
    while(count)
    {
        pushList(plist, num/count+'0');
        num %= count;
        count /= 10;
    }
}

void Negative(struct List* plist,int num)
{
    pushList(plist, '-');
    num *= -1;
    if(num <= 9)
    {
        pushList(plist, num+'0');
    }
    else
    {
        Split(plist, num);
    }
}

void Ergodic(struct TreeNode *root, struct List* plist)
{
    if(root)
    {
        if(0 <= root->val && root->val <= 9)
        {
            pushList(plist, (root->val + '0'));
        }
        else if(root->val < 0)
        {
            Negative(plist,root->val);
        }
        else
        {
            Split(plist, root->val);
        }
        if(root->left)
        {
            pushList(plist,'(');
            Ergodic(root->left, plist);
        }
        if(root->right)
        {
            if(NULL == root->left)
            {
                 pushList(plist,'(');
                 pushList(plist,')');
            }
            pushList(plist,'(');
            Ergodic(root->right,plist);
        }
    }
    pushList(plist,')');
}

char * tree2str(struct TreeNode* t){
    struct List *k = malloc(sizeof(struct List));
    k->arr = (char*)malloc(sizeof(char)*10);
    k->capacity = 10;
    k->size = 0;
    Ergodic(t, k);
    k->arr[--k->size] = '\0';
    return k->arr;
}