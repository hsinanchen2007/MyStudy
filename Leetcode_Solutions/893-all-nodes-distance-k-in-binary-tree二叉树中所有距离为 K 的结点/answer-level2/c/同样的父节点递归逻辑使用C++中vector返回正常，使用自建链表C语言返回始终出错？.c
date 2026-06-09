思路：假设找寻距离目标节点为K，那么对应他的父节点就需要找寻K-1，父节点的父节点就是K-1-1，依次往上层推直到root节点，标记已经遍历的点为1，防止重复遍历。

```
struct RetNode {
	int val;
	struct RetNode *next;
};

int rec[501] = { 0 };

void appendRet(struct RetNode *pHead, int val)
{
	struct RetNode *r = pHead;
	struct RetNode *pNew = (struct RetNode *)malloc(sizeof(struct RetNode));
	pNew->val = val;
	pNew->next = NULL;

	while (r->next != NULL) {
		r = r->next;
	}
	r->next = pNew;
}

void freeRet(struct RetNode *pHead) //释放链表
{
	struct RetNode * p;
	while (pHead != NULL) {
		p = pHead;
		pHead = pHead->next;
		free(p);
		p = NULL;
	}
}

struct TreeNode * findRet(struct TreeNode *pHead, int val)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	struct TreeNode * p = pHead;
	if (p->val == val) {
		return p;
	}
	else {
		struct TreeNode * a = findRet(p->left, val);
		if (a != NULL) {
			return a;
		}
		struct TreeNode * b = findRet(p->right, val);
		if (b != NULL) {
			return b;
		}
	}
	return NULL;
}

struct TreeNode* findParent(struct TreeNode* pHead, int val)
{
	if (pHead == NULL) {
		return NULL;
	}
	struct TreeNode * p = pHead;
	if (p->left != NULL) {
		if (p->left->val == val) {
			return p;
		} else {
			struct TreeNode* a = findParent(p->left, val);
			if (a != NULL) {
				return a;
			}
		}
	}
	if (p->right != NULL) {
		if (p->right->val == val) {
			return p;
		} else {
			struct TreeNode* a = findParent(p->right, val);
			if (a != NULL) {
				return a;
			}
		}
	}

	return NULL;
}

void checkLeaf(struct TreeNode* root, int K, struct RetNode* ret) {
	if (K == 0 && rec[root->val] != 1) {
		appendRet(ret, root->val);
		printf("leaf ret = %d\n", root->val);
		return;
	} else {
		if (root == NULL) {
			return;
		}
	}

	if (root->left != NULL) {
		if (rec[root->left->val] != 1) {
			checkLeaf(root->left, K - 1, ret);
		}
	}
	if (root->right != NULL) {
		if (rec[root->right->val] != 1) {
			checkLeaf(root->right, K - 1, ret);
		}
	}
}

void checkRoot(struct TreeNode* root, struct TreeNode* current, struct TreeNode* target, int K, struct RetNode* ret) {
	if (current == NULL) {
		return;
	}
	if (K == 0) {
		appendRet(ret, target->val);
		return;
	}
	if (current == target) {
		rec[target->val] = 1;
		checkLeaf(current, K, ret);
		int cnt = K;
		struct TreeNode* tmp = findParent(root, target->val);
		while (tmp != NULL && cnt >= 0) {
			if (rec[tmp->val] != 1) {
				// printf("root---%d\n", tmp->val);
				checkLeaf(tmp, --cnt, ret);
				rec[tmp->val] = 1;
			}
			tmp = findParent(root, tmp->val);
		}
	} else {
		checkRoot(root, current->left, target, K, ret);
		checkRoot(root, current->right, target, K, ret);
	}
}

int* distanceK(struct TreeNode* root, struct TreeNode* target, int K, int* returnSize) {
	struct RetNode* ret = (struct RetNode*)malloc(sizeof(struct RetNode));
	ret->val = -1;
	ret->next = NULL;
	checkRoot(root, root, target, K, ret);
	struct RetNode* tmp = ret->next;
	int cnt = 0;
	while (tmp != NULL) {
		cnt++;
		tmp = tmp->next;
	}
	int* a = (int *)malloc(sizeof(int) * cnt);
	struct RetNode* tmp1 = ret->next;
	int i = 0;
	*returnSize = cnt;
	while (tmp1 != NULL) {
		a[i++] = tmp1->val;
		tmp1 = tmp1->next;
	}
	freeRet(ret);
	return a;
}
```
上述代码将返回值ret使用vector替代可以通过，但是使用自建链表返回就会报错。
后来使用如下代码测试也报了同样的错误，不知为何？
```
int* distanceK(struct TreeNode* root, struct TreeNode* target, int K, int* returnSize) {
    *returnSize = 3;
	int* a = (int *)malloc(sizeof(int) * 3);
	return a;
}
```

附录使用vector返回的C++版本（逻辑与C的完全相同，已经通过）：
```
int rec[501] = { 0 };

struct TreeNode * findRet(struct TreeNode *pHead, int val)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	struct TreeNode * p = pHead;
	if (p->val == val) {
		return p;
	}
	else {
		struct TreeNode * a = findRet(p->left, val);
		if (a != NULL) {
			return a;
		}
		struct TreeNode * b = findRet(p->right, val);
		if (b != NULL) {
			return b;
		}
	}
	return NULL;
}

struct TreeNode* findParent(struct TreeNode* pHead, int val)
{
	if (pHead == NULL) {
		return NULL;
	}
	struct TreeNode * p = pHead;
	if (p->left != NULL) {
		if (p->left->val == val) {
			return p;
		} else {
			struct TreeNode* a = findParent(p->left, val);
			if (a != NULL) {
				return a;
			}
		}
	}
	if (p->right != NULL) {
		if (p->right->val == val) {
			return p;
		} else {
			struct TreeNode* a = findParent(p->right, val);
			if (a != NULL) {
				return a;
			}
		}
	}

	return NULL;
}

void checkLeaf(struct TreeNode* root, int K, vector<int>& ret) {
	if (K == 0 && rec[root->val] != 1) {
		//appendRet(ret, root->val);
		ret.push_back(root->val);
		printf("leaf ret = %d\n", root->val);
		return;
	} else {
		if (root == NULL) {
			return;
		}
	}

	if (root->left != NULL) {
		if (rec[root->left->val] != 1) {
			checkLeaf(root->left, K - 1, ret);
		}
	}
	if (root->right != NULL) {
		if (rec[root->right->val] != 1) {
			checkLeaf(root->right, K - 1, ret);
		}
	}
}

void checkRoot(struct TreeNode* root, struct TreeNode* current, struct TreeNode* target, int K, vector<int>& ret) {
	if (current == NULL) {
		return;
	}
	if (K == 0) {
		//appendRet(ret, target->val);
		ret.push_back(target->val);
		return;
	}
	if (current == target) {
		rec[target->val] = 1;
		checkLeaf(current, K, ret);
		int cnt = K;
		struct TreeNode* tmp = findParent(root, target->val);
		while (tmp != NULL && cnt >= 0) {
			if (rec[tmp->val] != 1) {
				// printf("root---%d\n", tmp->val);
				checkLeaf(tmp, --cnt, ret);
				rec[tmp->val] = 1;
			}
			tmp = findParent(root, tmp->val);
		}
	} else {
		checkRoot(root, current->left, target, K, ret);
		checkRoot(root, current->right, target, K, ret);
	}
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
	vector<int> ret;
	checkRoot(root, root, target, K, ret);
	return ret;
}

```
