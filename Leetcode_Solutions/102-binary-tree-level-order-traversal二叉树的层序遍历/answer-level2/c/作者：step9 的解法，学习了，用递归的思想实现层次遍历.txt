
作者：step9 的解法，学习了，用递归的思想实现层次遍历
/**

Definition for a binary tree node.
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
};
*/
int CountTreeDepth(struct TreeNode* root)
{
int left = 0;
int right = 0;
int rslt = 1;

if ((root->left == NULL)&&(root->right == NULL)) {
    return rslt;
}

if (root->left != NULL) {
    left = CountTreeDepth(root->left);
} 
if (root->right != NULL) {
    right = CountTreeDepth(root->right);
}

rslt += (left > right)? left : right;

return rslt;
}
//
void CountTreeNode(struct TreeNode* root, int depth, int nodecout[] )
{
nodecout[depth] += 1;

if ((root->left == NULL)&&(root->right == NULL)) {
    return;
} 

depth += 1;
if (root->left != NULL) {
    CountTreeNode(root->left, depth, nodecout);
}
if (root->right != NULL) {
    CountTreeNode(root->right, depth, nodecout);
}

return;
}

void SaveVal(struct TreeNode* root, int depth, int pos[], int **rslt )
{
int idx2 = pos[depth];

rslt[depth][idx2] = root->val;
pos[depth] += 1;//当前深度的结点加1

if ((root->left == NULL)&&(root->right == NULL)) {
    return;
} 

depth += 1;//深度加1

if (root->left != NULL) {
    SaveVal(root->left, depth, pos, rslt);
}
if (root->right != NULL) {
    SaveVal(root->right, depth, pos, rslt);
}

return;
}

/**

Return an array of arrays of size *returnSize.

The sizes of the arrays are returned as *returnColumnSizes array.

Note: Both returned array and columnSizes array must be malloced, assume caller calls free().
/
int levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
int count, i;
int **rslt;
int *depth;

if(root==NULL){
* returnSize = 0;
return rslt;
}
//计算一下二叉树有几层
count = CountTreeDepth(root);
*returnSize = count;

//申请二维指针的空间
rslt = (int**)malloc(countsizeof(int));
returnColumnSizes = (int)malloc(countsizeof(int));
depth = (int)malloc(count*sizeof(int));

//初始化
for (i=0; i<count; i++) {
(*returnColumnSizes)[i] = 0;
depth[i] = 0;
}

//计算每层有几个结点
CountTreeNode(root, 0, (*returnColumnSizes));

//申请返回值的结点个数
for (i=0; i<count; i++) {
rslt[i] = (int*)malloc((*returnColumnSizes)[i]*sizeof(int));
}

//保存每层的值
SaveVal(root, 0, depth, rslt);

free(depth);

return rslt;
}
