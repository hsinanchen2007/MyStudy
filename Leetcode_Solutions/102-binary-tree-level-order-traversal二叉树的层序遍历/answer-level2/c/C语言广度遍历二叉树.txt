题目的算法不难，难的是如何用C语言实现
1、使用节点数组queue模拟队列，取定长
2、除了维护head和tail,还需要维护level，界定树的层。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXL 1024
struct TreeNode *queue[MAXL];
int head;
int tail;
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (root == NULL) {
        return NULL;
    }
    int **out = (int **)malloc(MAXL * sizeof(int *));    
    head = 0; // 队列头
    tail = 0; // 队列尾部
    int level = 0; // 每一层的终止点
    int cur = 0; // 输出队列当前元素指针
    queue[tail++] = root;
    level = tail;
    int size = 0;
    int *colSize = (int *)malloc(MAXL * sizeof(int));
    memset(colSize, 0, MAXL * sizeof(int));
    while (head != tail) { // 队列不空就一直遍历       
        out[size] = (int*)malloc(MAXL * sizeof(int));
        memset(out[size], 0, MAXL * sizeof(int));
        cur = 0;
        level = tail;                
        while (head != level) { // 遍历每一层
            out[size][cur++] = queue[head]->val;           
            if (queue[head]->left != NULL) {
                queue[tail++] = queue[head]->left;
                tail = tail % MAXL;
            }            
            if (queue[head]->right != NULL) {
                queue[tail++] = queue[head]->right;
                tail = tail % MAXL;
            }
            head = (head + 1) % MAXL;
        }                     
        colSize[size++] = cur; 
    }   
    *returnSize = size;
    *returnColumnSizes = colSize;
    return out;    
}