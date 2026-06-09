### 解题思路

总体思路和112题类似，用DFS找到和等于sum的路径。区别是找到目标后存储结果，以及在找的过程中，记录搜索路上的信息。
搜索过程中：把路上遇到的所有节点都保存起来传递进去，用于找到终点后保存所有信息；过程中记录路径的长度值，作为列号。
找到一个合适的叶子节点后：全局变量行数+1，给本次搜素的结果分配内存，并把路上遇到的所有值存起来。

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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int g_col = 0;

bool dfs(struct TreeNode* root, int sum, int total, int **result, int** returnColumnSizes, int* temp, int nums)
{
    if (root == NULL) {
        return false;
    }

    if ((root->left == NULL) && (root->right == NULL)) {
        total += root->val;
        if (sum == total) {
            // 找到了一条合适的路径，填写相关的数据
            temp[nums++] = root->val;
            result[g_col] = malloc(sizeof(int) * nums); // 给这行分配内存
            for (int i = 0; i < nums; i++) {  // 把到达该终点遇到的所有节点存在结果中
                result[g_col][i] = temp[i];
            }
            returnColumnSizes[0][g_col++] = nums;
            return true;
        }
    }

    temp[nums] = root->val;
    total += root->val;
    nums++;

    bool a = dfs(root->left, sum, total, result, returnColumnSizes, temp, nums);
    bool b = dfs(root->right, sum, total, result, returnColumnSizes, temp, nums);
    return (a || b);
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    // 总体思路和112题类似，用DFS找到和等于sum的路径
    // 搜索过程中把路上遇到的所有值都传递进去，找到终点后保存所有信息；过程中记录路径的长度值，作为列号
    // 找到一个合适的叶子节点后，把所有相关的值存储并返回：全局变量行数+1，并把路上遇到的所有值存起来
    g_col = 0;
    *returnSize = 0;
    int **result = (int*)malloc(sizeof(int*) * 1024);  // 开辟一个大数组。如果不允许这种做法，就多做一遍遍历，找到一共有多少路径
    *returnColumnSizes = malloc(sizeof(int) * 1024);
    int total = 0;
    int nums = 0;
    int temp[1024] = {0};

    if (dfs(root, sum, total, result, returnColumnSizes, temp, nums)) {  // 能找到和等于给定值
        *returnSize = g_col;
        return result;
    }

    return NULL;
}
```