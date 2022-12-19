### 类似归并排序，左右子树各自递归，新建一颗二叉树，返回头结点，思路简单，哪个大佬能告诉我 内存得分为什么这么差
![image.png](https://pic.leetcode-cn.com/88704206f1768171f94a44d732f4a5b14b7250a576608aecc7d8856ee378b986-image.png)

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


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
	
	if(t1==NULL&&t2==NULL) return NULL;

	// struct TreeNode*  node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode* node;
	if(t1!=NULL && t2!=NULL) {
		node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		node->val = t1->val + t2->val;		

		node->left = mergeTrees(t1->left, t2->left);
		node->right = mergeTrees(t1->right, t2->right);
	}

    struct TreeNode* head = node;

	if(t1==NULL) return t2;
	if(t2==NULL) return t1;

    return head;
}
```