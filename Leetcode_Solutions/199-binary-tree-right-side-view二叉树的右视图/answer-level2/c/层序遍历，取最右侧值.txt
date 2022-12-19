### 解题思路
层序遍历取数组最右边值

### 代码

```c

void DFS(struct TreeNode* root,int *path,int deep, int* row)
{
	if (root != NULL) {
		path[deep] = root->val;
		if (*row < deep + 1) {
			*row = deep + 1;
		}
		DFS(root->left,path,deep +1,row);
		DFS(root->right, path, deep + 1, row);
	}
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
	int *path = (int *)malloc(1000);
    memset(path, 0, 1000);
	int row = 0;
	DFS(root, path, 0 ,&row);
	*returnSize = row;
	return path;
}
```