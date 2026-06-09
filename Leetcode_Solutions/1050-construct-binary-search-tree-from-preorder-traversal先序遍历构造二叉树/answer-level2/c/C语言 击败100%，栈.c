### 解题思路
解这道题目需要先了解先序遍历产生数组的特点
先序遍历数组从任何一个父节点数，后面紧跟着的是left子树，然后是right子树
问题的关键在于如何找到两棵子树的分界点，而且子树又会有子树，是个递归嵌套关系。
所以需要解决下面的问题：
1. 如何保存父节点，从而可以嵌套的进行计算？
自然会想到栈，使用栈结构把当前还没处理完的节点保存起来。
2. 处理完左节点，如何知道当前数据是属于当前父节点，还是更高层次的节点？
这个就需要栈中的值去比较了，右节点是一定大于当前父节点，但是又一定小于当前父节点的父节点（简称爷节点），所以关键是要找到爷节点。这样就需要栈中只保存爷节点，如果top爷节点小于当前数据，那么它一定不是当前数据的爷节点，这也是将top节点弹出并更新当前父节点指针，然后继续查找，直到找到大于当前数据的爷节点，那么此时就可以在当前父节点指针增加右节点了，增加之后需要把当前父节点指针更新为新增加的节点。

![image.png](https://pic.leetcode-cn.com/04328e3d4ea38acf2bcd06f256b553f7d5a95b3d0dc7dd2f2e005a5f6f64a613-image.png)

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
#define MY_OK 0
#define MY_FAIL (-1)

#define MY_BASE_SIZE 1024

typedef struct TreeNode MyItem;

struct MyStack {
	MyItem **buf;
	int size;
	int cnt;
};

int stackInit(struct MyStack *s)
{
	s->size = MY_BASE_SIZE;
	s->cnt = 0;
	s->buf = (MyItem **)calloc(s->size, sizeof(MyItem *));
	if (s->buf == NULL) {
		return MY_FAIL;
	}
	return MY_OK;
}

bool stackIsEmpty(struct MyStack *s)
{
	if (s->cnt == 0) {
		return true;
	}
	return false;
}

int stackPush(struct MyStack *s, MyItem *item)
{
	MyItem **buf = NULL;
	if (s->cnt == s->size) {
		buf = (MyItem**)calloc(s->size + MY_BASE_SIZE, sizeof(MyItem*));
		if (buf == NULL) {
			return MY_FAIL;
		}
		memcpy(buf, s->buf, s->cnt * sizeof(MyItem*));
		free(s->buf);
		s->buf = buf;
		s->size += MY_BASE_SIZE;
	}
	s->buf[s->cnt] = item;
	s->cnt++;
	return MY_OK;
}

MyItem * stackPop(struct MyStack *s)
{
	if (stackIsEmpty(s) == true) {
		return NULL;
	}
	s->cnt--;
	return s->buf[s->cnt];
}

MyItem * stackPeekTop(struct MyStack *s)
{
	if (stackIsEmpty(s) == true) {
		return NULL;
	}
	return s->buf[s->cnt - 1];
}
void stackFree(struct MyStack *s)
{
	if (s->buf != NULL) {
		free(s->buf);
		s->buf = NULL;
	}
	s->size = 0;
	s->cnt = 0;
	return;
}

struct TreeNode* tCreateNode(int val)
{
	struct TreeNode *node = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
	if (node == NULL) {
		return NULL;
	}
	node->val = val;
	node->left = node->right = NULL;
	return node;
}

int procNULL(struct MyStack *s, struct TreeNode **cur, int val)
{
	int ret;
	*cur = tCreateNode(val);
	if (*cur == NULL) {
		stackFree(s);
		return MY_FAIL;
	}
	return MY_OK;
}

int procNotNULL(struct MyStack *s, struct TreeNode **cur, int val)
{
	int ret;
	struct TreeNode *newNode = NULL;
	newNode = tCreateNode(val);
	if (newNode == NULL) {
		stackFree(s);
		return MY_FAIL;
	}
	if ((*cur)->val > val) {
		(*cur)->left = newNode;
		ret = stackPush(s, *cur);
		if (ret != MY_OK) {
			stackFree(s);
			return MY_FAIL;
		}
	} else {
		(*cur)->right = newNode;
	}
	*cur = newNode;
	return MY_OK;
}
void trace(struct TreeNode *cur, int val)
{
	if (cur == NULL) {
		printf("cur == NULL val = %d\n", val);
		return;
	}
	printf("cur->val = %d\n", cur->val);
	return;
}
void traceStack(struct MyStack *s)
{
	int i;
	struct TreeNode *node = NULL;
	printf("stack : ");
	for (i = 0; i < s->cnt; i++) {
		node = s->buf[i];
		printf("%d, ", node->val);
	}
	printf("\n");
	return;
}
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
	int i, ret;
	struct MyStack s;
	struct TreeNode *top = NULL;
	struct TreeNode *cur = NULL;
	struct TreeNode *root = NULL;
	if (preorderSize < 1) {
		return NULL;
	}
	ret = stackInit(&s);
	if (ret != MY_OK) {
		return NULL;
	}
	ret = procNULL(&s, &root, preorder[0]);
	if (ret != MY_OK) {
		stackFree(&s);
		return NULL;
	}
	cur = root;
	for (i = 1; i < preorderSize; i++) {
		while ((top = stackPeekTop(&s)) != NULL) {
			if (top->val > preorder[i]) {
				break;
			}	
			cur = stackPop(&s);
		}
		//trace(cur, preorder[i]);
		ret = procNotNULL(&s, &cur, preorder[i]);		
		if (ret != MY_OK) {
			stackFree(&s);
			return NULL;
		}
		//traceStack(&s);		
	}
	stackFree(&s);
	return root;
}
```