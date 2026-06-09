### 解题思路
此处撰写解题思路

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
/*
1.flag = 0 空节点
2.flag = 1 没安装，没覆盖
3.flag = 2 没安装，已覆盖
4.flag = 3 安装，已覆盖，并能覆盖父节点
*/
void travel(struct TreeNode* root, int* flag, int* cnt)
{
    int left_flag = 0;
    int right_flag = 0;
    if (root == NULL) {
        *flag = 0;
        return;
    }

    travel(root->left, &left_flag, cnt);
    travel(root->right, &right_flag, cnt);

    if (left_flag == 0) {
        if (right_flag == 0 || right_flag == 2) {
            *flag = 1;
        } else if (right_flag == 1) {
            *flag = 3;
            (*cnt)++;
        } else {
            *flag = 2;
        }
    } else if (left_flag == 1) {
        *flag = 3;
        (*cnt)++;
    } else if (left_flag == 2) {
        if (right_flag == 0 || right_flag == 2) {
            *flag = 1;
        } else if (right_flag == 1) {
            *flag = 3;
            (*cnt)++;
        } else {
            *flag = 2;
        }
    } else {
        if (right_flag == 1) {
            *flag = 3;
            (*cnt)++;
        } else {
            *flag = 2;
        }
    }
}

int minCameraCover(struct TreeNode* root)
{
    int flag = 0;
    int cnt = 0;
    travel(root, &flag, &cnt);
    if (flag == 1) {
        cnt++;
    }
    return cnt;
}
```