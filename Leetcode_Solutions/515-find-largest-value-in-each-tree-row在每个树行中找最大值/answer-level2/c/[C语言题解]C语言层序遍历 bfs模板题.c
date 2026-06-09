### 解题思路
1. 先遍历求树的高度，对应开辟内存记录层数更新对应层数的值

1. C语言层序遍历，bfs 上手的很好的一个题目，个人认为是模板级题目
![image.png](https://pic.leetcode-cn.com/105ce0ffeb02206193db842770a1e83cbb9cd9c2521d779c15c7cacaedf837aa-image.png)

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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */ 
#define max(a,b)  (a)>(b)?(a):(b)

// 思路一： 树的高度未知，可以先求解树的高度，按照高度开数组对应存储每层max
int TreeHeight(struct TreeNode* node){
    if(node==NULL) return 0;
    int lh = TreeHeight(node->left);
    // printf("%d--",node->val);
    int rh = TreeHeight(node->right);
    return (lh>rh ? lh:rh) + 1;
}

void bfs(struct TreeNode* node, int *res, int resLevel){
    if(node==NULL) return;

    res[resLevel] = max(res[resLevel], node->val);
    
    bfs(node->left, res, resLevel+1);
    bfs(node->right, res, resLevel+1);
}

int* largestValues(struct TreeNode* root, int* returnSize){

    int h = TreeHeight(root); // 求树的高度
    *returnSize = h;
    // printf("\n%d",INT_MIN);
    int resLevel = 0;
    int *res = (int*)malloc(sizeof(int) * h); // 开个数组，对应记录每一层的最大值
    // (void)memset(res, 0, sizeof(int)*h);  // 初始化0不行，val可能为负数
    for(int i=0;i<h;i++) {
        res[i] = INT_MIN;
    }
   
    bfs(root, res, resLevel);

	return res;
}
```