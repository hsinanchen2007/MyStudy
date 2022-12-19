### 解题思路

主体代码非常简单，就是通过递归，来遍历二叉树

```c
void inorder(struct TreeNode *root, Darry *darr)
{
    if ( root == NULL) return;
    inorder(root->left, darr);
    Append(darr, root->val);
    inorder(root->right, darr);
}
```

但是问题在于实现不知道二叉树有多大。对于其他编程语言，基本都自带了动态Array，所以相对简单。

然而C语言没有，因此就需要专门定义一个动态数组，包括创建，增加，和扩大这三个函数。

其实大小设置为100. 避免多次申请浪费时间。

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    int *arr;
    int count; //当前容量
    int size; //总大小
} Darry;

//创建数据结构
Darry *CreateDarray(int size)
{
    Darry *darr;
    darr = (Darry *)malloc( sizeof(Darry) );
    darr->arr = (int*)malloc( sizeof(int) * size);
    darr->size = size;
    darr->count = 0;
    return darr;
}

//扩大
bool *Resize(Darry *darr){
    int new_size = darr->size * 2;
    int *arr = (int*)malloc( sizeof(int) * new_size);
    memcpy(arr, darr->arr, sizeof(int) * darr->size );
    darr->size = new_size;
    free(darr->arr);
    darr->arr = arr;
    return true;
}

bool Append(Darry *darr, int data)
{
    if (darr->count == darr->size ){
        if ( ! ( Resize(darr)) ) return false;
    }
    darr->arr[darr->count] = data;
    darr->count+=1;
    return true;
}

void inorder(struct TreeNode *root, Darry *darr)
{
    if ( root == NULL) return;
    inorder(root->left, darr);
    Append(darr, root->val);
    inorder(root->right, darr);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){

    Darry *darr = CreateDarray(100);
    inorder(root, darr);
    
    int *arr = darr->arr;
    *returnSize = darr->count;
    return arr;

}
```