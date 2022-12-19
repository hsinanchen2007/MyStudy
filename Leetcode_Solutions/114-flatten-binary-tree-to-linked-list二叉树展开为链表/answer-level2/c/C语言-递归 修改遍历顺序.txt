### 解题思路
思路是如高赞答案中采用右左中的遍历顺序进行递归的，写下这些只是为展示C语言写法
*注意：*由于力扣测试用例是连续输入的，故全局变量pre指针需每次置空

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

struct TreeNode *pre = NULL;
void flatten2(struct TreeNode* root);

void flatten(struct TreeNode* root){   
    if(root == NULL) return;
    
    pre = NULL;
    flatten2(root);
}

void flatten2(struct TreeNode* root){
    if(root == NULL) return;

    //右左中遍历 防止断链
    flatten2(root -> right);
    flatten2(root -> left);
    root -> right = pre;
    root -> left = NULL;
    pre = root;
}

```