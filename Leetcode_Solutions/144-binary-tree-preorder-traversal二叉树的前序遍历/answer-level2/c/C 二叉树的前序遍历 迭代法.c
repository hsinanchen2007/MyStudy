不算很快：
递归法求了树的大小，迭代法访问数值
![image.png](https://pic.leetcode-cn.com/1a09a819547a8fe8a64d730ea930bff6311c93c138c6b3a4f677729beaa4d756-image.png)

![image.png](https://pic.leetcode-cn.com/f663838d9d421b74e6d2b402710400cc4504821cfbff5aa55e608a77bb41e374-image.png)

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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int treeSize(struct TreeNode* root){
     if(!root) return 0;     
     return treeSize(root->left) + treeSize(root->right) + 1;
 }

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = treeSize(root);
    if(!root || size == 0){
        *returnSize = 0;
        return NULL;
    } 
    struct TreeNode **stack = (struct TreeNode **)malloc(size * sizeof(struct TreeNode*));//需要一个栈来存放右节点
    int *res = (int *)malloc(sizeof(int) * size);

    int i = 0;
    int top = -1;
    while (true) {
        while (root) {
		    res[i++] = root->val; 
		    stack[++top] = root->right;//入栈
		    root = root->left;
	    }
		if (top == -1) break; 
		root = stack[top--]; //出栈
	}
    *returnSize = size;
    free(stack);
    return res;
}



```