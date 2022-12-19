### 解题思路
求出3条路的个数
然后分别相减，大于等于2 则为true

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void dfs(struct TreeNode *root, int *left_num, int *right_num, int left_mark,
	 int right_mark, int index, int *dad)
{
	if (!root)
		return;
	if (left_mark)
		(*left_num)++;
	else if (right_mark)
		(*right_num)++;
	else if (!right_mark && !left_mark)
		(*dad)++;
	else
		printf("error\n");
	if (root->val == index) {
		dfs(root->left, left_num, right_num, 1, right_mark, index, dad);
		dfs(root->right, left_num, right_num, left_mark, 1, index, dad);
	} else {
		dfs(root->left, left_num, right_num, left_mark, right_mark,
		    index, dad);
		dfs(root->right, left_num, right_num, left_mark, right_mark,
		    index, dad);
	}
}

/* 所有的节点有3条路走，father, left, right */
bool btreeGameWinningMove(struct TreeNode *root, int n, int x)
{
	int loop;
	int left_num = 0;
	int right_num = 0;
	int dad = 0;
	if (!root || n == 0 || n == 1)
		return false;

	dfs(root, &left_num, &right_num, 0, 0, x, &dad);
	dad--;
	printf("left %d right %d dad %d\n", left_num, right_num, dad);
	if (left_num - (dad + right_num) >= 2)
		return true;
	if (dad - (left_num + right_num) >= 2)
                return true;
        if (right_num - (dad + left_num) >= 2)
                return true;

	return false;
}
```