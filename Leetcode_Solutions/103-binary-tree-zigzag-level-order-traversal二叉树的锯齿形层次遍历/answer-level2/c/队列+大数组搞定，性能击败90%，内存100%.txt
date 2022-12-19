# 
使用队列先进先出的方式，层次遍历，最后输出的时候做锯齿处理。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct dataNode {
    int val;
    int degree;
    struct TreeNode *pointer;
};

 int head = 0;
 int tail  = 0;
 struct dataNode data[10000] = {0};

void ReadDataToQueue(struct TreeNode* root, int *cnt);
void InQueFunc(struct dataNode *p);
void DequeFunc(struct dataNode * q);
int  lenQue();
int levelQueCnt(int degree);

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    
    int nodeCnt = 0;
    int level   = 0;

    head = 0;
    tail = 0;
    memset(data, 0, sizeof(struct dataNode) * 10000);

    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    

    ReadDataToQueue(root, &nodeCnt);

    head = nodeCnt-1;
    tail = 0;

    *returnSize = data[head].degree + 1;

    int **retArray = (int **)malloc(sizeof(int *) * (*returnSize));
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * (*returnSize));
    struct dataNode outTmpData = {0};
    int levelCnt = 0;

    while(tail <= head) {
        if (retArray[level] != NULL) {
            levelCnt = levelQueCnt(level);
            returnColumnSizes[0][level] = levelCnt;
            retArray[level] = (int *)malloc(sizeof(int) * levelCnt);
        }
        if (level % 2 == 1) {
            for (int i = 0; i < levelCnt; i++) {
                DequeFunc(&outTmpData);
                retArray[level][levelCnt - i -1] = outTmpData.val;
            }
        } else {
            for (int i = 0; i < levelCnt; i++) {
                DequeFunc(&outTmpData);
                retArray[level][i] = outTmpData.val;
            }
        }
        
        level++;
    }

    return retArray;

}

void InQueFunc(struct dataNode *p)
{
    memcpy(data+head, p, sizeof(struct dataNode));
    head++;
    head = head % 10000;
    return;
}

void DequeFunc(struct dataNode * q)
{
    memcpy(q, data+tail, sizeof(struct dataNode));
    tail++;
    tail = tail %10000;
    return;
}

int  lenQue()
{
    return((10000+head-tail)%10000);
}

int levelQueCnt(int degree)
{
    int cnt = 0;
    for (int i = 0; i <= head; i++) {
        if (data[i].degree != degree) continue;
        if (data[i].degree == degree) {
            cnt++;
            continue;
        }
        if (data[i].degree > degree) break;
    }

    return cnt;
}


void ReadDataToQueue(struct TreeNode* root, int *cnt)
{
    struct TreeNode *tmp = root;
    struct dataNode inTmpData = {0};
    struct dataNode outTmpData = {0};
    int nodeCnt = 0;

    inTmpData.val = root->val;
    inTmpData.degree = 0;
    inTmpData.pointer = root;
    InQueFunc(&inTmpData);
    nodeCnt++;

    while(lenQue()) {
        DequeFunc(&outTmpData);
            
        if (outTmpData.pointer->left != NULL) {
            inTmpData.val = (outTmpData.pointer->left)->val;
            inTmpData.pointer = outTmpData.pointer->left;
            inTmpData.degree = outTmpData.degree + 1;
            InQueFunc(&inTmpData);
            nodeCnt++;
        }
        if (outTmpData.pointer->right != NULL) {
            inTmpData.val = outTmpData.pointer->right->val;
            inTmpData.pointer = outTmpData.pointer->right;
            inTmpData.degree = outTmpData.degree + 1;
            InQueFunc(&inTmpData);
            nodeCnt++;
        }
        
    }

    *cnt = nodeCnt;

    return;
}
```
![image.png](https://pic.leetcode-cn.com/fe04f9a08975499ce40204b3626196c49f59a3a0dd8099ce75bed76f7a654eae-image.png)
