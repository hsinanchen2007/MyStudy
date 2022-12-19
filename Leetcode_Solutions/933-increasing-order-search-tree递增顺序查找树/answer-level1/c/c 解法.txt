# 解题思路：

1. 用递归把数字拿出来
2. 再放把数字按顺序返回一个新的树中

![捕获3.PNG](https://pic.leetcode-cn.com/eb60913448c8a9595d7c71091396445acd5e0c19d820e26ea6336e3a523774db-%E6%8D%95%E8%8E%B73.PNG)
# 代码：
```

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void getting_the_numbers_out(struct TreeNode* root,  int** numbers, int* count);
struct TreeNode* increasingBST(struct TreeNode* root){
    
    int *numbers = malloc(sizeof(int)*100), 
        count = 0, 
        index = 0; 
    getting_the_numbers_out(root, &numbers, &count); 
    struct TreeNode *newhead = malloc(sizeof(*newhead)),
                    *next = newhead,
                    *current;
    
    newhead->val = numbers[index++];
    newhead->left = NULL;

    while(index < count){
        current = malloc(sizeof(*current));
        next->right = current;
        next = current;
        current->val = numbers[index++];
        current->left = NULL;
    }
    next->right = NULL;
    return newhead;
}


void getting_the_numbers_out(struct TreeNode* root,  int** numbers, int* count){
    
    if(root == NULL){
        return NULL;
    }
    getting_the_numbers_out(root->left,  numbers, count);
    *(*numbers + (*count)++) = root->val;
    getting_the_numbers_out(root->right, numbers, count);
}
 
 
 
 
```







